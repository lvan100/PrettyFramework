#pragma once

#include "BaseControl.h"
#include "TwoPointShape.h"

namespace PrettyFramework {

	/**
	 * 布局控件，计算子控件在父控件内的布局
	 */
	class LayoutControl : public BaseControl
	{
		friend class UserControl;

	public:
		LayoutControl(BaseControl* control);
		virtual ~LayoutControl();

		// 
		// 0.属性
		// 

	public:
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
		
		// 
		// 1.绘图
		// 

	protected:
		/**
		 * 通知控件需要进行绘图
		 */
		virtual void Paint(Gdiplus::Graphics& graph);

	public:
		/**
		 * 获取布局控件的背景对象
		 */
		shared_ptr<TwoPointShape>& GetBkgndShape() {
			return m_bkgnd_shape;
		}

	protected:
		/**
		 * 布局控件的背景对象
		 */
		shared_ptr<TwoPointShape> m_bkgnd_shape;
		
		// 
		// 2.事件
		// 

	protected:
		/**
		 * 鼠标弹起事件
		 */
		virtual void OnMouseUp(Gdiplus::PointF point);

		/**
		 * 鼠标移动事件
		 */
		virtual void OnMouseMove(Gdiplus::PointF point);

		/**
		 * 鼠标按下事件
		 */
		virtual void OnMouseDown(Gdiplus::PointF point);

	protected:
		/**
		 * 最近鼠标按下的子控件
		 */
		BaseControl* last_pressed;

		/**
		 * 最近获得热点的子控件
		 */
		BaseControl* last_hovered;

		/**
		 * 最近获得焦点的子控件
		 */
		BaseControl* last_focused;
		
		// 
		// 3.布局
		// 

	protected:
		/**
		 * 重新计算界面控件的布局
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
		 * 输出控件的详细信息
		 */
		virtual void Dump();
	};

}