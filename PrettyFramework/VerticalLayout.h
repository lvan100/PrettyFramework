#pragma once

#include "LayoutControl.h"

/**
 * ���򲼾�,���ؼ�������ȵ��Ų�����ʾ����
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