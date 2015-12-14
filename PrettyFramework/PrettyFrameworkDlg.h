#pragma once

#include "LinearLayout.h"

/**
 * ≤‚ ‘∂‘ª∞øÚ
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
};