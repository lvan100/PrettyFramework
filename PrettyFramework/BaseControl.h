#pragma once

#include <vector>
#include <memory>
using namespace std;

//
// �Զ���ؼ�ģ�ͣ��ο�Android����ģ�ͣ�������ͬ�����ɺϣ�
//

//
// �Զ���ؼ����Է�Ϊ����ؼ��Ͳ��ֿؼ����֡�һ�����ֿؼ�
// ���԰���������ֿؼ����߶������ؼ��������ݲ�ͬ�Ĺ���
// ���ӿؼ������ڸ��ؼ��ڡ����ֿؼ��ĸ��ؼ������ǲ��ֿؼ���
// Ҳ�����ǽ���ؼ�����һ������ؼ���ֻ�ܰ���һ�����ֿؼ���
//

//
// �������Ϲ����γɵ�XML���������ļ���ʽ���£�
// 
// <LayoutControl>
//		<LayoutControl>
//			<UserControl>
//				<LayoutControl />
//			</UserControl>
//		</LayoutControl>
//		<UserControl />
//		<LayoutControl />
//		<UserControl />
// </LayoutControl>
//

// 
// �ڵ�ǰ��ģ���У����ֿؼ����Բ����б������߿�Ƚ������ԡ�
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
	 * ������С�Ŀؼ���С
	 */
	void SetMinSize(CSize size) {
		m_min_size = size;
	}

	/**
	 * ��ȡ��С�Ŀؼ���С
	 */
	CSize GetMinSize() {
		return m_min_size;
	}

protected:
	/**
	 * ��С�Ŀؼ���С
	 */
	CSize m_min_size;

public:
	/**
	 * ���ÿؼ���λ��Ȩ��
	 */
	void SetWeight(float weight) {
		m_weight = weight;
	}

	/*
	 * ��ȡ�ؼ���λ��Ȩ��
	 */
	float GetWeight() {
		return m_weight;
	}

protected:
	/**
	 * �ؼ���Ȩ��
	 */
	float m_weight;

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
	virtual void OnButtonUp() = 0;

	/**
	 * ����ƶ�
	 */
	virtual void OnMouseMove() = 0;

	/**
	 * ��갴��
	 */
	virtual void OnButtonDown() = 0;

protected:
	/**
	 * ���¼������ؼ��Ĳ���
	 */
	virtual void RecalcLayout() = 0;
};