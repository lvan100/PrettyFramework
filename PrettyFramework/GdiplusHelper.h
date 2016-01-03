#pragma once

/**
 * Gdiplus 辅助类
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
	 * 保存图像到文件
	 */
	static BOOL SaveImageToFile(Gdiplus::Image* image, LPCTSTR path);
};