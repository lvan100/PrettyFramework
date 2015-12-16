#pragma once

#include "LinearLayout.h"

using namespace PrettyFramework;

/**
 * ���ԶԻ���
 */
class CPrettyFrameworkDlg : public CDialogEx, private LinearLayout
{
public:
	CPrettyFrameworkDlg(CWnd* pParent = NULL);

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};