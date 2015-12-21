#pragma once

#include "Shape.h"

namespace PrettyFramework {

	/**
	 * �����㹹�ɵ���״�������������Ρ�
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
		void SetBeginPoint(CPoint point) {
			m_pt_begin = point;
		}

		/**
		 * ��ȡ��״��ʼ��
		 */
		CPoint GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * ��״��ʼ��
		 */
		CPoint m_pt_begin;

	public:
		/**
		 * ������״������
		 */
		void SetEndPoint(CPoint point) {
			m_pt_end = point;
		}

		/**
		 * ��ȡ��״������
		 */
		CPoint GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * ��״������
		 */
		CPoint m_pt_end;
	};

}