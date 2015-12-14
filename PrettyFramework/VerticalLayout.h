#pragma once

#include "LayoutControl.h"

/**
 * 竖向布局,将控件竖向均匀的排布在显示区域
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