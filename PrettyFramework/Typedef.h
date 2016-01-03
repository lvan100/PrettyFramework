#pragma once

#include <array>
#include <functional>
using namespace std;

#include "Coordinate.h"

namespace PrettyFramework {

	/**
	 * 获取枚举的元素数量
	 */
	template<typename T>
	struct enum_size {
		const static int size = 0;
	};

	/**
	 * 对齐方式
	 */
	enum Gravity
	{
		Top = 0x0000,
		Left = 0x0000,
		CenterH = 0x0001,
		Right = 0x0002,
		CenterV = 0x0004,
		Bottom = 0x0008,
	};

	template<>
	struct enum_size<Gravity> {
		const static int size = 6;
	};

	/**
	 * 控件的状态
	 */
	enum State
	{
		Normal = 0x00,  // 普通
		Hovered = 0x01, // 热点
		Pressed = 0x02, // 按下
		Focused = 0x04, // 焦点
		Disable = 0x08, // 禁用
	};
	
	template<>
	struct enum_size<State> {
		const static int size = 5;
	};

	class UserControl;

	/**
	 * 定义鼠标事件的参数
	 */
	struct EventParam {

		/**
		 * 鼠标当前的坐标
		 */
		Point point;

		/**
		 * 是否吃掉这个事件
		 */
		BOOL will_eat_it;

		/**
		 * 鼠标事件的来源控件
		 */
		UserControl* control;
	};
	
	/**
	 * 定义鼠标事件的响应函数原型
	 */
	using MouseEvent = function<void(EventParam&)>;

	/**
	 * 定义鼠标点击事件的参数
	 */
	struct ClickParam {

		/**
		 * 点击事件的来源控件
		 */
		UserControl* control;
	};

	/**
	 * 定义鼠标点击事件响应函数原型
	 */
	using ClickEvent = function<void(ClickParam&)>;

	/**
	 * 缩小范围
	 */
	void DeflateRect(Gdiplus::RectF& rect, const Margin& margin) {
		rect.Height -= margin.Top + margin.Bottom;
		rect.Width -= margin.Left + margin.Right;
		rect.X += margin.Left;
		rect.Y += margin.Top;
	}

	/**
	 * 缩小范围
	 */
	void DeflateRect(Gdiplus::RectF& rect, float margin) {
		rect.Height -= margin * 2;
		rect.Width -= margin * 2;
		rect.X += margin;
		rect.Y += margin;
	}

	/**
	 * 转换为 Gdiplus 的坐标系
	 */
	Gdiplus::PointF toGdiplusPoint(Point point) {
		return Gdiplus::PointF(point.X, point.Y);
	}

	/**
	 * 转换为 GDI 的坐标系
	 */
	CPoint toGDIPoint(Point point) {
		return CPoint(point.X, point.Y);
	}

	/**
	 * 转换为 Gdiplus 的坐标系
	 */
	Gdiplus::RectF toGdiplusRect(Rect rect) {
		return Gdiplus::RectF(rect.Left, rect.Top, rect.Width, rect.Height);
	}

	/**
	 * 转换为 GDI 的坐标系
	 */
	CRect toGdiRect(Rect rect) {
		return CRect(rect.GetLeft(), rect.GetTop(), rect.GetRight(), rect.GetBottom());
	}

}