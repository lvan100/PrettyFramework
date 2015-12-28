#pragma once

#include <memory>
using namespace std;

namespace PrettyFramework {

	/**
	 * 基本界面主题
	 */
	class BaseTheme
	{
	public:
		BaseTheme();
		virtual ~BaseTheme();
		
		/**
		 * 重新加载配色方案
		 */
		void Reload(CString file);

	public:
		// 标签控件的字体
		CFont label_text_font;

		// 标签控件的背景颜色
		COLORREF label_bk_clr;

		// 标签控件的文字颜色
		COLORREF label_text_clr;

		// 标签控件的边框颜色
		COLORREF label_border_normal_clr;
		COLORREF label_border_hover_clr;
		COLORREF label_border_press_clr;
		COLORREF label_border_focus_clr;

		// 按钮控件的字体
		CFont button_text_font;

		// 按钮控件的文字颜色
		COLORREF button_text_clr;

		// 按钮控件的背景颜色
		COLORREF button_bk_normal_clr;
		COLORREF button_bk_hover_clr;
		COLORREF button_bk_press_clr;
		COLORREF button_bk_focus_clr;

		// 按钮控件的边框颜色
		COLORREF button_border_normal_clr;
		COLORREF button_border_hover_clr;
		COLORREF button_border_press_clr;
		COLORREF button_border_focus_clr;
	};

	/**
	 * 获取预设界面主题方案
	 */
	shared_ptr<BaseTheme>& GetUITheme();

}