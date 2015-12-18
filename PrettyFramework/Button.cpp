#include "stdafx.h"

#include "Button.h"
#include "BaseTheme.h"

namespace PrettyFramework {

	Button::Button(LayoutControl* parent)
		: UserControl(parent)
		, m_bitmap(nullptr)
	{
		m_font = &GetUITheme()->button_text_font;
		m_bk_color = GetUITheme()->button_bk_color;
		m_text_color = GetUITheme()->button_text_clr;
		m_border_color = GetUITheme()->button_border_clr;
	}

	Button::~Button()
	{
	}

	void Button::OnPaint(CDC& dc)
	{
		CRect rcPaint = GetPaintRect();
		if (!rcPaint.IsRectEmpty()) {

			if (IsPressed()) {
				dc.FillSolidRect(rcPaint, m_bk_color[0]);
			}

			if (IsFocused()) {
				DrawFocusRect(dc.GetSafeHdc(), rcPaint);
			}

			if (IsHovered()) {
				dc.FrameRect(rcPaint, &CBrush(m_border_color[0]));
			}

			DrawIconEx(dc.GetSafeHdc(), rcPaint.left, rcPaint.top
				, m_bitmap, rcPaint.Width(), rcPaint.Height()
				, 0, nullptr, DI_NORMAL);
		}
	}

}