#pragma once

#include "UserControl.h"

namespace PrettyFramework {

	/**
	 * 标签控件
	 */
	class Label : public UserControl
	{
	public:
		Label(LayoutControl* parent);
		virtual ~Label();

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
		 * 获取文本内容
		 */
		CString GetText() {
			return m_text;
		}

		/**
		 * 设置文本内容
		 */
		void SetText(CString text) {
			m_text = text;
		}

	private:
		/**
		 * 文本内容
		 */
		CString m_text;

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

	protected:
		/**
		 * 绘制自身当前层
		 */
		virtual void OnPaint(CDC& dc);
	};

}