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
		void SetBeginPoint(Point point) {
			m_pt_begin = point;
		}

		/**
		 * ��ȡ��״��ʼ��
		 */
		Point GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * ��״��ʼ��
		 */
		Point m_pt_begin;

	public:
		/**
		 * ������״������
		 */
		void SetEndPoint(Point point) {
			m_pt_end = point;
		}

		/**
		 * ��ȡ��״������
		 */
		Point GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * ��״������
		 */
		Point m_pt_end;
	};

}