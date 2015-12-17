#include "stdafx.h"
#include "UserControl.h"
#include "AbsoluteLayout.h"

namespace PrettyFramework {

	UserControl::UserControl(LayoutControl* parent)
		: BaseControl(parent)
		, is_bkgnd_null(TRUE)
		, is_border_null(TRUE)
		, m_pressed(FALSE)
		, m_focused(FALSE)
		, m_hovered(FALSE)
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
		OnPaint(dc); /* »æÖÆµ±Ç°Í¼²ã */

		if (m_layout != nullptr) {
			m_layout->Paint(dc);
		}		
	}

	void UserControl::OnButtonUp(CPoint point)
	{
		// TRACE(_T("UserControl : %s button up \n"), GetId());

		m_pressed = GetRect().PtInRect(point);

		if (m_layout != nullptr) {
			m_layout->OnButtonUp(point);
		} else {
			Redraw();
		}
	}

	void UserControl::OnMouseMove(CPoint point)
	{
// 		TRACE(_T("UserControl : %s mouse move , Rect in parent : %d,%d,%d,%d , Point : %d,%d \n")
// 			, GetId(), GetRect().left, GetRect().top, GetRect().right, GetRect().bottom, point.x, point.y);

		BOOL hover_changed = FALSE;

		BOOL is_hovered = GetRect().PtInRect(point);
		if (is_hovered != m_hovered) {
			hover_changed = TRUE;
		}

		m_hovered = is_hovered;

		if (m_layout != nullptr) {
			m_layout->OnMouseMove(point);
		} else {
			if (hover_changed) {
				Redraw();
			}
		}

		if (hover_changed) {
			TRACE(_T("UserControl : %s redraw \n"), GetId());
		}
	}

	void UserControl::OnButtonDown(CPoint point)
	{
		// TRACE(_T("UserControl : %s button down \n"), GetId());

		m_focused = m_pressed = GetRect().PtInRect(point);

		if (m_layout != nullptr) {
			m_layout->OnButtonDown(point);
		} else {
			Redraw();
		}
	}

}