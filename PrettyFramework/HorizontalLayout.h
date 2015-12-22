#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * 横向线性布局，所有子控件共享父控件的高度，
	 * 需要子控件的 Weight 和 MinWidth 属性配合。
	 */
	class HorizontalLayout : public LayoutControl
	{
	public:
		HorizontalLayout(BaseControl* control = nullptr);
		virtual ~HorizontalLayout();

	protected:
		/**
		 * 重新计算界面控件的布局
		 */
		virtual void RecalcLayout();
	};

}