#pragma once

#include <array>
#include <functional>
using namespace std;

#include "Coordinate.h"

namespace PrettyFramework {

	/**
	 * ��ȡö�ٵ�Ԫ������
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

	class UserControl;

	/**
	 * ��������¼��Ĳ���
	 */
	struct EventParam {

		/**
		 * ��굱ǰ������
		 */
		Point point;

		/**
		 * �Ƿ�Ե�����¼�
		 */
		BOOL will_eat_it;

		/**
		 * ����¼�����Դ�ؼ�
		 */
		UserControl* control;
	};
	
	/**
	 * ��������¼�����Ӧ����ԭ��
	 */
	using MouseEvent = function<void(EventParam&)>;

	/**
	 * ����������¼��Ĳ���
	 */
	struct ClickParam {

		/**
		 * ����¼�����Դ�ؼ�
		 */
		UserControl* control;
	};

	/**
	 * ����������¼���Ӧ����ԭ��
	 */
	using ClickEvent = function<void(ClickParam&)>;

	/**
	 * ��С��Χ
	 */
	void DeflateRect(Gdiplus::RectF& rect, const Margin& margin) {
		rect.Height -= margin.Top + margin.Bottom;
		rect.Width -= margin.Left + margin.Right;
		rect.X += margin.Left;
		rect.Y += margin.Top;
	}

	/**
	 * ��С��Χ
	 */
	void DeflateRect(Gdiplus::RectF& rect, float margin) {
		rect.Height -= margin * 2;
		rect.Width -= margin * 2;
		rect.X += margin;
		rect.Y += margin;
	}

	/**
	 * ת��Ϊ Gdiplus ������ϵ
	 */
	Gdiplus::PointF toGdiplusPoint(Point point) {
		return Gdiplus::PointF(point.X, point.Y);
	}

	/**
	 * ת��Ϊ GDI ������ϵ
	 */
	CPoint toGDIPoint(Point point) {
		return CPoint(point.X, point.Y);
	}

	/**
	 * ת��Ϊ Gdiplus ������ϵ
	 */
	Gdiplus::RectF toGdiplusRect(Rect rect) {
		return Gdiplus::RectF(rect.Left, rect.Top, rect.Width, rect.Height);
	}

	/**
	 * ת��Ϊ GDI ������ϵ
	 */
	CRect toGdiRect(Rect rect) {
		return CRect(rect.GetLeft(), rect.GetTop(), rect.GetRight(), rect.GetBottom());
	}

}