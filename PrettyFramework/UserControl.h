#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * 界面控件
	 */
	class UserControl : public BaseControl
	{
		friend class LayoutControl;

	public:
		UserControl(LayoutControl* parent);
		virtual ~UserControl();

		/**
		 * 设置布局控件
		 */
		void SetLayoutControl(shared_ptr<LayoutControl> layout) {
			m_layout = layout;
			RecalcLayout();
		}

		/**
		 * 获取布局控件
		 */
		shared_ptr<LayoutControl>& GetLayoutControl() {
			return m_layout;
		}

	protected:
		/**
		 * 布局控件，默认为绝对布局控件
		 */
		shared_ptr<LayoutControl> m_layout;

	protected:
		/**
		 * 重新计算界面控件的布局
		 */
		virtual void RecalcLayout();

	public:
		/**
		 * 获取背景颜色
		 */
		COLORREF GetBkColor() {
			return m_bk_color;
		}

		/**
		 * 设置背景颜色
		 */
		void SetBkColor(COLORREF clr) {
			m_bk_color = clr;
		}

	protected:
		/**
		 * 背景颜色
		 */
		COLORREF m_bk_color;

	public:
		/**
		 * 获取边框颜色
		 */
		COLORREF GetBorderColor() {
			return m_border_color;
		}

		/**
		 * 设置边框颜色
		 */
		void SetBorderColor(COLORREF clr) {
			m_border_color = clr;
		}

	protected:
		/**
		 * 边框颜色
		 */
		COLORREF m_border_color;

	public:
		/**
		 * 设置控件为空白背景
		 */
		void SetBkgndNull(BOOL isNull = TRUE) {
			is_bkgnd_null = isNull;
		}

		/**
		 * 是否设置为空白背景
		 */
		BOOL IsBkgndNull() {
			return is_bkgnd_null;
		}

	protected:
		/**
		 * 是否为空白背景
		 */
		BOOL is_bkgnd_null;

	public:
		/**
		 * 设置控件为无边框
		 */
		void SetBorderNull(BOOL isNull = TRUE) {
			is_border_null = isNull;
		}

		/**
		 * 是否设置为无边框
		 */
		BOOL IsBorderNull() {
			return is_border_null;
		}

	protected:
		/**
		 * 是否为无边框
		 */
		BOOL is_border_null;

	protected:
		/**
		 * 绘图
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * 绘制自身
		 */
		virtual void OnPaint(CDC& dc) = 0;

	protected:
		/**
		 * 是否处于按下
		 */
		BOOL m_pressed;

		/**
		 * 是否处于焦点
		 */
		BOOL m_focused;

		/**
		 * 是否处于热点
		 */
		BOOL m_hovered;

	protected:
		/**
		 * 鼠标弹起
		 */
		virtual void OnButtonUp(CPoint point);

		/**
		 * 鼠标移动
		 */
		virtual void OnMouseMove(CPoint point);

		/**
		 * 鼠标按下
		 */
		virtual void OnButtonDown(CPoint point);
	};

}