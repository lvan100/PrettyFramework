#pragma once

#include "TwoPointShape.h"

namespace PrettyFramework {

	/**
	 * ���Σ�����λ������ʼ�����ֹ�������
	 */
	class Rectangle : public TwoPointShape
	{
	public:
		Rectangle();
		virtual ~Rectangle();

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc);
	};

}