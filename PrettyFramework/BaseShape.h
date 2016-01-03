#pragma once

#include "Visual.h"

namespace PrettyFramework {

	/**
	 * ��ͼ��״,���б߽���������ԡ�
	 */
	class Shape : public Visual
	{
	public:
		Shape() : m_border_width(0)
			, m_border_null(FALSE)
			, m_fill_null(FALSE)
		{
			m_border_style = Gdiplus::DashStyle::DashStyleSolid;
		}

		virtual ~Shape() {}

	public:
		/**
		 * ���ñ߿�Ŀ��
		 */
		void SetBorderWidth(float width) {
			m_border_width = width;
		}

		/**
		 * ��ȡ�߿�Ŀ��
		 */
		float GetBorderWidth() {
			return m_border_width;
		}

	protected:
		/**
		 * �߿�Ŀ��
		 */
		float m_border_width;

	public:
		/**
		 * ���ñ߿����ɫ
		 */
		void SetBorderColor(Gdiplus::Color clr) {
			m_border_color = clr;
		}

		/**
		 * ��ȡ�߿����ɫ
		 */
		Gdiplus::Color GetBorderColor() {
			return m_border_color;
		}

	protected:
		/**
		 * �߿����ɫ
		 */
		Gdiplus::Color m_border_color;

	public:
		/**
		 * ���ñ߿����ʽ��@Gdiplus::DashStyle
		 */
		void SetBorderStyle(Gdiplus::DashStyle style) {
			m_border_style = style;
		}

		/**
		 * ��ȡ�߿����ʽ��@Gdiplus::DashStyle
		 */
		Gdiplus::DashStyle GetBorderStyle() {
			return m_border_style;
		}

	protected:
		/**
		 * �߿����ʽ��@Gdiplus::DashStyle
		 */
		Gdiplus::DashStyle m_border_style;

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
		void SetFillColor(Gdiplus::Color clr) {
			m_fill_color = clr;
		}

		/**
		 * ��ȡ������ɫ
		 */
		Gdiplus::Color GetFillColor() {
			return m_fill_color;
		}

	protected:
		/**
		 * ������ɫ
		 */
		Gdiplus::Color m_fill_color;

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