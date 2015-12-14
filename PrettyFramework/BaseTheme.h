#pragma once

/**
 * 基本界面主题
 */
class BaseTheme
{
public:
	BaseTheme();
	virtual ~BaseTheme();

	COLORREF label_bk_color;
	COLORREF label_text_clr0;
	COLORREF label_border_clr;

	CFont label_text_font;
};

/**
 * 获取预设界面主题方案
 */
BaseTheme* GetUITheme();