#pragma once

#include "Shape.h"

#include <vector>
using namespace std;

namespace PrettyFramework {

	/**
	 * �ɶ�㹹�ɵ���״�������������ȡ�
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
		 * ��ӵ�
		 */
		void AddPoint(CPoint point) {
			m_points.push_back(point);
		}

	protected:
		/**
		 * ������
		 */
		vector<CPoint> m_points;
	};

}