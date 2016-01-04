#include "stdafx.h"
#include "UserControl.h"

namespace PrettyFramework {

	UserControl::UserControl(LayoutControl* parent)
		: BaseControl(parent)
		, m_state(State::Normal)
	{
	}

	UserControl::~UserControl()
	{
	}

	void UserControl::Paint(Gdiplus::Graphics& graph)
	{
		OnPaint(graph); /* 绘制自身图层 */

		if (m_layout != nullptr) {
			
			Gdiplus::Region rgnOldClip;
			graph.GetClip(&rgnOldClip);

			Rect rcClip = GetViewRect();
			rcClip.DeflateRect(m_margin);

			auto& F = toGdiplusRect(rcClip);
			Gdiplus::Region rgnClip(F);

			{ /* 绘制子控件 */

				Rect rect = m_layout->GetViewRect();
				auto& F2 = toGdiplusRect(rect);

				Gdiplus::Region rgnControl(F2);

				rgnControl.Intersect(&rgnClip);
				graph.SetClip(&rgnControl);

				m_layout->Paint(graph);
			}			

			graph.SetClip(&rgnOldClip);
		}
	}

	void UserControl::SetDisable(BOOL disable)
	{
		if (disable) {
			m_state = State::Disable;
		} else {
			m_state &= ~State::Disable;
		}
	}

	void UserControl::SetPressed(BOOL pressed)
	{
		if (pressed) {
			m_state |= State::Pressed;
		} else {
			m_state &= ~State::Pressed;
		}
	}
	
	void UserControl::SetFocused(BOOL focused)
	{
		if (focused) {
			m_state |= State::Focused;
		} else {
			m_state &= ~State::Focused;
		}
	}

	void UserControl::SetHovered(BOOL hovered)
	{
		if (hovered) {
			m_state |= State::Hovered;
		} else {
			m_state &= ~State::Hovered;
		}
	}

	void UserControl::OnMouseUp(Point point)
	{
		if (IsDisable()) {
			return;
		}

		BOOL bHitted = HitTest(point);
		SetPressed(FALSE);
		SetFocused(bHitted);

		EventParam param;
		param.point = point;
		param.control = this;
		param.will_eat_it = FALSE;

		if (bHitted) {
			OnPreviewMouseUp(param);
			if (param.will_eat_it) {
				return; /* 吃掉它 */
			}
		}

		if (m_layout != nullptr) {
			m_layout->OnMouseUp(point);
		} else {
			Redraw();
		}

		if (bHitted) {
			OnMouseUp(param);
		}
	}

	void UserControl::OnMouseMove(Point point)
	{
		if (IsDisable()) {
			return;
		}

		BOOL hover_changed = FALSE;

		BOOL is_hovered = HitTest(point);
		if (is_hovered != IsHovered()) {
			hover_changed = TRUE;
		}

		SetHovered(is_hovered);

		EventParam param;
		param.point = point;
		param.control = this;
		param.will_eat_it = FALSE;

		if (is_hovered) {
			OnPreviewMouseMove(param);
			if (param.will_eat_it) {
				return; /* 吃掉它 */
			}
		}

		if (m_layout != nullptr) {
			m_layout->OnMouseMove(point);
		} else {
			if (hover_changed) {
				Redraw();				
			}
		}

		if (is_hovered) {
			OnMouseMove(param);
		}
	}

	void UserControl::OnMouseDown(Point point)
	{
		if (IsDisable()) {
			return;
		}

		BOOL ptHitted = HitTest(point);
		SetFocused(ptHitted);
		SetPressed(ptHitted);

		EventParam param;
		param.point = point;
		param.control = this;
		param.will_eat_it = FALSE;

		if (ptHitted) {
			OnPreviewMouseDown(param);
			if (param.will_eat_it) {
				return; /* 吃掉它 */
			}
		}

		if (m_layout != nullptr) {
			m_layout->OnMouseDown(point);
		} else {
			Redraw();
		}

		if (ptHitted) {
			OnMouseDown(param);
		}
	}

	void UserControl::RecalcLayout()
	{
		if (m_layout != nullptr) {
			Rect rcClient(GetRect());
			rcClient.MoveTo(0.0f, 0.0f);
			m_layout->SetRect(rcClient);
		}
	}

	BaseControl* UserControl::FindControlById(CString id)
	{
		if (m_id == id) { return this; }

		if (m_layout != nullptr) {
			return m_layout->FindControlById(id);
		}

		return nullptr;
	}

	void UserControl::Dump()
	{
		TRACE(_T("UserControl:%s Rect:%d,%d,%d,%d \n"), GetId(), GetRect().GetLeft()
			, GetRect().GetTop(), GetRect().GetRight(), GetRect().GetBottom());

		if (m_layout != nullptr) {
			return m_layout->Dump();
		}
	}

}