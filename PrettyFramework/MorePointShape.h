#pragma once

#include <vector>
using namespace std;

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * �ɶ���������״���������Ρ����ߡ�
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
		 * ������ĩβ��ӵ�
		 */
		void AddLastPoint(Gdiplus::PointF point) {
			m_points.push_back(point);
		}

	protected:
		/**
		 * ������
		 */
		vector<Gdiplus::PointF> m_points;
	};

}