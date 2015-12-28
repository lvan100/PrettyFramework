#pragma once

#include "Constant.h"
#include "VisualStyle.h"

namespace PrettyFramework {

	class Button;

	/**
	 * ��ť��ʽ
	 */
	class ButtonStyle : public VisualStyle
	{
	public:
		ButtonStyle(Button* button);
		virtual ~ButtonStyle();

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * �󶨵İ�ť�ؼ�
		 */
		Button* m_button;
	};

}