#pragma once

#include "Visual.h"

namespace PrettyFramework {

	/**
	 * ��ͼ��״,���б߽���������ԡ�
	 */
	class Shape : public Visual
	{
	public:
		Shape()
			: m_border_width(0)
			, m_fill_null(FALSE)
			, m_border_null(FALSE)
			, m_border_style(PS_SOLID)
		{}

		virtual ~Shape() {}

	public:
		/**
		 * ���ñ߿�Ŀ��
		 */
		void SetBorderWidth(int width) {
			m_border_width = width;
		}

		/**
		 * ��ȡ�߿�Ŀ��
		 */
		int GetBorderWidth() {
			return m_border_width;
		}

	protected:
		/**
		 * �߿�Ŀ��
		 */
		int m_border_width;

	public:
		/**
		 * ���ñ߿����ɫ
		 */
		void SetBorderColor(COLORREF clr) {
			m_border_color = clr;
		}

		/**
		 * ��ȡ�߿����ɫ
		 */
		COLORREF GetBorderColor() {
			return m_border_color;
		}

	protected:
		/**
		 * �߿����ɫ
		 */
		COLORREF m_border_color;

	public:
		/**
		 * ���ñ߿����ʽ��@CDC::PenStyle
		 */
		void SetBorderStyle(int style) {
			m_border_style = style;
		}

		/**
		 * ��ȡ�߿����ʽ��@CDC::PenStyle
		 */
		int GetBorderStyle() {
			return m_border_style;
		}

	protected:
		/**
		 * �߿����ʽ��@CDC::PenStyle
		 */
		int m_border_style;

	public:
		/**
		 * ���ñ߿��Ƿ�Ϊ��
		 */
		void SetBorderNull(BOOL isNull) {
			m_border_null = isNull;
		}

		/**
		 * �߿��Ƿ�Ϊ��
		 */
		BOOL IsBorderNull() {
			return m_border_null;
		}

	protected:
		/**
		 * �߿��Ƿ�Ϊ��
		 */
		BOOL m_border_null;

	public:
		/**
		 * ����������ɫ
		 */
		void SetFillColor(COLORREF clr) {
			m_fill_color = clr;
		}

		/**
		 * ��ȡ������ɫ
		 */
		COLORREF GetFillColor() {
			return m_fill_color;
		}

	protected:
		/**
		 * ������ɫ
		 */
		COLORREF m_fill_color;

	public:
		/**
		 * ��������Ƿ�Ϊ��
		 */
		void SetFillNull(BOOL isNull) {
			m_fill_null = isNull;
		}

		/**
		 * ����Ƿ�Ϊ��
		 */
		BOOL IsFillNull() {
			return m_fill_null;
		}

	protected:
		/**
		 * ����Ƿ�Ϊ��
		 */
		BOOL m_fill_null;
	};

}