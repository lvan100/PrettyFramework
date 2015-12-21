#pragma once

#include "Line.h"

namespace PrettyFramework {

	/**
	 * 矩形，偷偷地继承自线条类型。
	 */
	class Rectangle : public Line
	{
	public:
		Rectangle();
		virtual ~Rectangle();

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);
	};

}