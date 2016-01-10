
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// PrettyFramework.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

static CString GetModuleDir(HMODULE hModule = NULL)
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

static CSize GetIconSize(HICON hIcon)
{
	if (hIcon == nullptr) {
		return CSize(0, 0);
	}

	ICONINFO iconInfo;
	GetIconInfo(hIcon, &iconInfo);

	BITMAP bitmap;
	GetObject(iconInfo.hbmColor, sizeof(BITMAP), &bitmap);

	DeleteObject(iconInfo.hbmColor);
	DeleteObject(iconInfo.hbmMask);

	return CSize(bitmap.bmWidth, bitmap.bmHeight);
}

static CString GetResourceDir()
{
	return GetModuleDir() + _T("Resource\\");
}