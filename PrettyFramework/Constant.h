#pragma once

#include <array>
using namespace std;

namespace PrettyFramework {

	/**
	 * ��ȡö�ٵ�Ԫ�ظ�ʽ
	 */
	template<typename T>
	struct enum_size {
		const static int size = 0;
	};

	/**
	 * ���뷽ʽ
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
	 * �ؼ���״̬
	 */
	enum State
	{
		Normal = 0x00,  // ��ͨ
		Hovered = 0x01, // �ȵ�
		Pressed = 0x02, // ����
		Focused = 0x04, // ����
		Disable = 0x08, // ����
	};
	
	template<>
	struct enum_size<State> {
		const static int size = 5;
	};

	/**
	 * ����ؼ�״̬����ɫ����
	 */
	using StateColor = array<COLORREF, enum_size<State>::size>;

}