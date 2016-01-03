#pragma once

namespace PrettyFramework {

	// 
	// ��������ϵ����ʹ����������ϵ��
	// 

	/**
	 * ����������ߡ���С�ȸ��
	 */
	class Size
	{
	public:
		Size(float width, float height)
			: Height(height)
			, Width(width)
		{}

		Size(const Size& size) {
			Height = size.Height;
			Width = size.Width;
		}

		Size() : Size(0.0f, 0.0f)
		{}

	public:
		/**
		 * ���ȣ���ȣ�
		 */
		float Width;

		/**
		 * ��ȣ��߶ȣ�
		 */
		float Height;
	};

	/**
	 * ������ĸ��
	 */
	class Point
	{
	public:
		Point(float x, float y)
			: X(x), Y(y)
		{}

		Point() : Point(0.0f, 0.0f)
		{}

		Point(const Point& point) {
			X = point.X;
			Y = point.Y;
		}

		Point operator= (Point point) {
			X = point.X;
			Y = point.Y;
			return *this;
		}

	public:
		/**
		 * X ����
		 */
		float X;

		/**
		 * Y ����
		 */
		float Y;
	};

	/**
	 * �������Σ���Χ�����򣩵ĸ��
	 */
	class Rect
	{
	public:
		static Rect From(float left, float top, float right, float bottom) {
			return Rect(left, top, right - left, bottom - top);
		}

		static Rect From(Point leftTop, Point rightBottom) {
			return From(leftTop.X, leftTop.Y, rightBottom.X, rightBottom.Y);
		}

		Rect(float left, float top, float width, float height)
			: Height(height)
			, Width(width)
			, Left(left)
			, Top(top)
		{}

		Rect() : Rect(0.0f, 0.0f, 0.0f, 0.0f)
		{}

		Rect(Point point, Size size) {
			Height = size.Height;
			Width = size.Width;
			Left = point.X;
			Top = point.Y;
		}

		Rect(const Rect& rect) {
			Height = rect.Height;
			Width = rect.Width;
			Left = rect.Left;
			Top = rect.Top;
		}

		BOOL Contains(float x, float y) {
			return x >= GetLeft() && x <= GetRight()
				&& y >= GetTop() && y <= GetBottom();
		}

		BOOL Contains(Point point) {
			return Contains(point.X, point.Y);
		}

		float GetBottom() {
			return Top + Height;
		}

		float GetRight() {
			return Left + Width;
		}

		float GetLeft() {
			return Left;
		}

		float GetTop() {
			return Top;
		}

	public:
		/**
		 * ��� Y ����
		 */
		float Top;

		/**
		 * ��� X ����
		 */
		float Left;

		/**
		 * ���εĳ��ȣ���ȣ�
		 */
		float Width;

		/**
		 * ���εĿ�ȣ��߶ȣ�
		 */
		float Height;
	};

	/**
	 * �����߾�ĸ��
	 */
	class Margin
	{
	public:
		Margin(float left, float top, float right, float bottom)
			: Bottom(bottom)
			, Right(right)
			, Left(left)
			, Top(top)
		{}

		Margin() : Margin(0.0f, 0.0f, 0.0f, 0.0f)
		{}

		Margin(float leftRight, float topBottom)
			: Bottom(topBottom)
			, Right(leftRight)
			, Left(leftRight)
			, Top(topBottom)
		{}

		Margin(float margin)
			: Bottom(margin)
			, Right(margin)
			, Left(margin)
			, Top(margin)
		{}

	public:
		/**
		 * �ϱ߾�
		 */
		float Top;

		/**
		 * ��߾�
		 */
		float Left;

		/**
		 * �ұ߾�
		 */
		float Right;

		/**
		 * �±߾�
		 */
		float Bottom;
	};

}