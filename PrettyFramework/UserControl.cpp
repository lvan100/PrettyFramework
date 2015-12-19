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

	void UserControl::RecalcLayout()
	{
		if (m_layout != nullptr) {
			CRect rcClient(GetRect());
			rcClient.MoveToXY(0, 0);
			m_layout->SetRect(rcClient);
		}
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

	COLORREF UserControl::GetBkColor(State state)
	{
		switch (state)
		{
		case PrettyFramework::Normal:
			return m_bk_color[0];
		case PrettyFramework::Hovered:
			return m_bk_color[1];
		case PrettyFramework::Pressed:
			return m_bk_color[2];
		case PrettyFramework::Focused:
			return m_bk_color[3];
		case PrettyFramework::Disable:
			return m_bk_color[4];
		default:
			return m_bk_color[0];
		}
	}

	void UserControl::SetBkColor(State state, COLORREF clr)
	{
		switch (state)
		{
		case PrettyFramework::Normal:
			m_bk_color[0] = clr;
			break;
		case PrettyFramework::Hovered:
			m_bk_color[1] = clr;
			break;
		case PrettyFramework::Pressed:
			m_bk_color[2] = clr;
			break;
		case PrettyFramework::Focused:
			m_bk_color[3] = clr;
			break;
		case PrettyFramework::Disable:
			m_bk_color[4] = clr;
			break;
		default:
			m_bk_color[0] = clr;
			break;
		}
	}

	COLORREF UserControl::GetBorderColor(State state)
	{
		switch (state)
		{
		case PrettyFramework::Normal:
			return m_border_color[0];
		case PrettyFramework::Hovered:
			return m_border_color[1];
		case PrettyFramework::Pressed:
			return m_border_color[2];
		case PrettyFramework::Focused:
			return m_border_color[3];
		case PrettyFramework::Disable:
			return m_border_color[4];
		default:
			return m_border_color[0];
		}
	}

	void UserControl::SetBorderColor(State state, COLORREF clr)
	{
		switch (state)
		{
		case PrettyFramework::Normal:
			m_border_color[0] = clr;
			break;
		case PrettyFramework::Hovered:
			m_border_color[1] = clr;
			break;
		case PrettyFramework::Pressed:
			m_border_color[2] = clr;
			break;
		case PrettyFramework::Focused:
			m_border_color[3] = clr;
			break;
		case PrettyFramework::Disable:
			m_border_color[4] = clr;
			break;
		default:
			m_border_color[0] = clr;
			break;
		}
	}

	void UserControl::SetDisable(BOOL disable)
	{
		if (disable) {
			m_state |= State::Disable;
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
		SetPressed(FALSE);
		SetFocused(GetRect().PtInRect(point));

		if (m_layout != nullptr) {
			m_layout->OnMouseUp(point);
		} else {
			Redraw();
		}
	}

	void UserControl::OnMouseMove(CPoint point)
	{
		BOOL hover_changed = FALSE;

		BOOL is_hovered = GetRect().PtInRect(point);
		if (is_hovered != IsHovered()) {
			hover_changed = TRUE;
		}

		SetHovered(is_hovered);

		if (m_layout != nullptr) {
			m_layout->OnMouseMove(point);
		} else {
			if (hover_changed) {
				Redraw();				
			}
		}
	}

	void UserControl::OnMouseDown(CPoint point)
	{
		BOOL ptInRect = GetRect().PtInRect(point);
		SetFocused(ptInRect);
		SetPressed(ptInRect);

		if (m_layout != nullptr) {
			m_layout->OnMouseDown(point);
		} else {
			Redraw();
		}
	}

	BaseControl* UserControl::OnFindControlById(CString id)
	{
		if (m_id == id) { return this; }

		if (m_layout != nullptr) {
			return m_layout->OnFindControlById(id);
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