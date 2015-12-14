#include "stdafx.h"
#include "SelfModule.h"
#include "PrettyFramework.h"
#include "PrettyFrameworkDlg.h"

CPrettyFrameworkApp::CPrettyFrameworkApp()
{
}

/**
 * ȫ��Ψһ��Ӧ�ó������
 */
CPrettyFrameworkApp theApp;

/**
 * ȫ�ֵ�Shell������
 */
CShellManager theShellManager;

BOOL CPrettyFrameworkApp::InitInstance()
{
	CWinApp::InitInstance();

	// VS2015 ͨ��������ʼ�� afxGlobalData ����.
	/* AFX_GLOBAL_DATA* p = */ GetGlobalData();

	SelfModuleList::GetInstance()->Inits();

	CPrettyFrameworkDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

int CPrettyFrameworkApp::ExitInstance()
{
	SelfModuleList::GetInstance()->Uninits();

	// ����ڳ�����ʹ���� CMFCButton �ȿؼ�
	// ��Ҫ�ֶ��ͷ� CMFCVisualManager ����.
	CMFCVisualManager::DestroyInstance();

	return CWinApp::ExitInstance();
}