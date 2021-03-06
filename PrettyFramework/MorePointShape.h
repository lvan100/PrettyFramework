#pragma once

#include <vector>
using namespace std;

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * 由多点决定的形状，三角形、曲线等。
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
		 * 向点序列添加点
		 */
		void AddPoint(Point point) {
			m_points.push_back(point);
		}

	protected:
		/**
		 * 点序列
		 */
		vector<Point> m_points;
	};

}