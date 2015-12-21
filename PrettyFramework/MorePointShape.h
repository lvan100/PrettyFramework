#pragma once

#include "Shape.h"

#include <vector>
using namespace std;

namespace PrettyFramework {

	/**
	 * 由多点构成的形状，如自由线条等。
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
		 * 添加点
		 */
		void AddPoint(CPoint point) {
			m_points.push_back(point);
		}

	protected:
		/**
		 * 点序列
		 */
		vector<CPoint> m_points;
	};

}