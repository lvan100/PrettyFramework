#pragma once

#include "BaseShape.h"

namespace PrettyFramework {

	/**
	 * �������������״�������������Ρ�
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
		 * ������״��ʼ��
		 */
		void SetBeginPoint(Gdiplus::PointF point) {
			m_pt_begin = point;
		}

		/**
		 * ��ȡ��״��ʼ��
		 */
		Gdiplus::PointF GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * ��״��ʼ��
		 */
		Gdiplus::PointF m_pt_begin;

	public:
		/**
		 * ������״������
		 */
		void SetEndPoint(Gdiplus::PointF point) {
			m_pt_end = point;
		}

		/**
		 * ��ȡ��״������
		 */
		Gdiplus::PointF GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * ��״������
		 */
		Gdiplus::PointF m_pt_end;
	};

}