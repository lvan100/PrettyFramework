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
		 * �����Ӿ���ͼ�ӿ�
		 */
		virtual void Paint(Gdiplus::Graphics& graph);
	};

}