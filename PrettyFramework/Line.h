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

	protected:
		/**
		 * ����ʵ�ֻ�ͼ�ӿ�
		 */
		virtual void Paint0(Gdiplus::Graphics& graph);
	};

}