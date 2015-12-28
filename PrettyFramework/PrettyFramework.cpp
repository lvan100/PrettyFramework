#include "stdafx.h"
#include "BaseTheme.h"
#include "SelfModule.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

CPrettyFrameworkApp::CPrettyFrameworkApp()
{
}

/**
 * 全局唯一的应用程序对象
 */
CPrettyFrameworkApp theApp;

/**
 * 全局的Shell管理器
 */
CShellManager theShellManager;

BOOL CPrettyFrameworkApp::InitInstance()
{
	CWinApp::InitInstance();

	// VS2015 通过函数初始化 afxGlobalData 变量.
	/* AFX_GLOBAL_DATA* p = */ GetGlobalData();

	CString strPath = GetModuleDir();
	strPath += _T("Resource\\Theme\\BaseTheme.xml");

	GetUITheme()->Reload(strPath);

	SelfModuleList::GetInstance()->Inits();
	
	CPrettyFrameworkDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

int CPrettyFrameworkApp::ExitInstance()
{
	SelfModuleList::GetInstance()->Uninits();

	// 如果在程序中使用了 CMFCButton 等控件
	// 需要手动释放 CMFCVisualManager 对象.
	CMFCVisualManager::DestroyInstance();

	return CWinApp::ExitInstance();
}