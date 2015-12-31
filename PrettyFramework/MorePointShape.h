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

		/**
		 * ɾ������ĩβ�ĵ�
		 */
		void DeleteLastPoint() {
			m_points.erase(m_points.end());
		}

	protected:
		/**
		 * ������
		 */
		vector<Gdiplus::PointF> m_points;
	};

}