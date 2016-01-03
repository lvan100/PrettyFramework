#pragma once

/**
 * Gdiplus ������
 */
class GdiplusHelper
{
public:
	GdiplusHelper(void);
	~GdiplusHelper(void);

private:
	ULONG_PTR m_GdiplusToken;
	ULONG_PTR m_GdiHookToken;

	Gdiplus::GdiplusStartupInput m_GdiplusStartupInput;
	Gdiplus::GdiplusStartupOutput m_GdiplusStartupOutput;

public:
	/**
	 * ����ͼ���ļ�
	 */
	static BOOL SaveImageToFile(Gdiplus::Image* image, LPCTSTR path);
};