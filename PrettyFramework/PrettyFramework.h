
// PrettyFramework.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPrettyFrameworkApp: 
// �йش����ʵ�֣������ PrettyFramework.cpp
//

class CPrettyFrameworkApp : public CWinApp
{
public:
	CPrettyFrameworkApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPrettyFrameworkApp theApp;