#include "stdafx.h"
#include "LayoutControl.h"

namespace PrettyFramework {

	LayoutControl::LayoutControl(BaseControl* control)
		: BaseControl(control)
	{
	}

	LayoutControl::~LayoutControl()
	{
	}

	BaseControl* LayoutControl::OnFindControlById(CString id)
	{
		if (m_id == id) { return this; }
		
		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			BaseControl* control = (*iter)->FindControlById(id);
			if (control != nullptr) {
				return control;
			}
		}

		return nullptr;		
	}

	void LayoutControl::AddChild(shared_ptr<BaseControl> child)
	{
		if (child == nullptr || child.get() == this) {
			ASSERT(FALSE); /* ��Ȼ��������Լ� */
			return;
		}
		
		m_children.push_back(child);

		RecalcLayout();
	}

	void LayoutControl::RemoveChild(shared_ptr<BaseControl> child)
	{
		if (child == nullptr || child.get() == this) {
			ASSERT(FALSE); /* ��Ȼ����ɾ���Լ� */
			return;
		}

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			if (child == (*iter)) {

				if (last_pressed == child) {
					last_pressed = nullptr;
				}

				if (last_hovered == child) {
					last_hovered = nullptr;
				}

				if (last_focused == child) {
					last_focused = nullptr;
				}

				m_children.erase(iter);
				
				break;
			}
		}

		RecalcLayout();
	}
	
	void LayoutControl::Paint(CDC& dc)
	{
		if (m_children.size() == 0) {
			return; /* ����Ϊ�� */
		}

		CRgn rgnClip;

		CRect rcOldClip;
		dc.GetClipBox(rcOldClip);

		CRect rcClip = GetViewRect();
		rcClip.DeflateRect(m_margin);

		rgnClip.CreateRectRgnIndirect(rcClip);
		
		// TODO ��ʱ���򲼾ֿؼ����ӱ߿�ͱ���Ӧ��Ҳû��������
		dc.FrameRect(GetViewRect(), &CBrush(RGB(0,0,0)));

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			CRgn rgnControl;
			auto& control = (*iter);

			CRect rect = control->GetViewRect();
			rgnControl.CreateRectRgnIndirect(rect);

			// ��ֹ�ӿؼ��Ļ�ͼ���򳬳����ؼ�����ʾ��Χ.
			rgnControl.CombineRgn(&rgnClip, &rgnControl, RGN_AND);
			dc.SelectClipRgn(&rgnControl);

			control->Paint(dc);
		}

		CRgn rgnOldClip;
		rgnOldClip.CreateRectRgnIndirect(rcOldClip);

		dc.SelectClipRgn(&rgnOldClip);
	}

	void LayoutControl::OnMouseUp(CPoint point)
	{
		CPoint ptInThis(point);
		ptInThis.Offset(GetRect().left, GetRect().top);

		if (last_pressed != nullptr) {
			last_pressed->OnMouseUp(ptInThis);
		}

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			auto& control = (*iter);
			if (last_pressed != control) {
				if (control->GetRect().PtInRect(ptInThis)) {
					control->OnMouseUp(ptInThis);
					break;
				}
			}
		}

		if (m_children.size() == 0) {
			Redraw();
		}

		last_pressed = nullptr;
	}

	void LayoutControl::OnMouseMove(CPoint point)
	{
		CPoint ptInThis(point);
		ptInThis.Offset(GetRect().left, GetRect().top);

		shared_ptr<BaseControl> hovered = nullptr;

		if (last_hovered != nullptr) {
			last_hovered->OnMouseMove(ptInThis);
			if (last_hovered->GetRect().PtInRect(point)) {
				hovered = last_hovered;
			}
		}
		
		if (hovered == nullptr) {

			for (auto iter = m_children.begin()
				; iter != m_children.end()
				; iter++) {

				auto& control = (*iter);
				if (last_hovered != control) {
					if (control->GetRect().PtInRect(ptInThis)) {
						control->OnMouseMove(ptInThis);
						hovered = control;
						break;
					}
				}
			}

			last_hovered = hovered;
		}
		
		if (m_children.size() == 0) {
			Redraw();
		}
	}

	void LayoutControl::OnMouseDown(CPoint point)
	{
		CPoint ptInThis(point);
		ptInThis.Offset(GetRect().left, GetRect().top);

		shared_ptr<BaseControl> pressed = nullptr;

		if (last_focused != nullptr) {
			last_focused->OnMouseDown(ptInThis);
			if (last_focused->GetRect().PtInRect(point)) {
				pressed = last_focused;
			}
		}
		
		if (pressed == nullptr) {

			for (auto iter = m_children.begin()
				; iter != m_children.end()
				; iter++) {

				auto& control = (*iter);
				if (last_focused != control) {
					if (control->GetRect().PtInRect(ptInThis)) {
						control->OnMouseDown(ptInThis);
						pressed = control;
						break;
					}
				}
			}
			
			last_focused = last_pressed = pressed;
		}

		if (m_children.size() == 0) {
			Redraw();
		}
	}

}