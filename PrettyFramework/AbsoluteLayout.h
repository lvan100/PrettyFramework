#pragma once

#include "LayoutControl.h"

/**
 * ���Բ��֣��ɿؼ��Լ��趨��ʾ����
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
	virtual void RecalcLayout() {}
};