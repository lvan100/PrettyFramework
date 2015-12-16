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
		m_layout = shared_ptr<AbsoluteLayout>(new AbsoluteLayout(this));
	}

	UserControl::~UserControl()
	{
	}

	void UserControl::RecalcLayout()
	{
		if (m_layout.get() != nullptr) {
			CRect rcClient(GetRect());
			rcClient.MoveToXY(0, 0);
			m_layout->SetRect(rcClient);
		}
	}

	void UserControl::Paint(CDC& dc)
	{
		OnPaint(dc); /* »æÖÆµ±Ç°Í¼²ã */

		m_layout->Paint(dc);
	}

	void UserControl::OnButtonUp(CPoint point)
	{
		m_pressed = FALSE;
		m_layout->OnButtonUp(point);
	}

	void UserControl::OnMouseMove(CPoint point)
	{
		m_hovered = TRUE;
		m_layout->OnMouseMove(point);
	}

	void UserControl::OnButtonDown(CPoint point)
	{
		m_pressed = TRUE;
		m_layout->OnButtonDown(point);
	}

}