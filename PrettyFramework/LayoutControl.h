#pragma once

#include "BaseControl.h"

/**
 * ���ֿؼ�
 */
class LayoutControl : public BaseControl
{
public:
	LayoutControl(BaseControl* control);
	virtual ~LayoutControl();

	/**
	 * ��ȡ�ӿؼ��б�
	 */
	vector<shared_ptr<BaseControl>>& GetChildren() {
		return m_children;
	}

	/**
	 * ����ӿؼ�����Ȼ�����ظ�����Լ�
	 */
	void AddChild(shared_ptr<BaseControl> child);

	/**
	 * �Ƴ��ӿؼ�����Ȼ�����ظ�ɾ���Լ�
	 */
	void RemoveChild(shared_ptr<BaseControl> child);

protected:
	/**
	 * �ӿؼ��б�
	 */
	vector<shared_ptr<BaseControl>> m_children;

public:
	/**
	 * ��ͼ
	 */
	virtual void Paint(CDC& dc);

public:
	/**
	 * ��굯��
	 */
	virtual void OnButtonUp();

	/**
	 * ����ƶ�
	 */
	virtual void OnMouseMove();

	/**
	 * ��갴��
	 */
	virtual void OnButtonDown();

protected:
	/**
	 * �����갴�µ��ӿؼ�
	 */
	shared_ptr<BaseControl> last_pressed;

	/**
	 * �������ȵ���ӿؼ�
	 */
	shared_ptr<BaseControl> last_hovered;

	/**
	 * �����ý�����ӿؼ�
	 */
	shared_ptr<BaseControl> last_focused;
};