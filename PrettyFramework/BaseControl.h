#pragma once

#include <vector>
#include <memory>
using namespace std;

//
// 控件分为界面控件和布局控件，一个布局控件可以包含多个布局
// 控件或者多个界面控件，一个界面控件只能包含一个布局控件。
//

//
// 布局控件不能接收鼠标或者键盘事件；只能做基础控件的容器。
//

/**
 * 基础控件
 */
class BaseControl
{
public:
	BaseControl(BaseControl* parent);
	virtual ~BaseControl();

	/**
	 * 获取父控件
	 */
	BaseControl* GetParent() {
		return m_parent;
	}

protected:
	/**
	 * 父控件
	 */
	BaseControl* m_parent;

public:
	/**
	 * 设置控件显示区域
	 */
	void SetRect(CRect rect) {
		rect_in_parent = rect;
		RecalcLayout();
	}

	/**
	 * 获取控件显示区域
	 */
	CRect GetRect() {
		return rect_in_parent;
	}

protected:
	/**
	 * 在父控件的显示区域
	 */
	CRect rect_in_parent;

public:
	/**
	 * 获取控件的绘图坐标
	 */
	CRect GetPaintRect();

	/**
	 * 绘图
	 */
	virtual void Paint(CDC& dc) = 0;

public:
	/**
	 * 鼠标弹起
	 */
	virtual void OnButtonUp() {}

	/**
	 * 鼠标移动
	 */
	virtual void OnMouseMove() {}

	/**
	 * 鼠标按下
	 */
	virtual void OnButtonDown() {}

protected:
	/**
	 * 重新计算界面控件的布局
	 */
	virtual void RecalcLayout() = 0;
};