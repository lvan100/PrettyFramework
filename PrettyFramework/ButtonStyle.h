#pragma once

#include "Constant.h"
#include "VisualStyle.h"

namespace PrettyFramework {

	class Button;

	/**
	 * 按钮样式
	 */
	class ButtonStyle : public VisualStyle
	{
	public:
		ButtonStyle(Button* button);
		virtual ~ButtonStyle();

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * 绑定的按钮控件
		 */
		Button* m_button;
	};

}