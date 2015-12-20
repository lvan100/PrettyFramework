#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Constant.h"

namespace PrettyFramework {

	//
	// 自定义控件模型（部分实现参考Android界面模型的概念）
	//

	//
	// 自定义控件本质上可以分为[界面控件]和[布局控件]两种。
	// 界面控件就是显示内容的控件，可以响应鼠标和键盘消息；
	// 布局控件是通过指定规则将子控件排列在父控件内的控件。
	//
	
	// 
	// 布局控件可以容纳任何控件，其父控件既可以是布局控件，
	// 也可以是界面控件。而界面控件则只能包含一个布局控件，
	// 其父控件也只能是布局控件。
	// 
	
	//
	// 根据以上规则生成的 XML 格式的界面描述文件形式如下：
	// 
	// <LayoutControl id="root">
	//		<LayoutControl id="title">
	//			<UserControl id="app_icon">
	//				<LayoutControl />
	//			</UserControl>
	//		</LayoutControl>
	//		<UserControl id="content" />
	//		<LayoutControl id="status">
	//			<UserControl id="tip">
	//				<LayoutControl />
	//			</UserControl>
	//		</LayoutControl>
	// </LayoutControl>
	//

	// 
	// 在此模型中，布局控件不打算具有背景、边框等界面属性。
	// 

	// 
	// 布局控件在计算控件权重的时候，固定大小的控件会按照
	// 所占父控件的比重计算，指定权重的控件将按照设置的权
	// 重计算，自动高度或者宽度的控件将均匀分配剩余权重。
	// 
	
	// 
	// 一般而言，控件的权重必须是[0.0f, 1.0f]中间的某个值。
	// 

	// 
	// 用户只能操控界面控件的事件，其事件机制类似WPF的处理，
	// 分为隧道和冒泡两种类型，在隧道事件中可以阻止冒泡事件
	// 的发生。对于事件的处理包含类继承和事件注入两个层面。
	// 

	/**
	 * 基础控件，定义了[界面控件]和[布局控件]都包含的属性。
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
		 * 设置控件在父控件的坐标
		 */
		void SetRect(CRect rect) {
			rect_in_parent = rect;
			RecalcLayout();
		}

		/**
		 * 获取控件在父控件的坐标
		 */
		CRect GetRect() {
			return rect_in_parent;
		}

	protected:
		/**
		 * 在父控件的显示坐标
		 */
		CRect rect_in_parent;

	public:
		/**
		 * 设置控件的固定宽高
		 */
		void SetFixSize(CSize size) {
			m_fix_size = size;
		}

		/**
		 * 获取控件的固定宽高
		 */
		CSize GetFixSize() {
			return m_fix_size;
		}

	protected:
		/**
		 * 控件的固定宽高
		 */
		CSize m_fix_size;

	public:
		/**
		 * 设置控件的布局权重
		 */
		void SetWeight(float weight) {
			m_weight = weight;
		}

		/**
		 * 获取控件的布局权重
		 */
		float GetWeight() {
			return m_weight;
		}

	protected:
		/**
		 * 控件的布局权重
		 */
		float m_weight;

	public:
		/**
		 * 设置控件是否具有自动宽度
		 */
		void SetAutoWidth(BOOL autoWidth) {
			m_auto_width = autoWidth;
		}

		/**
		 * 查询控件是否具有自动宽度
		 */
		BOOL IsAutoWidth() {
			return m_auto_width;
		}

	protected:
		/**
		 * 是否具有自动宽度
		 */
		BOOL m_auto_width;

	public:
		/**
		 * 设置控件是否具有自动高度
		 */
		void SetAutoHeight(BOOL autoHeight) {
			m_auto_height = autoHeight;
		}

		/**
		 * 查询控件是否具有自动高度
		 */
		BOOL IsAutoHeight() {
			return m_auto_height;
		}

	protected:
		/**
		 * 是否具有自动高度
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

	public:
		/**
		 * 设置控件的内边距
		 */
		void SetMargin(CRect margin) {
			m_margin = margin;
		}

		/**
		 * 获取控件的内边距
		 */
		CRect GetMargin() {
			return m_margin;
		}

	protected:
		/**
		 * 控件的内边距
		 */
		CRect m_margin;

	protected:
		/**
		 * 重绘控件
		 */
		void Redraw();

		/**
		 * 获取控件的视图坐标
		 */
		CRect GetViewRect();

		/**
		 * 通知控件需要进行绘图
		 */
		virtual void Paint(CDC& dc) = 0;

	protected:
		/**
		 * 鼠标弹起事件
		 */
		virtual void OnMouseUp(CPoint point) = 0;

		/**
		 * 鼠标移动事件
		 */
		virtual void OnMouseMove(CPoint point) = 0;

		/**
		 * 鼠标按下事件
		 */
		virtual void OnMouseDown(CPoint point) = 0;

	protected:
		/**
		 * 重新计算子控件的布局
		 */
		virtual void RecalcLayout() = 0;

	public:
		/**
		 * 查找指定ID的控件，查找失败返回空指针
		 */
		BaseControl* FindControlById(CString id) {
			return OnFindControlById(id);
		}

	protected:
		/**
		 * 设置一个子类根据ID查找控件的接口函数
		 */
		virtual BaseControl* OnFindControlById(CString id) = 0;

	public:
		/**
		 * 输出控件的详细信息
		 */
		virtual void Dump() = 0;
	};

}