#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * 绝对布局，完全由控件自己设定显示的坐标
	 */
	class AbsoluteLayout : public LayoutControl
	{
	public:
		AbsoluteLayout(BaseControl* control = nullptr);
		virtual ~AbsoluteLayout();
	};

}