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
		 * �����Ӿ���ͼ�ӿ�
		 */
		virtual void Paint(Gdiplus::Graphics& graph);
	};

}