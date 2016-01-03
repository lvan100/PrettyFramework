#pragma once

#include <vector>
using namespace std;

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * 由多点决定的形状，如三角形、曲线。
	 */
	class MorePointShape : public Shape
	{
	public:
		MorePointShape()
		{}

		virtual ~MorePointShape()
		{}

	public:
		/**
		 * 在序列末尾添加点
		 */
		void AddLastPoint(Gdiplus::PointF point) {
			m_points.push_back(point);
		}

	protected:
		/**
		 * 点序列
		 */
		vector<Gdiplus::PointF> m_points;
	};

}