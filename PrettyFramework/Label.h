#pragma once

#include "UserControl.h"

/**
 * ��ǩ�ؼ�
 */
class Label : public UserControl
{
public:
	Label(LayoutControl* parent);
	virtual ~Label();

	/**
	 * ��ȡ�ı�����
	 */
	CString GetText() {
		return m_text;
	}

	/**
	 * �����ı�����
	 */
	void SetText(CString text) {
		m_text = text;
	}

private:
	/**
	 * �ı�����
	 */
	CString m_text;

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

protected:
	/**
	 * ��������ǰ��
	 */
	virtual void OnPaint(CDC& dc);
};