#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * �������Բ��֣������ӿؼ������ؼ��Ŀ�ȣ�
	 * ��Ҫ�ӿؼ��� Weight �� MinHeight ������ϡ�
	 */
	class VerticalLayout : public LayoutControl
	{
	public:
		VerticalLayout(BaseControl* control = nullptr);
		virtual ~VerticalLayout();

	protected:
		/**
		 * ���¼������ؼ��Ĳ���
		 */
		virtual void RecalcLayout();
	};

}