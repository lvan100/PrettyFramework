#pragma once

#include "AbsoluteLayout.h"
#include "VerticalLayout.h"

/**
 * ≤‚ ‘∂‘ª∞øÚ
 */
class CPrettyFrameworkDlg : public CDialogEx, private AbsoluteLayout
{
public:
	CPrettyFrameworkDlg(CWnd* pParent = NULL);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	virtual BOOL OnInitDialog();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};