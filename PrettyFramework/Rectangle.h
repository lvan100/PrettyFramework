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

	protected:
		/**
		 * ����ʵ�ֻ�ͼ�ӿ�
		 */
		virtual void Paint0(Gdiplus::Graphics& graph);
	};

}