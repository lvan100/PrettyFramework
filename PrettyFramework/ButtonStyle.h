#pragma once

#include "Visual.h"
#include "Typedef.h"

namespace PrettyFramework {

	class Button;

	/**
	 * ��ť��ʽ
	 */
	class ButtonStyle : public Visual
	{
	public:
		ButtonStyle(Button* button);
		virtual ~ButtonStyle();

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(Gdiplus::Graphics& graph);

	protected:
		/**
		 * �󶨵İ�ť�ؼ�
		 */
		Button* m_button;
	};

}