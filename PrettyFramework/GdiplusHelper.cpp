#include "stdafx.h"

#include "SelfModule.h"
#include "TypeSelect.h"

#include "GdiplusHelper.h"

#include <memory>
using namespace std;

/**
 * Gdiplus 库初始化和反初始化对象
 */
static std::unique_ptr<GdiplusHelper> theGdiplusHelper;

/**
 * 定义当前模块
 */
static DefModule _Module("GdiplusHelper"
	, ""
	, []$(Constructor)() {
	}, []$(Initializer)() {
		theGdiplusHelper.reset(new GdiplusHelper());
	}, []$(Uninitializer)() {
		theGdiplusHelper.release();
	}, []$(Destructor)() {
	});

GdiplusHelper::GdiplusHelper(void)
{
#if 0
	m_GdiplusStartupInput.SuppressBackgroundThread = TRUE;
	Gdiplus::GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartupInput, &m_GdiplusStartupOutput);
	m_GdiplusStartupOutput.NotificationHook(&m_GdiHookToken);
#else
	Gdiplus::GdiplusStartup(&m_GdiplusToken, &m_GdiplusStartupInput, NULL);
#endif
}

GdiplusHelper::~GdiplusHelper(void)
{
#if 0
	m_GdiplusStartupOutput.NotificationUnhook(m_GdiHookToken);
#endif

	Gdiplus::GdiplusShutdown(m_GdiplusToken);
}

BOOL GdiplusHelper::SaveImageToFile(Gdiplus::Image* image, LPCTSTR path)
{
	UINT nBytes;
	UINT nEncoders;
	Gdiplus::Status status;

	status = Gdiplus::GetImageEncodersSize(&nEncoders, &nBytes);
	if (status != Gdiplus::Ok) {
		return FALSE;
	}

	USES_CONVERSION_EX;
	Gdiplus::ImageCodecInfo* pEncoders = static_cast<Gdiplus::ImageCodecInfo*>
		(_ATL_SAFE_ALLOCA(nBytes, _ATL_SAFE_ALLOCA_DEF_THRESHOLD));

	if (pEncoders == NULL) {
		return FALSE;
	}

	status = Gdiplus::GetImageEncoders(nEncoders, nBytes, pEncoders);
	if (status != Gdiplus::Ok) {
		return FALSE;
	}

	CLSID clsidEncoder = CLSID_NULL;

	CString pszExtension(::PathFindExtension(path));

	for (UINT iCodec = 0; iCodec < nEncoders; iCodec++) {
		CString strExtensions(pEncoders[iCodec].FilenameExtension);

		int iStart = 0;
		do {
			CString strExtension = ::PathFindExtension(strExtensions.Tokenize(L";", iStart));
			if (iStart != -1) {
				if (strExtension.CompareNoCase(pszExtension) == 0) {
					clsidEncoder = pEncoders[iCodec].Clsid;
					break;
				}
			}
		} while (iStart != -1);

		if (clsidEncoder != CLSID_NULL) {
			break;
		}
	}

	if (clsidEncoder == CLSID_NULL) {
		return FALSE;
	}

	return (image->Save(path, &clsidEncoder) == Gdiplus::Ok);
}