#pragma once

#include "Constant.h"
#include "VisualStyle.h"

namespace PrettyFramework {

	class Button;

	/**
	 * 按钮样式
	 */
	class ButtonStyle : public VisualStyle
	{
	public:
		ButtonStyle(Button* button);
		virtual ~ButtonStyle();

	public:
		/**
		 * 设置文本颜色
		 */
		void SetTextColor(COLORREF clr) {
			m_text_color = clr;
		}

		/**
		 * 获取文本颜色
		 */
		COLORREF GetTextColor() {
			return m_text_color;
		}

	private:
		/**
		 * 文本颜色
		 */
		COLORREF m_text_color;

	public:
		/**
		 * 获取字体
		 */
		CFont* GetFont() {
			return m_font;
		}

		/**
		 * 设置字体
		 */
		void SetFont(CFont* font) {
			m_font = font;
		}

	private:
		/**
		 * 字体
		 */
		CFont* m_font;

	public:
		/**
		 * 获取不同状态下的背景颜色
		 */
		COLORREF GetBkColor(State state);

		/**
		 * 设置不同状态下的背景颜色
		 */
		void SetBkColor(State state, COLORREF clr);

	protected:
		/**
		 * 控件不同状态下的背景颜色
		 */
		StateColor m_bk_color;

	public:
		/**
		 * 获取不同状态下的边框颜色
		 */
		COLORREF GetBorderColor(State state);

		/**
		 * 设置不同状态下的边框颜色
		 */
		void SetBorderColor(State state, COLORREF clr);

	protected:
		/**
		 * 控件不同状态下的边框颜色
		 */
		StateColor m_border_color;

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * 绑定的按钮控件
		 */
		Button* m_button;
	};

}