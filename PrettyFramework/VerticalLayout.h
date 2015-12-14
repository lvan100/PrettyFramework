#pragma once

#include "LayoutControl.h"

/**
 * ���򲼾�,���ؼ������Ų��ڸ��ؼ���ʾ������
 * ��Ҫ�ӿؼ��� Weight �� MinHeight �������
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