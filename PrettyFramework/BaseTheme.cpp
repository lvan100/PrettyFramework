#include "stdafx.h"
#include "BaseTheme.h"

#include "Markup.h"

namespace PrettyFramework {

	/**
	 * ����һ��ȫ�ֵĽ����������
	 */
	shared_ptr<BaseTheme> theUITheme;

	/**
	 * �ṩһ�������������İ�װ����
	 */
	shared_ptr<BaseTheme>& GetUITheme() {
		if (theUITheme == nullptr) {
			theUITheme.reset(new BaseTheme());
		}
		return theUITheme;
	}

	BaseTheme::BaseTheme()
	{}

	BaseTheme::~BaseTheme()
	{}

	/**
	 * ���ַ����н�����ɫֵ
	 */
	static COLORREF GetColor(CString str) {
		if (str.GetAt(0) == '#') {
			long value = _tcstol(str.Mid(1), nullptr, 16);
			return RGB((value & 0xFF0000) >> 16
				, (value & 0x00FF00) >> 8
				, (value & 0x0000FF));
		} else {
			return RGB(0, 0, 0);
		}
	}

	void BaseTheme::Reload(CString file)
	{
		CMarkup xmlTheme;
		if (xmlTheme.Load(file)) {
			
			// ������ǩ�ؼ�����ɫ����
			while (xmlTheme.FindChildElem(_T("Label"))) {
				xmlTheme.IntoElem();

				while (xmlTheme.FindChildElem(_T("Text"))) {
					xmlTheme.IntoElem();

					while (xmlTheme.FindChildElem(_T("Color"))) {
						CString strColor = xmlTheme.GetChildAttrib(_T("Value"));
						label_text_clr = GetColor(strColor);
					}
					
					while (xmlTheme.FindChildElem(_T("Font"))) {
						LOGFONT logFont{ 0 };
						GetGlobalData()->fontRegular.GetLogFont(&logFont);





					}

					xmlTheme.OutOfElem();
				}


				xmlTheme.OutOfElem();
			}

			// ������ť�ؼ�����ɫ����
			while (xmlTheme.FindChildElem(_T("Button"))) {
				xmlTheme.IntoElem();


				xmlTheme.OutOfElem();
			}			
		}
	}

}