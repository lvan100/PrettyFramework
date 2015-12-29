#pragma once

#include "Visual.h"

namespace PrettyFramework {

	class Label;

	/**
	 * 标签样式
	 */
	class LabelStyle : public Visual
	{
	public:
		LabelStyle(Label* label);
		virtual ~LabelStyle();

	public:
		/**
		 * 设置只显示单行文本
		 */
		void SetSingleLine(BOOL singleLine) {
			m_single_line = singleLine;
		}

		/**
		 * 是否只显示单行文本
		 */
		BOOL IsSingleLine() {
			return m_single_line;
		}

	protected:
		/**
		 * 只显示单行文本
		 */
		BOOL m_single_line;

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * 绑定的标签控件
		 */
		Label* m_label;
	};

}