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

	void LayoutControl::AddChild(shared_ptr<BaseControl> child)
	{
		if (child != nullptr && child.get() != this) {
			m_children.push_back(child);
		}

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
				m_children.erase(iter);

				if (last_pressed == child) {
					last_pressed = nullptr;
				}

				if (last_hovered == child) {
					last_hovered = nullptr;
				}

				if (last_focused == child) {
					last_focused = nullptr;
				}

				break;
			}
		}

		RecalcLayout();
	}

	void LayoutControl::Paint(CDC& dc)
	{
		CRgn rgnClient;
		CRect rcClient = GetPaintRect();
		rgnClient.CreateRectRgnIndirect(rcClient);

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			CRgn rgn;
			auto& control = (*iter);

			CRect rect = control->GetPaintRect();
			rgn.CreateRectRgnIndirect(rect);

			// 防止子控件的位置超出父控件的显示范围.
			rgn.CombineRgn(&rgnClient, &rgn, RGN_AND);
			dc.SelectClipRgn(&rgn);

			control->Paint(dc);
		}
	}

	void LayoutControl::OnButtonUp(CPoint point)
	{
		// TRACE(_T("LayoutControl : %s button up \n"), GetId());

		CPoint ptInThis(point);
		ptInThis.Offset(GetRect().left, GetRect().top);

		if (last_pressed != nullptr) {
			last_pressed->OnButtonUp(ptInThis);
		}

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			auto& control = (*iter);
			if (last_pressed != control) {
				if (control->GetRect().PtInRect(ptInThis)) {
					control->OnButtonUp(ptInThis);
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
		// TRACE(_T("LayoutControl : %s mouse move \n"), GetId());

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

	void LayoutControl::OnButtonDown(CPoint point)
	{
		// TRACE(_T("LayoutControl : %s button down \n"), GetId());

		CPoint ptInThis(point);
		ptInThis.Offset(GetRect().left, GetRect().top);

		if (last_focused != nullptr) {
			last_focused->OnButtonDown(ptInThis);
		}

		shared_ptr<BaseControl> pressed = nullptr;

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			auto& control = (*iter);
			if (last_focused != control) {
				if (control->GetRect().PtInRect(ptInThis)) {
					control->OnButtonDown(ptInThis);
					pressed = control;
					break;
				}
			}
		}

		if (m_children.size() == 0) {
			Redraw();
		}

		last_focused = last_pressed = pressed;
	}

}