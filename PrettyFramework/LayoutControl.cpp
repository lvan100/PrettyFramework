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
			ASSERT(FALSE); /* 当然不能添加自己 */
			return;
		}
		
		m_children.push_back(child);

		RecalcLayout();
	}

	void LayoutControl::RemoveChild(shared_ptr<BaseControl> child)
	{
		if (child == nullptr || child.get() == this) {
			ASSERT(FALSE); /* 当然不能删除自己 */
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
			return; /* 内容为空 */
		}

		CRgn rgnClip;

		CRect rcOldClip;
		dc.GetClipBox(rcOldClip);

		CRect rcClip = GetViewRect();
		rcClip.DeflateRect(m_margin);

		rgnClip.CreateRectRgnIndirect(rcClip);
		
// 		// TODO 这时候向布局控件增加边框和背景应该也没有问题了
// 		dc.FrameRect(GetViewRect(), &CBrush(RGB(0,0,0)));

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			CRgn rgnControl;
			auto& control = (*iter);

			CRect rect = control->GetViewRect();
			rgnControl.CreateRectRgnIndirect(rect);

			// 防止子控件的绘图区域超出父控件的显示范围.
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
		ptInThis.Offset(-GetRect().left, -GetRect().top);

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
		ptInThis.Offset(-GetRect().left, -GetRect().top);

		TRACE(_T("LayoutControl:%s Rect:%d,%d,%d,%d \n"), GetId()
			, GetRect().left, GetRect().top, GetRect().right
			, GetRect().bottom);

		TRACE(_T("LayoutControl:%s Mouse:%d,%d \n"), GetId()
			, ptInThis.x, ptInThis.y);

		shared_ptr<BaseControl> hovered = nullptr;

		if (last_hovered != nullptr) {
			last_hovered->OnMouseMove(ptInThis);
			if (last_hovered->GetRect().PtInRect(ptInThis)) {
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
		ptInThis.Offset(-GetRect().left, -GetRect().top);

		shared_ptr<BaseControl> pressed = nullptr;

		if (last_focused != nullptr) {
			last_focused->OnMouseDown(ptInThis);
			if (last_focused->GetRect().PtInRect(ptInThis)) {
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

	void LayoutControl::Dump()
	{
		TRACE(_T("LayoutControl:%s Rect:%d,%d,%d,%d \n"), GetId()
			, GetRect().left, GetRect().top, GetRect().right
			, GetRect().bottom);

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {
			(*iter)->Dump();
		}
	}

}