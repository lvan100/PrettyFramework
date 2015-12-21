#pragma once

#include "TwoPointShape.h"

namespace PrettyFramework {

	/**
	 * 线条，位置由起始点和终止点决定。
	 */
	class Line : public TwoPointShape
	{
	public:
		Line();
		virtual ~Line();

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);
	};

}