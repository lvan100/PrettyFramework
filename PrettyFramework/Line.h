#pragma once

#include "Shape.h"

namespace PrettyFramework {

	/**
	 * ���������������յ�����ԡ�
	 */
	class Line : public Shape
	{
	public:
		Line();
		virtual ~Line();

	public:
		/**
		 * ����������ʼ��
		 */
		void SetBeginPoint(CPoint point) {
			m_pt_begin = point;
		}

		/**
		 * ��ȡ������ʼ��
		 */
		CPoint GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * ������ʼ��
		 */
		CPoint m_pt_begin;

	public:
		/**
		 * ��������������
		 */
		void SetEndPoint(CPoint point) {
			m_pt_end = point;
		}

		/**
		 * ��ȡ����������
		 */
		CPoint GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * ����������
		 */
		CPoint m_pt_end;

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc);
	};

}