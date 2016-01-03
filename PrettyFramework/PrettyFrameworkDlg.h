#pragma once

#include "BaseShape.h"

#include "VerticalLayout.h"

using namespace PrettyFramework;

// 
// �͵������ؼ����ɵ�ʱ��ʹ�ü̳еķ�ʽò�Ʋ����������Ҫ�Լ�ʵ��
// ���ڲ�����ί�е�ʵ����ʽӦ���ܸ�ʤһ��ɡ��л������Կ�����������
// 

/**
 * ���ԶԻ���
 */
class CPrettyFrameworkDlg : public CDialogEx, private VerticalLayout
{
public:
	CPrettyFrameworkDlg(CWnd* pParent = NULL);

	void BtnCloseClicked(ClickParam& param);

protected:

	vector<shared_ptr<Shape>> m_shapes;

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};