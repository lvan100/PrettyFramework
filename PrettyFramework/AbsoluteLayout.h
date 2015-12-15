#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * 绝对布局，由控件自己设定显示区域
	 */
	class AbsoluteLayout : public LayoutControl
	{
	public:
		AbsoluteLayout(BaseControl* control = nullptr);
		virtual ~AbsoluteLayout();

	protected:
		/**
		 * 重新计算界面控件的布局
		 */
		virtual void RecalcLayout();
	};

}