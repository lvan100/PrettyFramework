#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"

/**
 * Ӧ�ó�����
 */
class CPrettyFrameworkApp : public CWinApp
{
public:
	CPrettyFrameworkApp();

public:
	virtual BOOL InitInstance();
	virtual int  ExitInstance();
};

/**
 * ȫ��Ψһ��Ӧ�ó������
 */
extern CPrettyFrameworkApp theApp;

/**
 * ȫ�ֵ�Shell������
 */
extern CShellManager theShellManager;