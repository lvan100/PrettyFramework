#pragma once

#include "Constant.h"
#include "VisualStyle.h"

namespace PrettyFramework {

	class Button;

	/**
	 * ��ť��ʽ
	 */
	class ButtonStyle : public VisualStyle
	{
	public:
		ButtonStyle(Button* button);
		virtual ~ButtonStyle();

	public:
		/**
		 * �����ı���ɫ
		 */
		void SetTextColor(COLORREF clr) {
			m_text_color = clr;
		}

		/**
		 * ��ȡ�ı���ɫ
		 */
		COLORREF GetTextColor() {
			return m_text_color;
		}

	private:
		/**
		 * �ı���ɫ
		 */
		COLORREF m_text_color;

	public:
		/**
		 * ��ȡ����
		 */
		CFont* GetFont() {
			return m_font;
		}

		/**
		 * ��������
		 */
		void SetFont(CFont* font) {
			m_font = font;
		}

	private:
		/**
		 * ����
		 */
		CFont* m_font;

	public:
		/**
		 * ��ȡ��ͬ״̬�µı�����ɫ
		 */
		COLORREF GetBkColor(State state);

		/**
		 * ���ò�ͬ״̬�µı�����ɫ
		 */
		void SetBkColor(State state, COLORREF clr);

	protected:
		/**
		 * �ؼ���ͬ״̬�µı�����ɫ
		 */
		StateColor m_bk_color;

	public:
		/**
		 * ��ȡ��ͬ״̬�µı߿���ɫ
		 */
		COLORREF GetBorderColor(State state);

		/**
		 * ���ò�ͬ״̬�µı߿���ɫ
		 */
		void SetBorderColor(State state, COLORREF clr);

	protected:
		/**
		 * �ؼ���ͬ״̬�µı߿���ɫ
		 */
		StateColor m_border_color;

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * �󶨵İ�ť�ؼ�
		 */
		Button* m_button;
	};

}