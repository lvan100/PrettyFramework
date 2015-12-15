#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	/**
	 * ����ؼ�
	 */
	class UserControl : public BaseControl
	{
	public:
		UserControl(LayoutControl* parent);
		virtual ~UserControl();

		/**
		 * ���ò��ֿؼ�
		 */
		void SetLayoutControl(shared_ptr<LayoutControl> layout) {
			m_layout = layout;
			RecalcLayout();
		}

		/**
		 * ��ȡ���ֿؼ�
		 */
		shared_ptr<LayoutControl>& GetLayoutControl() {
			return m_layout;
		}

	protected:
		/**
		 * ���ֿؼ���Ĭ��Ϊ���Բ��ֿؼ�
		 */
		shared_ptr<LayoutControl> m_layout;

	protected:
		/**
		 * ���¼������ؼ��Ĳ���
		 */
		virtual void RecalcLayout();

	public:
		/**
		 * ��ȡ������ɫ
		 */
		COLORREF GetBkColor() {
			return m_bk_color;
		}

		/**
		 * ���ñ�����ɫ
		 */
		void SetBkColor(COLORREF clr) {
			m_bk_color = clr;
		}

	protected:
		/**
		 * ������ɫ
		 */
		COLORREF m_bk_color;

	public:
		/**
		 * ��ȡ�߿���ɫ
		 */
		COLORREF GetBorderColor() {
			return m_border_color;
		}

		/**
		 * ���ñ߿���ɫ
		 */
		void SetBorderColor(COLORREF clr) {
			m_border_color = clr;
		}

	protected:
		/**
		 * �߿���ɫ
		 */
		COLORREF m_border_color;

	public:
		/**
		 * ���ÿؼ�Ϊ�հױ���
		 */
		void SetBkgndNull(BOOL isNull = TRUE) {
			is_bkgnd_null = isNull;
		}

		/**
		 * �Ƿ�����Ϊ�հױ���
		 */
		BOOL IsBkgndNull() {
			return is_bkgnd_null;
		}

	protected:
		/**
		 * �Ƿ�Ϊ�հױ���
		 */
		BOOL is_bkgnd_null;

	public:
		/**
		 * ���ÿؼ�Ϊ�ޱ߿�
		 */
		void SetBorderNull(BOOL isNull = TRUE) {
			is_border_null = isNull;
		}

		/**
		 * �Ƿ�����Ϊ�ޱ߿�
		 */
		BOOL IsBorderNull() {
			return is_border_null;
		}

	protected:
		/**
		 * �Ƿ�Ϊ�ޱ߿�
		 */
		BOOL is_border_null;

	public:
		/**
		 * ��ͼ
		 */
		virtual void Paint(CDC& dc);

	protected:
		/**
		 * ��������
		 */
		virtual void OnPaint(CDC& dc) = 0;

	public:
		/**
		 * ��굯��
		 */
		virtual void OnButtonUp();

		/**
		 * ����ƶ�
		 */
		virtual void OnMouseMove();

		/**
		 * ��갴��
		 */
		virtual void OnButtonDown();
	};

}