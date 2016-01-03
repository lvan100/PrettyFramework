#pragma once

#include "Visual.h"

namespace PrettyFramework {

	/**
	 * 绘图形状,具有边界和填充等属性。
	 */
	class Shape : public Visual
	{
	public:
		Shape()
			: m_border_width(0)
			, m_fill_null(FALSE)
			, m_border_null(FALSE)
			, m_border_style(PS_SOLID)
		{}

		virtual ~Shape() {}

	public:
		/**
		 * 设置边框的宽度
		 */
		void SetBorderWidth(float width) {
			m_border_width = width;
		}

		/**
		 * 获取边框的宽度
		 */
		float GetBorderWidth() {
			return m_border_width;
		}

	protected:
		/**
		 * 边框的宽度
		 */
		float m_border_width;

	public:
		/**
		 * 设置边框的颜色
		 */
		void SetBorderColor(Gdiplus::Color clr) {
			m_border_color = clr;
		}

		/**
		 * 获取边框的颜色
		 */
		Gdiplus::Color GetBorderColor() {
			return m_border_color;
		}

	protected:
		/**
		 * 边框的颜色
		 */
		Gdiplus::Color m_border_color;

	public:
		/**
		 * 设置边框的样式，@Gdiplus::Pen
		 */
		void SetBorderStyle(int style) {
			m_border_style = style;
		}

		/**
		 * 获取边框的样式，@Gdiplus::Pen
		 */
		int GetBorderStyle() {
			return m_border_style;
		}

	protected:
		/**
		 * 边框的样式，@Gdiplus::Pen
		 */
		int m_border_style;

	public:
		/**
		 * 设置边框是否为空
		 */
		void SetBorderNull(BOOL isNull) {
			m_border_null = isNull;
		}

		/**
		 * 边框是否为空
		 */
		BOOL IsBorderNull() {
			return m_border_null;
		}

	protected:
		/**
		 * 边框是否为空
		 */
		BOOL m_border_null;

	public:
		/**
		 * 设置填充的颜色
		 */
		void SetFillColor(Gdiplus::Color clr) {
			m_fill_color = clr;
		}

		/**
		 * 获取填充的颜色
		 */
		Gdiplus::Color GetFillColor() {
			return m_fill_color;
		}

	protected:
		/**
		 * 填充的颜色
		 */
		Gdiplus::Color m_fill_color;

	public:
		/**
		 * 设置填充是否为空
		 */
		void SetFillNull(BOOL isNull) {
			m_fill_null = isNull;
		}

		/**
		 * 填充是否为空
		 */
		BOOL IsFillNull() {
			return m_fill_null;
		}

	protected:
		/**
		 * 填充是否为空
		 */
		BOOL m_fill_null;
	};

}