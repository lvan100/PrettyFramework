#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * �������Բ��֣������ӿؼ������ؼ��ĸ߶ȣ�
	 * ��Ҫ�ӿؼ��� Weight �� MinWidth ������ϡ�
	 */
	class HorizontalLayout : public LayoutControl
	{
	public:
		HorizontalLayout(BaseControl* control = nullptr);
		virtual ~HorizontalLayout();

	protected:
		/**
		 * ���¼������ؼ��Ĳ���
		 */
		virtual void RecalcLayout();
	};

}