#pragma once

#include <array>
using namespace std;

namespace PrettyFramework {

	/**
	 * 获取枚举的元素格式
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

	/**
	 * 定义控件状态的颜色数组
	 */
	using StateColor = array<COLORREF, enum_size<State>::size>;

}