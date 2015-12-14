#pragma once

#include <vector>
#include <memory>
using namespace std;

//
// �ؼ���Ϊ����ؼ��Ͳ��ֿؼ���һ�����ֿؼ����԰����������
// �ؼ����߶������ؼ���һ������ؼ�ֻ�ܰ���һ�����ֿؼ���
//

//
// ���ֿؼ����ܽ��������߼����¼���ֻ���������ؼ���������
//

/**
 * �����ؼ�
 */
class BaseControl
{
public:
	BaseControl(BaseControl* parent);
	virtual ~BaseControl();

	/**
	 * ��ȡ���ؼ�
	 */
	BaseControl* GetParent() {
		return m_parent;
	}

protected:
	/**
	 * ���ؼ�
	 */
	BaseControl* m_parent;

public:
	/**
	 * ���ÿؼ���ʾ����
	 */
	void SetRect(CRect rect) {
		rect_in_parent = rect;
		RecalcLayout();
	}

	/**
	 * ��ȡ�ؼ���ʾ����
	 */
	CRect GetRect() {
		return rect_in_parent;
	}

protected:
	/**
	 * �ڸ��ؼ�����ʾ����
	 */
	CRect rect_in_parent;

public:
	/**
	 * ��ȡ�ؼ��Ļ�ͼ����
	 */
	CRect GetPaintRect();

	/**
	 * ��ͼ
	 */
	virtual void Paint(CDC& dc) = 0;

public:
	/**
	 * ��굯��
	 */
	virtual void OnButtonUp() {}

	/**
	 * ����ƶ�
	 */
	virtual void OnMouseMove() {}

	/**
	 * ��갴��
	 */
	virtual void OnButtonDown() {}

protected:
	/**
	 * ���¼������ؼ��Ĳ���
	 */
	virtual void RecalcLayout() = 0;
};