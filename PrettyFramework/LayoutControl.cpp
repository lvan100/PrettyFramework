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
		CPoint ptInThis(point);
		ptInThis.Offset(rect_in_parent.left, rect_in_parent.top);

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {
			auto& control = (*iter);
			if (control->GetRect().PtInRect(ptInThis)) {
				control->OnButtonUp(ptInThis);
				last_pressed = nullptr;
				break;
			}
		}
	}

	void LayoutControl::OnMouseMove(CPoint point)
	{
		CPoint ptInThis(point);
		ptInThis.Offset(rect_in_parent.left, rect_in_parent.top);

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {
			auto& control = (*iter);
			if (control->GetRect().PtInRect(ptInThis)) {
				control->OnMouseMove(ptInThis);
				last_hovered = control;
				break;
			}
		}
	}

	void LayoutControl::OnButtonDown(CPoint point)
	{
		CPoint ptInThis(point);
		ptInThis.Offset(rect_in_parent.left, rect_in_parent.top);

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {
			auto& control = (*iter);
			if (control->GetRect().PtInRect(ptInThis)) {
				control->OnButtonDown(ptInThis);
				last_pressed = control;
				last_focused = control;
				break;
			}
		}
	}

}