#pragma once

#include <vector>
#include <memory>
using namespace std;

//
// 自定义控件模型（参考Android界面模型，如有雷同纯属巧合）
//

//
// 自定义控件可以分为界面控件和布局控件两种。一个布局控件
// 可以包含多个布局控件或者多个界面控件，并根据不同的规则
// 将子控件布局在父控件内。布局控件的父控件可以是布局控件，
// 也可以是界面控件。而一个界面控件则只能包含一个布局控件。
//

//
// 根据以上规则，形成的XML界面描述文件形式如下：
// 
// <LayoutControl>
//		<LayoutControl>
//			<UserControl>
//				<LayoutControl />
//			</UserControl>
//		</LayoutControl>
//		<UserControl />
//		<LayoutControl />
//		<UserControl />
// </LayoutControl>
//

// 
// 在当前的模型中，布局控件可以不具有背景、边框等界面属性。
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
	virtual void OnButtonUp() = 0;

	/**
	 * 鼠标移动
	 */
	virtual void OnMouseMove() = 0;

	/**
	 * 鼠标按下
	 */
	virtual void OnButtonDown() = 0;

protected:
	/**
	 * 重新计算界面控件的布局
	 */
	virtual void RecalcLayout() = 0;
};