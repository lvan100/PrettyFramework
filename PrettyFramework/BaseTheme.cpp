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
		if (theUITheme == nullptr) {
			theUITheme = make_shared<BaseTheme>();
		}
		return theUITheme.get();
	}

	BaseTheme::BaseTheme()
	{
		label_text_clr = RGB(0, 0, 0);

		label_bk_color[0] = RGB(240, 240, 240);
		label_bk_color[1] = RGB(240, 240, 240);
		label_bk_color[2] = RGB(240, 240, 240);
		label_bk_color[3] = RGB(240, 240, 240);
		label_bk_color[4] = RGB(240, 240, 240);

		label_border_clr[0] = RGB(255, 255, 255);
		label_border_clr[1] = RGB(255, 255, 255);
		label_border_clr[2] = RGB(255, 255, 255);
		label_border_clr[3] = RGB(255, 255, 255);
		label_border_clr[4] = RGB(255, 255, 255);

		button_text_clr = RGB(0, 0, 0);

		button_bk_color[0] = RGB(240, 240, 240);
		button_bk_color[1] = RGB(253, 244, 191);
		button_bk_color[2] = RGB(255, 242, 157);
		button_bk_color[3] = RGB(253, 244, 191);
		button_bk_color[4] = RGB(240, 240, 240);

		button_border_clr[0] = RGB(255, 255, 255);
		button_border_clr[1] = RGB(97, 97, 97);
		button_border_clr[2] = RGB(255, 255, 255);
		button_border_clr[3] = RGB(97, 97, 97);
		button_border_clr[4] = RGB(255, 255, 255);

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