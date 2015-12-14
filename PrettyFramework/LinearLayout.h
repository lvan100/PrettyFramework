#pragma once

#include "LayoutControl.h"

/**
 * ���Բ���,���ؼ����Ե��Ų��ڸ��ؼ���ʾ�����ڣ�
 * ��Ϊ������������Բ��֡��������Բ�����Ҫ�ӿ�
 * ���� Weight �� MinWidth ������ϣ��������Բ�
 * ����Ҫ�ӿؼ��� Weight �� MinHeight �������. 
 */
class LinearLayout : public LayoutControl
{
public:
	LinearLayout(BaseControl* control = nullptr, BOOL horizontal = FALSE);
	virtual ~LinearLayout();

	/**
	 * �Ƿ�Ϊ���򲼾�
	 */
	BOOL IsHorizontal() {
		return m_horizontal;
	}

protected:
	/**
	 * �Ƿ��Ǻ��򲼾�
	 */
	BOOL m_horizontal;

protected:
	/**
	 * ���¼������ؼ��Ĳ���
	 */
	virtual void RecalcLayout();

protected:
	/**
	 * ���¼�����򲼾�
	 */
	void RecalcLayoutH();

	/**
	 * ���¼������򲼾�
	 */
	void RecalcLayoutV();
};