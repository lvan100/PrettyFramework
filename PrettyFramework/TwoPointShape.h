#pragma once

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * 由两点决定的形状，线条、矩形等。
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
		void SetBeginPoint(Point point) {
			m_pt_begin = point;
		}

		/**
		 * 获取形状起始点
		 */
		Point GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * 形状起始点
		 */
		Point m_pt_begin;

	public:
		/**
		 * 设置形状结束点
		 */
		void SetEndPoint(Point point) {
			m_pt_end = point;
		}

		/**
		 * 获取形状结束点
		 */
		Point GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * 形状结束点
		 */
		Point m_pt_end;
	};

}