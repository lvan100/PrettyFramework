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

	protected:
		/**
		 * 子类实现绘图接口
		 */
		virtual void Paint0(Gdiplus::Graphics& graph);
	};

}