#pragma once

#include "BaseShape.h"

#include "VerticalLayout.h"

using namespace PrettyFramework;

// 
// 和第三方控件集成的时候使用继承的方式貌似不错，但是如果要自己实现
// 窗口部件，委托的实现形式应该能更胜一筹吧。有机会试试看。先这样。
// 

/**
 * 测试对话框
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