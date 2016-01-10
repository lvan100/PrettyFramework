#pragma once

#include <vector>
using namespace std;

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * �ɶ���������״�������Ρ����ߵȡ�
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
		 * ���������ӵ�
		 */
		void AddPoint(Point point) {
			m_points.push_back(point);
		}

	protected:
		/**
		 * ������
		 */
		vector<Point> m_points;
	};

}