#pragma once

#include "Shape.h"

#include <vector>
using namespace std;

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
		void AddLastPoint(CPoint point) {
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
		vector<CPoint> m_points;
	};

}