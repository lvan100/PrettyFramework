#pragma once

#include "Constant.h"

namespace PrettyFramework {

	/**
	 * 基本界面主题
	 */
	class BaseTheme
	{
	public:
		BaseTheme();
		virtual ~BaseTheme();

		COLORREF label_text_clr;
		StateColor label_bk_color;
		StateColor label_border_clr;

		COLORREF button_text_clr;
		StateColor button_bk_color;
		StateColor button_border_clr;

		CFont label_text_font;
		CFont button_text_font;
	};

	/**
	 * 获取预设界面主题方案
	 */
	BaseTheme* GetUITheme();

}