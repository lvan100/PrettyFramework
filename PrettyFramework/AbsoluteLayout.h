#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * ���Բ��֣���ȫ�ɿؼ��Լ��趨��ʾ������
	 */
	class AbsoluteLayout : public LayoutControl
	{
	public:
		AbsoluteLayout(BaseControl* control = nullptr);
		virtual ~AbsoluteLayout();

	protected:
		/**
		 * ���¼������ؼ��Ĳ���
		 */
		virtual void RecalcLayout();
	};

}