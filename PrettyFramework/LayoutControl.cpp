#include "stdafx.h"
#include "Rectangle.h"
#include "LayoutControl.h"

namespace PrettyFramework {

	LayoutControl::LayoutControl(BaseControl* control)
		: BaseControl(control)
	{
		m_bkgnd_shape.reset(new Rectangle());
		m_bkgnd_shape->SetBorderNull(TRUE);
		m_bkgnd_shape->SetFillNull(TRUE);
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
				m_children.erase(iter);

				if (last_pressed.lock() == child) {
					last_pressed.reset();
				}

				if (last_hovered.lock() == child) {
					last_hovered.reset();
				}

				if (last_focused.lock() == child) {
					last_focused.reset();
				}

				break;
			}
		}

		RecalcLayout();
	}
	
	void LayoutControl::Paint0(Gdiplus::Graphics& graph)
	{
		// 绘制布局控件的背景
		m_bkgnd_shape->Paint(graph);

		if (m_children.size() == 0) {
			return; /* 内容为空 */
		}

		Gdiplus::Region rgnOldClip;
		graph.GetClip(&rgnOldClip);

		Rect rcClip = GetViewRect();
		rcClip.DeflateRect(m_margin);

		auto& F = toGdiplusRect(rcClip);
		Gdiplus::Region rgnClip(F);
		
		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			auto& control = (*iter);

			Rect rect = control->GetViewRect();
			auto& F2 = toGdiplusRect(rect);

			Gdiplus::Region rgnControl(F2);

			rgnControl.Intersect(&rgnClip);
			graph.SetClip(&rgnControl);

			control->Paint(graph);
		}

		graph.SetClip(&rgnOldClip);
	}

	void LayoutControl::OnMouseUp(Point point)
	{
		Point ptInThis = GetPointInThis(point);

		if (!last_pressed.expired()) {
			last_pressed.lock()->OnMouseUp(ptInThis);
		}

		last_pressed.reset();

		if (m_children.size() == 0) {
			Redraw();
		}
	}

	void LayoutControl::OnMouseMove(Point point)
	{
		Point ptInThis = GetPointInThis(point);

		weak_ptr<BaseControl> hovered;
		auto& ptr = last_hovered.lock();

		if (!last_hovered.expired()) {
			ptr->OnMouseMove(ptInThis);
			if (ptr->HitTest(ptInThis)) {
				hovered = last_hovered;
			}
		}
		
		if (hovered.expired()) {

			for (auto iter = m_children.begin()
				; iter != m_children.end()
				; iter++) {

				auto& control = (*iter);
				if (ptr != control) {
					if (control->HitTest(ptInThis)) {
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

	void LayoutControl::OnMouseDown(Point point)
	{
		Point ptInThis = GetPointInThis(point);

		weak_ptr<BaseControl> pressed;
		auto& ptr = last_focused.lock();

		if (!last_focused.expired()) {
			ptr->OnMouseDown(ptInThis);
			if (ptr->HitTest(ptInThis)) {
				pressed = last_focused;
			}
		}
		
		if (pressed.expired()) {

			for (auto iter = m_children.begin()
				; iter != m_children.end()
				; iter++) {

				auto& control = (*iter);
				if (ptr != control) {
					if (control->HitTest(ptInThis)) {
						control->OnMouseDown(ptInThis);
						pressed = control;
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
			m_bkgnd_shape->SetBeginPoint(rect_in_parent.GetLeftTop());
			m_bkgnd_shape->SetEndPoint(rect_in_parent.GetRightBottom());
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
		TRACE(_T("LayoutControl:%s Rect:%d,%d,%d,%d \n"), GetId(), GetRect().GetLeft()
			, GetRect().GetTop(), GetRect().GetRight(), GetRect().GetBottom());

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {
			(*iter)->Dump();
		}
	}

}