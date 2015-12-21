#pragma once

#include "Rectangle.h"
#include "BaseControl.h"

namespace PrettyFramework {

	/**
	 * 布局控件，只计算子控件的布局，没有界面
	 */
	class LayoutControl : public BaseControl
	{
		friend class UserControl;

	public:
		LayoutControl(BaseControl* control);
		virtual ~LayoutControl();

		/**
		 * 添加子控件，当然不能重复地添加自己
		 */
		void AddChild(shared_ptr<BaseControl> child);

		/**
		 * 移除子控件，当然不能重复地删除自己
		 */
		void RemoveChild(shared_ptr<BaseControl> child);

		/**
		 * 获取子控件列表
		 */
		vector<shared_ptr<BaseControl>>& GetChildren() {
			return m_children;
		}

	protected:
		/**
		 * 子控件列表
		 */
		vector<shared_ptr<BaseControl>> m_children;

	protected:
		/**
		 * 查找指定ID的控件，查找失败返回空指针
		 */
		virtual BaseControl* FindControlById(CString id);

	protected:
		/**
		 * 通知控件需要进行绘图
		 */
		virtual void Paint(CDC& dc);

	public:
		/**
		 * 获取矩形背景对象
		 */
		Rectangle& GetBkRectangle() {
			return m_bkgnd_rectangle;
		}

	protected:
		/**
		 * 控件的矩形背景
		 */
		Rectangle m_bkgnd_rectangle;

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
		 * 最近鼠标按下的子控件
		 */
		shared_ptr<BaseControl> last_pressed;

		/**
		 * 最近获得热点的子控件
		 */
		shared_ptr<BaseControl> last_hovered;

		/**
		 * 最近获得焦点的子控件
		 */
		shared_ptr<BaseControl> last_focused;

	protected:
		/**
		 * 重新计算界面控件的布局
		 */
		virtual void RecalcLayout();

	public:
		/**
		 * 输出控件的详细信息
		 */
		virtual void Dump();
	};

}