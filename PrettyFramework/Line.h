#pragma once

#include "TwoPointShape.h"

namespace PrettyFramework {

	/**
	 * ������λ������ʼ�����ֹ�������
	 */
	class Line : public TwoPointShape
	{
	public:
		Line();
		virtual ~Line();

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc);
	};

}