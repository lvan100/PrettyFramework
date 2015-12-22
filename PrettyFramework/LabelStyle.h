#pragma once

#include "VisualStyle.h"

namespace PrettyFramework {

	class Label;

	/**
	 * 标签样式
	 */
	class LabelStyle : public VisualStyle
	{
	public:
		LabelStyle(Label* label);
		virtual ~LabelStyle();

	public:
		/**
		 * 设置只显示单行文本
		 */
		void SetSingleLine(BOOL singleLine) {
			m_single_line = singleLine;
		}

		/**
		 * 是否只显示单行文本
		 */
		BOOL IsSingleLine() {
			return m_single_line;
		}

	protected:
		/**
		 * 只显示单行文本
		 */
		BOOL m_single_line;

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

	protected:
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

	protected:
		/**
		 * 字体
		 */
		CFont* m_font;

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * 绑定的标签控件
		 */
		Label* m_label;
	};

}