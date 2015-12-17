#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Constant.h"

namespace PrettyFramework {

	//
	// 自定义控件模型（参考Android界面模型，如有雷同纯属巧合）
	//

	//
	// 自定义控件可以分为界面控件和布局控件两种。一个布局控件
	// 可以包含多个布局控件或者多个界面控件，并根据不同的规则
	// 将子控件布局在父控件内。布局控件的父控件可以是布局控件，
	// 也可以是界面控件。而一个界面控件则只能包含一个布局控件。
	//

	//
	// 根据以上规则，形成的XML界面描述文件形式如下：
	// 
	// <LayoutControl>
	//		<LayoutControl>
	//			<UserControl>
	//				<LayoutControl />
	//			</UserControl>
	//		</LayoutControl>
	//		<UserControl />
	//		<LayoutControl />
	//		<UserControl />
	// </LayoutControl>
	//

	// 
	// 在当前的模型中，布局控件可以不具有背景、边框等界面属性。
	// 

	// 
	// 控件的权重，一般而言，权重是一个[0.0f,1.0f]中间的某个值，
	// 如果某个控件的权重超过了1.0f，则认为该控件自动计算大小.
	// 

	// 
	// 在计算控件权重的时候，固定大小会按照所占父控件的比重计算，
	// 指定权重的控件将按照设置的比重计算，自动高度或者宽度的控件
	// 将按照剩余权重均匀分配.父控件宽度将按照1.0分配权重进行计算
	// 

	/**
	 * 基础控件
	 */
	class BaseControl
	{
		friend class UserControl;
		friend class LayoutControl;

	public:
		BaseControl(BaseControl* parent);
		virtual ~BaseControl();

		/**
		 * 获取父控件
		 */
		BaseControl* GetParent() {
			return m_parent;
		}

	protected:
		/**
		 * 父控件
		 */
		BaseControl* m_parent;

	public:
		/**
		 * 设置控件的ID
		 */
		void SetId(CString id) {
			m_id = id;
		}

		/**
		 * 获取控件的ID
		 */
		CString GetId() {
			return m_id;
		}

	protected:
		/**
		 * 控件的ID
		 */
		CString m_id;

	public:
		/**
		 * 获取本地窗口指针
		 */
		void* GetWindow() {
			return m_window;
		}

	protected:
		/**
		 * 设置本地窗口指针
		 */
		void SetWindow(void* window) {
			m_window = window;
		}

	protected:
		/**
		 * 本地窗口指针
		 */
		void* m_window;

	public:
		/**
		 * 设置控件显示区域
		 */
		void SetRect(CRect rect) {
			rect_in_parent = rect;
			RecalcLayout();
		}

		/**
		 * 获取控件显示区域
		 */
		CRect GetRect() {
			return rect_in_parent;
		}

	protected:
		/**
		 * 在父控件的显示区域
		 */
		CRect rect_in_parent;

	public:
		/**
		 * 设置固定大小
		 */
		void SetFixSize(CSize size) {
			m_fix_size = size;
		}

		/**
		 * 获取固定大小
		 */
		CSize GetFixSize() {
			return m_fix_size;
		}

	protected:
		/**
		 * 固定大小
		 */
		CSize m_fix_size;

	public:
		/**
		 * 设置控件的位置权重
		 */
		void SetWeight(float weight) {
			m_weight = weight;
		}

		/*
		 * 获取控件的位置权重
		 */
		float GetWeight() {
			return m_weight;
		}

	protected:
		/**
		 * 控件的权重
		 */
		float m_weight;

	public:
		/**
		 * 设置自动宽度
		 */
		void SetAutoWidth(BOOL autoWidth) {
			m_auto_width = autoWidth;
		}

		/**
		 * 是否设置了自动宽度
		 */
		BOOL IsAutoWidth() {
			return m_auto_width;
		}

	protected:
		/**
		 * 自动宽度
		 */
		BOOL m_auto_width;

	public:
		/**
		 * 设置自动高度
		 */
		void SetAutoHeight(BOOL autoHeight) {
			m_auto_height = autoHeight;
		}

		/**
		 * 是否设置了自动高度
		 */
		BOOL IsAutoHeight() {
			return m_auto_height;
		}

	protected:
		/**
		 * 自动高度
		 */
		BOOL m_auto_height;

	public:
		/**
		 * 设置内容的对齐方式，@Gravity
		 */
		void SetGravity(int gravity) {
			m_gravity = gravity;
		}

		/**
		 * 获取内容的对齐方式，@Gravity
		 */
		int GetGravity() {
			return m_gravity;
		}

	protected:
		/**
		 * 内容的对齐方式，@Gravity
		 */
		int m_gravity;

	protected:
		/**
		 * 重新绘制
		 */
		void Redraw();

		/**
		 * 获取控件的绘图坐标
		 */
		CRect GetPaintRect();

		/**
		 * 绘图
		 */
		virtual void Paint(CDC& dc) = 0;

	protected:
		/**
		 * 鼠标弹起
		 */
		virtual void OnButtonUp(CPoint point) = 0;

		/**
		 * 鼠标移动
		 */
		virtual void OnMouseMove(CPoint point) = 0;

		/**
		 * 鼠标按下
		 */
		virtual void OnButtonDown(CPoint point) = 0;

	protected:
		/**
		 * 重新计算界面控件的布局
		 */
		virtual void RecalcLayout() = 0;
	};

}