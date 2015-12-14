#pragma once

#include "LayoutControl.h"

/**
 * 线性布局,将控件线性的排布在父控件显示区域内，
 * 分为横向和竖向线性布局。横向线性布局需要子控
 * 件的 Weight 和 MinWidth 属性配合；竖向线性布
 * 局需要子控件的 Weight 和 MinHeight 属性配合. 
 */
class LinearLayout : public LayoutControl
{
public:
	LinearLayout(BaseControl* control = nullptr, BOOL horizontal = FALSE);
	virtual ~LinearLayout();

	/**
	 * 是否为横向布局
	 */
	BOOL IsHorizontal() {
		return m_horizontal;
	}

protected:
	/**
	 * 是否是横向布局
	 */
	BOOL m_horizontal;

protected:
	/**
	 * 重新计算界面控件的布局
	 */
	virtual void RecalcLayout();

protected:
	/**
	 * 重新计算横向布局
	 */
	void RecalcLayoutH();

	/**
	 * 重新计算竖向布局
	 */
	void RecalcLayoutV();
};