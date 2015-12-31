#pragma once

#include "TwoPointShape.h"

namespace PrettyFramework {

	/**
	 * 矩形，它的位置由起始点和终止点决定。
	 */
	class Rectangle : public TwoPointShape
	{
	public:
		Rectangle();
		virtual ~Rectangle();

	public:
		/**
		 * 定义视觉绘图接口
		 */
		virtual void Paint(Gdiplus::Graphics& graph);
	};

}