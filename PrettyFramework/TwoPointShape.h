#pragma once

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * 由两点决定的形状，如线条、矩形。
	 */
	class TwoPointShape : public Shape
	{
	public:
		TwoPointShape()
		{}

		virtual ~TwoPointShape()
		{}

	public:
		/**
		 * 设置形状起始点
		 */
		void SetBeginPoint(Gdiplus::PointF point) {
			m_pt_begin = point;
		}

		/**
		 * 获取形状起始点
		 */
		Gdiplus::PointF GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * 形状起始点
		 */
		Gdiplus::PointF m_pt_begin;

	public:
		/**
		 * 设置形状结束点
		 */
		void SetEndPoint(Gdiplus::PointF point) {
			m_pt_end = point;
		}

		/**
		 * 获取形状结束点
		 */
		Gdiplus::PointF GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * 形状结束点
		 */
		Gdiplus::PointF m_pt_end;
	};

}