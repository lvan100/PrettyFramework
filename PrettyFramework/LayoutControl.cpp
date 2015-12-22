#include "stdafx.h"
#include "Rectangle.h"
#include "LayoutControl.h"

namespace PrettyFramework {

	LayoutControl::LayoutControl(BaseControl* control)
		: BaseControl(control)
		, last_hovered(nullptr)
		, last_pressed(nullptr)
		, last_focused(nullptr)
	{
		m_bkgnd_shape.reset(new Rectangle());
// 		m_bkgnd_shape->SetBorderNull(TRUE);
// 		m_bkgnd_shape->SetFillNull(TRUE);
	}

	LayoutControl::~LayoutControl()
	{
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

				if (last_pressed == child.get()) {
					last_pressed = nullptr;
				}

				if (last_hovered == child.get()) {
					last_hovered = nullptr;
				}

				if (last_focused == child.get()) {
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
		// 绘制布局控件的背景
		m_bkgnd_shape->Paint(dc);

		if (m_children.size() == 0) {
			return; /* 内容为空 */
		}

		CRgn rgnClip;

		CRect rcOldClip;
		dc.GetClipBox(rcOldClip);

		CRect rcClip = GetViewRect();
		rcClip.DeflateRect(m_margin);

		rgnClip.CreateRectRgnIndirect(rcClip);
		
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

		last_pressed = nullptr;

		if (m_children.size() == 0) {
			Redraw();
		}
	}

	void LayoutControl::OnMouseMove(CPoint point)
	{
		CPoint ptInThis(point);
		ptInThis.Offset(-GetRect().left, -GetRect().top);

		BaseControl* hovered = nullptr;

		if (last_hovered != nullptr) {
			last_hovered->OnMouseMove(ptInThis);
			if (last_hovered->HitTest(ptInThis)) {
				hovered = last_hovered;
			}
		}
		
		if (hovered == nullptr) {

			for (auto iter = m_children.begin()
				; iter != m_children.end()
				; iter++) {

				auto& control = (*iter);
				if (last_hovered != control.get()) {
					if (control->HitTest(ptInThis)) {
						control->OnMouseMove(ptInThis);
						hovered = control.get();
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

		BaseControl* pressed = nullptr;

		if (last_focused != nullptr) {
			last_focused->OnMouseDown(ptInThis);
			if (last_focused->HitTest(ptInThis)) {
				pressed = last_focused;
			}
		}
		
		if (pressed == nullptr) {

			for (auto iter = m_children.begin()
				; iter != m_children.end()
				; iter++) {

				auto& control = (*iter);
				if (last_focused != control.get()) {
					if (control->HitTest(ptInThis)) {
						control->OnMouseDown(ptInThis);
						pressed = control.get();
						break;
					}
				}
			}
		}

		last_focused = last_pressed = pressed;

		if (m_children.size() == 0) {
			Redraw();
		}
	}

	void LayoutControl::RecalcLayout()
	{
		if (m_bkgnd_shape != nullptr) {
			m_bkgnd_shape->SetBeginPoint(rect_in_parent.TopLeft());
			m_bkgnd_shape->SetEndPoint(rect_in_parent.BottomRight());
		}
	}

	BaseControl* LayoutControl::FindControlById(CString id)
	{
		if (m_id == id) { return this; }

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			auto* control = (*iter)->FindControlById(id);
			if (control != nullptr) {
				return control;
			}
		}

		return nullptr;
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