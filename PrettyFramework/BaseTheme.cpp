#include "stdafx.h"
#include "BaseTheme.h"

#include <memory>
using namespace std;

namespace PrettyFramework {

	/**
	 * 保存一个全局的界面主题对象
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

		button_text_clr0 = RGB(0, 0, 0);
		button_bk_color = RGB(240, 240, 240);
		button_border_clr = RGB(255, 255, 255);

		LOGFONT logFont = { 0 };
		GetGlobalData()->fontRegular.GetLogFont(&logFont);

		_tcscpy_s(logFont.lfFaceName, L"微软雅黑");

		logFont.lfHeight = -15;
		label_text_font.CreateFontIndirect(&logFont);

		logFont.lfHeight = -15;
		button_text_font.CreateFontIndirect(&logFont);
	}

	BaseTheme::~BaseTheme()
	{
	}

}