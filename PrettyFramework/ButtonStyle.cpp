#include "stdafx.h"
#include "Button.h"
#include "BaseTheme.h"
#include "ButtonStyle.h"

namespace PrettyFramework {

	ButtonStyle::ButtonStyle(Button* button)
		: m_button(button)
	{
		m_font = &GetUITheme()->button_text_font;
		m_bk_color = GetUITheme()->button_bk_color;
		m_text_color = GetUITheme()->button_text_clr;
		m_border_color = GetUITheme()->button_border_clr;
	}

	ButtonStyle::~ButtonStyle()
	{}

	COLORREF ButtonStyle::GetBkColor(State state)
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

	void ButtonStyle::SetBkColor(State state, COLORREF clr)
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

	COLORREF ButtonStyle::GetBorderColor(State state)
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

	void ButtonStyle::SetBorderColor(State state, COLORREF clr)
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

	void ButtonStyle::Paint(CDC& dc)
	{
		CRect rcView = m_button->GetViewRect();
		if (!rcView.IsRectEmpty()) {

			CRect rcMargined(rcView);
			rcMargined.DeflateRect(m_button->GetMargin());

			dc.FrameRect(rcView, &CBrush(m_border_color[0]));
			dc.FillSolidRect(rcView, m_bk_color[0]);

			if (m_button->IsFocused()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[3]));
				dc.FillSolidRect(rcView, m_bk_color[3]);
			}

			if (m_button->IsHovered()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[1]));
				dc.FillSolidRect(rcView, m_bk_color[1]);
			}

			if (m_button->IsPressed()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[2]));
				dc.FillSolidRect(rcView, m_bk_color[2]);
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