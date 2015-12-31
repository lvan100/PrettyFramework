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
	
	void LayoutControl::Paint(Gdiplus::Graphics& graph)
	{
		// 绘制布局控件的背景
		m_bkgnd_shape->Paint(graph);

		if (m_children.size() == 0) {
			return; /* 内容为空 */
		}

		Gdiplus::Region rgnOldClip;
		graph.GetClip(&rgnOldClip);

		Gdiplus::RectF rcOldClip;
		graph.GetClipBounds(&rcOldClip);

		Gdiplus::RectF rcClip = GetViewRect();

		rcClip.X += m_margin.X;
		rcClip.Y += m_margin.Y;
		rcClip.Width -= m_margin.Width;
		rcClip.Height -= m_margin.Height;

		Gdiplus::Region rgnClip;
		rgnClip.Intersect(rcClip);
		
		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			auto& control = (*iter);

			Gdiplus::Region rgnControl;

			Gdiplus::RectF rect = control->GetViewRect();
			rgnControl.Intersect(rect);

			rgnControl.Intersect(&rgnClip);
			graph.SetClip(&rgnControl);

			control->Paint(graph);
		}

		graph.SetClip(&rgnOldClip);
	}

	void LayoutControl::OnMouseUp(Gdiplus::PointF point)
	{
		Gdiplus::PointF ptInThis(point);
		ptInThis.Y -= GetRect().GetTop();
		ptInThis.X -= GetRect().GetLeft();

		if (last_pressed != nullptr) {
			last_pressed->OnMouseUp(ptInThis);
		}

		last_pressed = nullptr;

		if (m_children.size() == 0) {
			Redraw();
		}
	}

	void LayoutControl::OnMouseMove(Gdiplus::PointF point)
	{
		Gdiplus::PointF ptInThis(point);
		ptInThis.Y -= GetRect().GetTop();
		ptInThis.X -= GetRect().GetLeft();

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

	void LayoutControl::OnMouseDown(Gdiplus::PointF point)
	{
		Gdiplus::PointF ptInThis(point);
		ptInThis.Y -= GetRect().GetTop();
		ptInThis.X -= GetRect().GetLeft();

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

			Gdiplus::PointF ptBegin(rect_in_parent.X, rect_in_parent.Y);
			m_bkgnd_shape->SetBeginPoint(ptBegin);

			Gdiplus::PointF ptEnd(rect_in_parent.GetRight(), rect_in_parent.GetBottom());
			m_bkgnd_shape->SetEndPoint(ptEnd);
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