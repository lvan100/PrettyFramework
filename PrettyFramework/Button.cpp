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

			dc.FrameRect(rcView, &CBrush(m_border_color[0]));
			dc.FillSolidRect(rcView, m_bk_color[0]);

			if (IsFocused()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[3]));
				dc.FillSolidRect(rcView, m_bk_color[3]);
			}

			if (IsHovered()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[1]));
				dc.FillSolidRect(rcView, m_bk_color[1]);
			}

			if (IsPressed()) {
				dc.FrameRect(rcView, &CBrush(m_border_color[2]));
				dc.FillSolidRect(rcView, m_bk_color[2]);
			}

			DrawIconEx(dc.GetSafeHdc(), rcMargined.left, rcMargined.top
				, m_bitmap, rcMargined.Width(), rcMargined.Height()
				, 0, nullptr, DI_NORMAL);

			if (IsDisable()) {

			}

// 			// TODO 这时候向布局控件增加边框和背景应该也没有问题了
// 			dc.FrameRect(rcMargined, &CBrush(RGB(0, 0, 0)));
// 
// 			// TODO 这时候向布局控件增加边框和背景应该也没有问题了
// 			dc.FrameRect(GetViewRect(), &CBrush(RGB(0, 0, 0)));

		}
	}
	
	void Button::OnPreviewMouseUp(EventParam& param)
	{
		UserControl::OnPreviewMouseUp(param);

		if (m_click) {
			ClickParam click = { this };
			m_click(click);
		}
	}
	
	void Button::OnMouseUp(EventParam& param)
	{
		UserControl::OnMouseUp(param);
	}
	
	void Button::OnPreviewMouseMove(EventParam& param)
	{
		UserControl::OnPreviewMouseMove(param);
	}

	void Button::OnMouseMove(EventParam& param)
	{
		UserControl::OnMouseMove(param);
	}

	void Button::OnPreviewMouseDown(EventParam& param)
	{
		UserControl::OnPreviewMouseDown(param);
	}
	
	void Button::OnMouseDown(EventParam& param)
	{
		UserControl::OnMouseDown(param);
	}
	
}