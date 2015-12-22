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

	void UserControl::Paint(CDC& dc)
	{
		OnPaint(dc); /* 绘制自身图层 */

		if (m_layout != nullptr) {
			
			CRgn rgnClip;

			CRect rcOldClip;
			dc.GetClipBox(rcOldClip);

			CRect rcClip = GetViewRect();
			rcClip.DeflateRect(m_margin);

			rgnClip.CreateRectRgnIndirect(rcClip);

			{ /* 绘制子控件 */

				CRgn rgnControl;

				CRect rect = m_layout->GetViewRect();
				rgnControl.CreateRectRgnIndirect(rect);

				// 防止子控件的绘图区域超出父控件的显示范围.
				rgnControl.CombineRgn(&rgnClip, &rgnControl, RGN_AND);
				dc.SelectClipRgn(&rgnControl);

				m_layout->Paint(dc);
			}			

			CRgn rgnOldClip;
			rgnOldClip.CreateRectRgnIndirect(rcOldClip);

			dc.SelectClipRgn(&rgnOldClip);
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

	void UserControl::OnMouseUp(CPoint point)
	{
		if (IsDisable()) {
			return;
		}

		SetPressed(FALSE);
		SetFocused(HitTest(point));

		EventParam param;
		param.control = this;
		param.will_eat_it = FALSE;

		OnPreviewMouseUp(param);

		if (param.will_eat_it) {
			return; /* 吃掉它 */
		} 

		if (m_layout != nullptr) {
			m_layout->OnMouseUp(point);
		} else {
			Redraw();
		}

		OnMouseUp(param);
	}

	void UserControl::OnMouseMove(CPoint point)
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
		param.control = this;
		param.will_eat_it = FALSE;

		OnPreviewMouseMove(param);

		if (param.will_eat_it) {
			return; /* 吃掉它 */
		}

		if (m_layout != nullptr) {
			m_layout->OnMouseMove(point);
		} else {
			if (hover_changed) {
				Redraw();				
			}
		}

		OnMouseMove(param);
	}

	void UserControl::OnMouseDown(CPoint point)
	{
		if (IsDisable()) {
			return;
		}

		EventParam param;
		param.control = this;
		param.will_eat_it = FALSE;

		OnPreviewMouseDown(param);

		if (param.will_eat_it) {
			return; /* 吃掉它 */
		}

		BOOL ptHitted = HitTest(point);
		SetFocused(ptHitted);
		SetPressed(ptHitted);

		if (m_layout != nullptr) {
			m_layout->OnMouseDown(point);
		} else {
			Redraw();
		}

		OnMouseDown(param);
	}

	void UserControl::RecalcLayout()
	{
		if (m_layout != nullptr) {
			CRect rcClient(GetRect());
			rcClient.MoveToXY(0, 0);
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
		TRACE(_T("UserControl:%s Rect:%d,%d,%d,%d \n"), GetId()
			, GetRect().left, GetRect().top, GetRect().right
			, GetRect().bottom);

		if (m_layout != nullptr) {
			return m_layout->Dump();
		}
	}

}