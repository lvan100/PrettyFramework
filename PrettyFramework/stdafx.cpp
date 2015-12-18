
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// PrettyFramework.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

CString GetModuleDir(HMODULE hModule/* = NULL*/)
{
	static CString strModulePath;

	if (PathFileExists(strModulePath.GetBuffer())) {
		return strModulePath;
	}

	TCHAR ext[_MAX_EXT];
	TCHAR dir[_MAX_DIR];
	TCHAR drive[_MAX_DRIVE];
	TCHAR fname[_MAX_FNAME];
	TCHAR szModuleFileName[MAX_PATH];

	if (NULL == GetModuleFileName(hModule, szModuleFileName, MAX_PATH)) {
		return _T("");
	}

	_wsplitpath_s(szModuleFileName, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);
	strModulePath = drive;
	strModulePath += dir;

	return strModulePath;
}