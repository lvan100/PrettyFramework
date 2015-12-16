#pragma once

namespace PrettyFramework {

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

		COLORREF button_bk_color;
		COLORREF button_text_clr0;
		COLORREF button_border_clr;

		CFont label_text_font;
		CFont button_text_font;
	};

	/**
	 * ��ȡԤ��������ⷽ��
	 */
	BaseTheme* GetUITheme();

}