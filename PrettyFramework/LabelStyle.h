#pragma once

#include "VisualStyle.h"

namespace PrettyFramework {

	class Label;

	/**
	 * ��ǩ��ʽ
	 */
	class LabelStyle : public VisualStyle
	{
	public:
		LabelStyle(Label* label);
		virtual ~LabelStyle();

	public:
		/**
		 * ����ֻ��ʾ�����ı�
		 */
		void SetSingleLine(BOOL singleLine) {
			m_single_line = singleLine;
		}

		/**
		 * �Ƿ�ֻ��ʾ�����ı�
		 */
		BOOL IsSingleLine() {
			return m_single_line;
		}

	protected:
		/**
		 * ֻ��ʾ�����ı�
		 */
		BOOL m_single_line;

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

	protected:
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

	protected:
		/**
		 * ����
		 */
		CFont* m_font;

	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * �󶨵ı�ǩ�ؼ�
		 */
		Label* m_label;
	};

}