#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	// 
	// 界面控件的状态有五种：普通、热点、按
	// 下、焦点、禁用。
	// 

	/**
	 * 界面控件，包含一个同样大小的布局控件
	 */
	class UserControl : public BaseControl
	{
		friend class LayoutControl;

	public:
		UserControl(LayoutControl* parent);
		virtual ~UserControl();

		// 
		// 0.属性
		// 

	public:
		/**
		 * 设置布局控件，默认的不设置任何布局控件，减少尾节点数量
		 */
		void SetLayoutControl(shared_ptr<LayoutControl> layout) {
			m_layout = layout;
			RecalcLayout();
		}

		/**
		 * 获取布局控件，可以动态地向布局控件中增删控件
		 */
		shared_ptr<LayoutControl>& GetLayoutControl() {
			return m_layout;
		}

	protected:
		/**
		 * 布局控件，默认不设置任何布局控件
		 */
		shared_ptr<LayoutControl> m_layout;


		// 
		// 1.绘图
		// 

	protected:
		/**
		 * 通知控件需要进行绘图
		 */
		virtual void Paint(CDC& dc);

		/**
		 * 继承此控件的控件用来绘制自身
		 */
		virtual void OnPaint(CDC& dc) = 0;

		// 
		// 2.事件
		// 

	public:
		/**
		 * 是否处于按下状态
		 */
		BOOL IsPressed() {
			return ((m_state & State::Pressed) == State::Pressed);
		}

		/**
		 * 是否处于焦点状态
		 */
		BOOL IsFocused() {
			return ((m_state & State::Focused) == State::Focused);
		}

		/**
		 * 是否处于热点状态
		 */
		BOOL IsHovered() {
			return ((m_state & State::Hovered) == State::Hovered);
		}

	public:
		/**
		 * 是否处于禁用状态
		 */
		BOOL IsDisable() {
			return ((m_state & State::Disable) == State::Disable);
		}

		/**
		 * 设置控件是否处于禁用状态
		 */
		void SetDisable(BOOL disable);

	protected:
		/**
		 * 设置是否处于按下状态
		 */
		void SetPressed(BOOL pressed);

		/**
		 * 设置是否处于焦点状态
		 */
		void SetFocused(BOOL focused);

		/**
		 * 设置是否处于热点状态
		 */
		void SetHovered(BOOL hovered);

	protected:
		/**
		 * 控件状态，@State
		 */
		int m_state;

	protected:
		/**
		 * 鼠标弹起事件
		 */
		virtual void OnMouseUp(CPoint point);

		/**
		 * 鼠标移动事件
		 */
		virtual void OnMouseMove(CPoint point);

		/**
		 * 鼠标按下事件
		 */
		virtual void OnMouseDown(CPoint point);
		
	protected:
		/**
		 * 鼠标弹起事件（子控件响应之前）
		 */
		virtual void OnPreviewMouseUp(EventParam& param) {
			if (m_preview_mouse_up_event) {
				m_preview_mouse_up_event(param);
			}
		}

		/**
		 * 鼠标弹起事件（子控件响应之后）
		 */
		virtual void OnMouseUp(EventParam& param) {
			if (m_mouse_up_event) {
				m_mouse_up_event(param);
			}
		}

		/**
		 * 鼠标移动事件（子控件响应之前）
		 */
		virtual void OnPreviewMouseMove(EventParam& param) {
			if (m_preview_mouse_move_event) {
				m_preview_mouse_move_event(param);
			}
		}

		/**
		 * 鼠标移动事件（子控件响应之后）
		 */
		virtual void OnMouseMove(EventParam& param) {
			if (m_mouse_move_event) {
				m_mouse_move_event(param);
			}
		}

		/**
		 * 鼠标按下事件（子控件响应之前）
		 */
		virtual void OnPreviewMouseDown(EventParam& param) {
			if (m_preview_mouse_down_event) {
				m_preview_mouse_down_event(param);
			}
		}

		/**
		 * 鼠标按下事件（子控件响应之后）
		 */
		virtual void OnMouseDown(EventParam& param) {
			if (m_mouse_down_event) {
				m_mouse_down_event(param);
			}
		}

	public:
		/**
		 * 设置鼠标弹起事件（子控件响应之前）的事件响应
		 */
		void SetPreviewMouseUpEvent(MouseEvent event) {
			m_preview_mouse_up_event = event;
		}

		/**
		 * 设置鼠标弹起事件（子控件响应之后）的事件响应
		 */
		void SetMouseUpEvent(MouseEvent event) {
			m_mouse_up_event = event;
		}

		/**
		 * 设置鼠标移动事件（子控件响应之前）的事件响应
		 */
		void SetPreviewMouseMoveEvent(MouseEvent event) {
			m_preview_mouse_move_event = event;
		}

		/**
		 * 设置鼠标移动事件（子控件响应之后）的事件响应
		 */
		void SetMouseMoveEvent(MouseEvent event) {
			m_mouse_move_event = event;
		}

		/**
		 * 设置鼠标按下事件（子控件响应之前）的事件响应
		 */
		void SetPreviewMouseDownEvent(MouseEvent event) {
			m_preview_mouse_down_event = event;
		}

		/**
		 * 设置鼠标按下事件（子控件响应之后）的事件响应
		 */
		void SetMouseDownEvent(MouseEvent event) {
			m_mouse_down_event = event;
		}

	protected:
		/**
		 * 鼠标弹起事件（子控件响应之前）的事件响应
		 */
		MouseEvent m_preview_mouse_up_event;

		/**
		 * 设置鼠标弹起事件（子控件响应之后）的事件响应
		 */
		MouseEvent m_mouse_up_event;

		/**
		 * 设置鼠标移动事件（子控件响应之前）的事件响应
		 */
		MouseEvent m_preview_mouse_move_event;

		/**
		 * 设置鼠标移动事件（子控件响应之后）的事件响应
		 */
		MouseEvent m_mouse_move_event;

		/**
		 * 设置鼠标按下事件（子控件响应之前）的事件响应
		 */
		MouseEvent m_preview_mouse_down_event;

		/**
		 * 设置鼠标按下事件（子控件响应之后）的事件响应
		 */
		MouseEvent m_mouse_down_event;
		
		// 
		// 3.布局
		// 

	protected:
		/**
		 * 计算布局控件的子控件的布局
		 */
		virtual void RecalcLayout();

	public:
		/**
		 * 查找指定ID的控件，查找失败返回空指针
		 */
		virtual BaseControl* FindControlById(CString id);
		
		// 
		// 4.调试
		// 

	public:
		/**
		 * 输出详细信息
		 */
		virtual void Dump();
	};

}