#pragma once

#include "LayoutControl.h"

/**
 * 竖向布局,将控件竖向排布在父控件显示区域内
 * 需要子控件的 Weight 和 MinHeight 属性配合
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