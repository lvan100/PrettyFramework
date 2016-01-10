#pragma once

#include "UserControl.h"

namespace PrettyFramework {

	/**
	 * 标签控件
	 */
	class Label : public UserControl
	{
	public:
		Label(LayoutControl* parent);
		virtual ~Label();
		
		// 
		// 0.属性
		// 

	public:
		/**
		 * 获取文本内容
		 */
		CString GetText() {
			return m_text;
		}

		/**
		 * 设置文本内容
		 */
		void SetText(CString text) {
			m_text = text;
		}

	private:
		/**
		 * 文本内容
		 */
		CString m_text;

		// 
		// 1.绘图
		// 

	protected:
		/**
		 * 绘制自身当前层
		 */
		virtual void OnPaint(Gdiplus::Graphics& graph);
	};

}