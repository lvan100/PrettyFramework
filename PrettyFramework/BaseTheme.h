#pragma once

/**
 * ������������
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
 * ��ȡԤ��������ⷽ��
 */
BaseTheme* GetUITheme();