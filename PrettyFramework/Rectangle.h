#pragma once

#include "Line.h"

namespace PrettyFramework {

	/**
	 * ���Σ�͵͵�ؼ̳����������͡�
	 */
	class Rectangle : public Line
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