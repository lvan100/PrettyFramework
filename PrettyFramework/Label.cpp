#include "stdafx.h"

#include "Label.h"
#include "BaseTheme.h"

Label::Label(LayoutControl* parent)
	: UserControl(parent)
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
			dc.SetBkColor(m_bk_color);
			dc.FillSolidRect(rcPaint, m_bk_color);
		}

		dc.SetBkMode(TRANSPARENT);
		dc.SetTextColor(m_text_color);

		dc.TextOut(rcPaint.left, rcPaint.top, m_text);

		dc.SelectObject(pOldFont);
	}
}