#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"

/**
 * 应用程序类
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
 * 全局唯一的应用程序对象
 */
extern CPrettyFrameworkApp theApp;

/**
 * 全局的Shell管理器
 */
extern CShellManager theShellManager;