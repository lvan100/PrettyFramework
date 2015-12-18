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
		CRect rcView = GetViewRect();
		if (!rcView.IsRectEmpty()) {

			CRect rcMargined(rcView);
			rcMargined.DeflateRect(m_margin);

			if (IsPressed()) {
				dc.FillSolidRect(rcView, m_bk_color[0]);
			}

			if (IsFocused()) {
				DrawFocusRect(dc.GetSafeHdc(), rcView);
			}

			if (IsHovered()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[0]));
			}

			DrawIconEx(dc.GetSafeHdc(), rcMargined.left, rcMargined.top
				, m_bitmap, rcMargined.Width(), rcMargined.Height()
				, 0, nullptr, DI_NORMAL);

			// TODO 这时候向布局控件增加边框和背景应该也没有问题了
			dc.FrameRect(rcMargined, &CBrush(RGB(0, 0, 0)));

			// TODO 这时候向布局控件增加边框和背景应该也没有问题了
			dc.FrameRect(GetViewRect(), &CBrush(RGB(0, 0, 0)));

		}
	}

}