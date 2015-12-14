#pragma once

#include "UserControl.h"

/**
 * 标签控件
 */
class Label : public UserControl
{
public:
	Label(LayoutControl* parent);
	virtual ~Label();

	/**
	 * 获取文本内容
	 */
	CString GetText() {
		return m_text;
	}

	/**
	 * 设置文本内容
	 */
	void SetText(CString text) {
		m_text = text;
	}

private:
	/**
	 * 文本内容
	 */
	CString m_text;

public:
	/**
	 * 设置文本颜色
	 */
	void SetTextColor(COLORREF clr) {
		m_text_color = clr;
	}

	/**
	 * 获取文本颜色
	 */
	COLORREF GetTextColor() {
		return m_text_color;
	}

private:
	/**
	 * 文本颜色
	 */
	COLORREF m_text_color;

public:
	/**
	 * 获取字体
	 */
	CFont* GetFont() {
		return m_font;
	}

	/**
	 * 设置字体
	 */
	void SetFont(CFont* font) {
		m_font = font;
	}

private:
	/**
	 * 字体
	 */
	CFont* m_font;

protected:
	/**
	 * 绘制自身当前层
	 */
	virtual void OnPaint(CDC& dc);
};