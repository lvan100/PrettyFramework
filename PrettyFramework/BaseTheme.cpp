#include "stdafx.h"
#include "BaseTheme.h"

#include <memory>
using namespace std;

/**
 * ����һ��ȫ�ֵĽ����������
 */
shared_ptr<BaseTheme> theUITheme;

BaseTheme* GetUITheme() {
	if (theUITheme.get() == nullptr) {
		theUITheme = make_shared<BaseTheme>();
	}
	return theUITheme.get();
}

BaseTheme::BaseTheme()
{
	label_text_clr0 = RGB(0, 0, 0);
	label_bk_color = RGB(240, 240, 240);
	label_border_clr = RGB(255, 255, 255);

	LOGFONT logFont = { 0 };
	GetGlobalData()->fontRegular.GetLogFont(&logFont);

	_tcscpy_s(logFont.lfFaceName, L"΢���ź�");

	logFont.lfHeight = -15;
	label_text_font.CreateFontIndirect(&logFont);
}

BaseTheme::~BaseTheme()
{
}