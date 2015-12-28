#pragma once

#include <memory>
using namespace std;

namespace PrettyFramework {

	/**
	 * ������������
	 */
	class BaseTheme
	{
	public:
		BaseTheme();
		virtual ~BaseTheme();
		
		/**
		 * ���¼�����ɫ����
		 */
		void Reload(CString file);

	public:
		// ��ǩ�ؼ�������
		CFont label_text_font;

		// ��ǩ�ؼ��ı�����ɫ
		COLORREF label_bk_clr;

		// ��ǩ�ؼ���������ɫ
		COLORREF label_text_clr;

		// ��ǩ�ؼ��ı߿���ɫ
		COLORREF label_border_normal_clr;
		COLORREF label_border_hover_clr;
		COLORREF label_border_press_clr;
		COLORREF label_border_focus_clr;

		// ��ť�ؼ�������
		CFont button_text_font;

		// ��ť�ؼ���������ɫ
		COLORREF button_text_clr;

		// ��ť�ؼ��ı�����ɫ
		COLORREF button_bk_normal_clr;
		COLORREF button_bk_hover_clr;
		COLORREF button_bk_press_clr;
		COLORREF button_bk_focus_clr;

		// ��ť�ؼ��ı߿���ɫ
		COLORREF button_border_normal_clr;
		COLORREF button_border_hover_clr;
		COLORREF button_border_press_clr;
		COLORREF button_border_focus_clr;
	};

	/**
	 * ��ȡԤ��������ⷽ��
	 */
	shared_ptr<BaseTheme>& GetUITheme();

}