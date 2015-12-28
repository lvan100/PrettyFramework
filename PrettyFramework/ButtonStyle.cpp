#include "stdafx.h"
#include "Button.h"
#include "BaseTheme.h"
#include "ButtonStyle.h"

namespace PrettyFramework {

	ButtonStyle::ButtonStyle(Button* button)
		: m_button(button)
	{
	}

	ButtonStyle::~ButtonStyle()
	{}

	void ButtonStyle::Paint(CDC& dc)
	{
		CRect rcView = m_button->GetViewRect();
		if (!rcView.IsRectEmpty()) {
			auto& theme = GetUITheme();

			CRect rcMargined(rcView);
			rcMargined.DeflateRect(m_button->GetMargin());

			dc.FrameRect(rcView, &CBrush(theme->button_border_normal_clr));
			dc.FillSolidRect(rcView, theme->button_bk_normal_clr);

			if (m_button->IsFocused()) {
				dc.FrameRect(rcView, &CBrush(theme->button_border_focus_clr));
				dc.FillSolidRect(rcView, theme->button_bk_focus_clr);
			}

			if (m_button->IsHovered()) {
				dc.FrameRect(rcView, &CBrush(theme->button_border_hover_clr));
				dc.FillSolidRect(rcView, theme->button_bk_hover_clr);
			}

			if (m_button->IsPressed()) {
				dc.FrameRect(rcView, &CBrush(theme->button_border_press_clr));
				dc.FillSolidRect(rcView, theme->button_bk_press_clr);
			}

			DrawIconEx(dc.GetSafeHdc(), rcMargined.left, rcMargined.top
				, m_button->GetBitmap(), rcMargined.Width(), rcMargined.Height()
				, 0, nullptr, DI_NORMAL);

			if (m_button->IsDisable()) {

			}

			// dc.FrameRect(rcMargined, &CBrush(RGB(0, 0, 0)));
			// dc.FrameRect(GetViewRect(), &CBrush(RGB(0, 0, 0)));

		}
	}

}