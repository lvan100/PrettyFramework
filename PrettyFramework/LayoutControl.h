#pragma once

#include "BaseControl.h"

namespace PrettyFramework {

	/**
	 * 布局控件
	 */
	class LayoutControl : public BaseControl
	{
		friend class UserControl;

	public:
		LayoutControl(BaseControl* control);
		virtual ~LayoutControl();

		/**
		 * 获取子控件列表
		 */
		vector<shared_ptr<BaseControl>>& GetChildren() {
			return m_children;
		}

		/**
		 * 添加子控件，当然不能重复添加自己
		 */
		void AddChild(shared_ptr<BaseControl> child);

		/**
		 * 移除子控件，当然不能重复删除自己
		 */
		void RemoveChild(shared_ptr<BaseControl> child);

	protected:
		/**
		 * 子控件列表
		 */
		vector<shared_ptr<BaseControl>> m_children;

	protected:
		/**
		 * 绘图
		 */
		virtual void Paint(CDC& dc);

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
	};

}