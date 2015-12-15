#include "stdafx.h"

#include "Label.h"
#include "BaseTheme.h"

namespace PrettyFramework {

	Label::Label(LayoutControl* parent)
		: UserControl(parent)
		, m_single_line(TRUE)
	{
		m_font = &GetUITheme()->label_text_font;
		m_bk_color = GetUITheme()->label_bk_color;
		m_text_color = GetUITheme()->label_text_clr0;
		m_border_color = GetUITheme()->label_border_clr;
	}

	Label::~Label()
	{
	}

	void Label::OnPaint(CDC& dc)
	{
		CRect rcPaint = GetPaintRect();
		if (!rcPaint.IsRectEmpty()) {

			CFont* pOldFont = dc.SelectObject(m_font);

			if (!IsBkgndNull()) {
				dc.FillSolidRect(rcPaint, m_bk_color);
			}

			if (!IsBorderNull()) {
				dc.FrameRect(rcPaint, &CBrush(m_border_color));
			}

			dc.SetBkMode(TRANSPARENT);
			dc.SetTextColor(m_text_color);

			rcPaint.DeflateRect(1, 1, 1, 1);

			DWORD nFormat = 0;

			if (m_single_line) {
				nFormat |= DT_SINGLELINE;
			}

			if ((m_gravity & Gravity::Left) == Gravity::Left) {
				nFormat |= DT_LEFT;
			}

			if ((m_gravity & Gravity::CenterH) == Gravity::CenterH) {
				nFormat |= DT_CENTER;
			}

			if ((m_gravity & Gravity::Right) == Gravity::Right) {
				nFormat |= DT_RIGHT;
			}

			if ((m_gravity & Gravity::Top) == Gravity::Top) {
				nFormat |= DT_TOP;
			}

			if ((m_gravity & Gravity::CenterV) == Gravity::CenterV) {
				nFormat |= DT_VCENTER;
			}

			if ((m_gravity & Gravity::Bottom) == Gravity::Bottom) {
				nFormat |= DT_BOTTOM;
			}

			dc.DrawText(m_text, rcPaint, nFormat);

			dc.SelectObject(pOldFont);
		}
	}

}