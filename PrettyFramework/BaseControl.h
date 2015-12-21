#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Constant.h"
#include "VisualStyle.h"

namespace PrettyFramework {

	//
	// 优美控件模型（部分实现参考Android、WPF界面模型概念）
	//

	//
	// “传统界面库如MFC、ATL等只有一种控件的概念，即界面控
	// 件，所以这些界面库都在控件布局上暴露出了很大的不足。
	// 后来出现的WPF虽然有了[容器控件]的概念，但是在实现上
	// 仍然将容器功能集成在界面控件之内，而众所周知的是，WPF
	// 的学习曲线很陡，我觉得一大部分来源于WPF界面模型的复杂
	// 。概念简单、实现灵活、容易使用的界面模型该如何实现呢？
	// 经过几年的思考之后，我终于有机会能够给出自己的答案！”
	// 

	// 
	// “我一直对QT的界面模型很感兴趣，但是在职业生涯的很多时
	// 间里我没有机会去了解它。在我从事过一段时间的Android编
	// 程后，我发现Android的界面模型很有意思，也很简单。最近
	// 在做一个资料管理软件（基于MFC）的时候，由于界面上需要
	// 做定制化，机缘巧合之下又重新思考了一下接触过的几个界面
	// 模型，对于自己的界面模型在心里也似乎有了模样，然后一番
	// 实践下来，越发觉得我的思路应该是正确的。”
	// 

	// 
	// 我把控件分为[界面控件]和[布局控件]两种。界面控件就是展
	// 示内容给用户看的控件，它可以响应鼠标和键盘消息，并在视
	// 觉上做出响应；而布局控件仅仅只是通过规则将子控件排列在
	// 父控件内的控件，它只具有背景和边框这两种简单的视觉效果。
	//
	
	// 
	// 理论上，布局控件可以容纳任何类型的控件，也就是说它可以只
	// 拥有界面控件，也可以只拥有布局控件，还可以同时拥有界面控
	// 件和布局控件，这样的设定其实就是“容器控件”概念的实现。
	// 而且布局控件的父控件既可以是布局控件，也可以是界面控件。
	// 虽然很可能是一件很无聊的事情，但是全部由布局控件构成的界
	// 面模型在理论上也是成立的。
	// 
	
	//
	// 一个界面控件只能拥有一个布局控件，而且其父控件也只能是布
	// 局控件。这样的设定赋予了界面控件“无限容器”的特性。酷！
	// 
	
	//
	// 根据以上控件规则生成的XML格式的界面模型描述文件形式如下：
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
	// 布局控件在计算控件权重的时候，固定大小的控件会按照其所占父
	// 控件的宽高比重计算，指定权重的控件将按照设置的权重进行计算
	// ，而设定了自动高度或者自动宽度的控件将均匀分配剩余的权重。
	// 
	
	// 
	// 一般而言，控件的权重必须是[0.0f,1.0f]中间的某个值，而且其父
	// 控件的权重总和是1.0f，那么如果子控件的权重总和超过了1.0f，
	// 就意味着有些子控件可能看不到或者显示不完整。
	// 

	// 
	// 该界面模型的事件机制采用类似WPF的处理，分为隧道和冒泡两种类
	// 型，用户可以在隧道事件中阻止冒泡事件的发生。而实现隧道事件的
	// 方式包含类继承和事件注入两种。
	// 

	/**
	 * 基础控件接口，定义那些[界面控件]和[布局控件]都必须包含的属性。
	 */
	class BaseControl : public VisualStyle
	{
		friend class UserControl;
		friend class LayoutControl;

	public:
		BaseControl(BaseControl* parent);
		virtual ~BaseControl();

		/**
		 * 获取父控件指针
		 */
		BaseControl* GetParent() {
			return m_parent;
		}

	protected:
		/**
		 * 父控件指针
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
		 * 控件在父控件的坐标
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
		virtual BaseControl* FindControlById(CString id) = 0;

	public:
		/**
		 * 输出控件的详细信息
		 */
		virtual void Dump() = 0;
	};

}