#include "stdafx.h"

#include "Label.h"
#include "BaseTheme.h"
#include "LabelStyle.h"

namespace PrettyFramework {

	LabelStyle::LabelStyle(Label* label)
		: m_label(label)
		, m_single_line(TRUE)
	{
	}
	
	LabelStyle::~LabelStyle()
	{
	}

	void LabelStyle::Paint(Gdiplus::Graphics& graph)
	{
// 		Rect rcView = m_label->GetViewRect();
// 		if (!rcView.IsRectEmpty()) {
// 			auto& theme = GetUITheme();
// 
// 			Rect rcMargined(rcView);
// 			rcMargined.DeflateRect(m_label->GetMargin());
// 
// 			CFont* pOldFont = dc.SelectObject(&theme->label_text_font);
// 
// 			dc.SetBkMode(TRANSPARENT);
// 			dc.SetTextColor(theme->label_text_clr);
// 
// 			DWORD nFormat = 0;
// 
// 			if (m_single_line) {
// 				nFormat |= DT_SINGLELINE;
// 			}
// 
// 			if ((m_label->GetGravity() & Gravity::Left) == Gravity::Left) {
// 				nFormat |= DT_LEFT;
// 			}
// 
// 			if ((m_label->GetGravity() & Gravity::CenterH) == Gravity::CenterH) {
// 				nFormat |= DT_CENTER;
// 			}
// 
// 			if ((m_label->GetGravity() & Gravity::Right) == Gravity::Right) {
// 				nFormat |= DT_RIGHT;
// 			}
// 
// 			if ((m_label->GetGravity() & Gravity::Top) == Gravity::Top) {
// 				nFormat |= DT_TOP;
// 			}
// 
// 			if ((m_label->GetGravity() & Gravity::CenterV) == Gravity::CenterV) {
// 				nFormat |= DT_VCENTER;
// 			}
// 
// 			if ((m_label->GetGravity() & Gravity::Bottom) == Gravity::Bottom) {
// 				nFormat |= DT_BOTTOM;
// 			}
// 
// 			dc.DrawText(m_label->GetText(), rcMargined, nFormat);
// 
// 			// dc.FrameRect(rcMargined, &CBrush(RGB(0, 0, 0))); 
// 			// dc.FrameRect(GetViewRect(), &CBrush(RGB(0, 0, 0)));
// 
// 			dc.SelectObject(pOldFont);
// 		}
	}

}