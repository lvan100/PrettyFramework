#pragma once

#include <array>
#include <functional>
using namespace std;

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
		 * 是否吃掉这个事件
		 */
		BOOL will_eat_it;

		/**
		 * 鼠标当前的坐标
		 */
		Gdiplus::PointF point;

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

}