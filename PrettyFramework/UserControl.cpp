#include "stdafx.h"
#include "UserControl.h"
#include "AbsoluteLayout.h"

namespace PrettyFramework {

	UserControl::UserControl(LayoutControl* parent)
		: BaseControl(parent)
		, is_bkgnd_null(FALSE)
		, is_border_null(FALSE)
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

		if (m_layout.get() != nullptr) {
			m_layout->Paint(dc);
		}
	}

	void UserControl::OnButtonUp()
	{

	}

	void UserControl::OnMouseMove()
	{

	}

	void UserControl::OnButtonDown()
	{

	}

}