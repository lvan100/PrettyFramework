#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * 竖向线性布局，所有子控件共享父控件的宽度，
	 * 需要子控件的 Weight 和 MinHeight 属性配合。
	 */
	class VerticalLayout : public LayoutControl
	{
	public:
		VerticalLayout(BaseControl* control = nullptr);
		virtual ~VerticalLayout();

	protected:
		/**
		 * 重新计算界面控件的布局
		 */
		virtual void RecalcLayout();
	};

}