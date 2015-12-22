#pragma once

namespace PrettyFramework {

	// 
	// 设计原则：为了简单，只能实现为单根继承的系统。
	// 

	// 
	// 任何具有视觉效果的对象都需要继承 @VisualStyle
	// 接口，如基础控件、绘图形状等，都会继承此接口。
	// 

	/**
	 * 视觉样式接口
	 */
	class VisualStyle
	{
	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc) = 0;
	};

}