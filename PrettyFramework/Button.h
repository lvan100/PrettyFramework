#pragma once

#include "UserControl.h"

namespace PrettyFramework {

	/**
	 * ��ť�ؼ�
	 */
	class Button : public UserControl
	{
	public:
		Button(LayoutControl* parent);
		virtual ~Button();

		// 
		// 0.����
		// 

	public:
		/**
		 * ����ͼ��
		 */
		void SetBitmap(HICON bitmap) {
			m_bitmap = bitmap;
		}

		/**
		 * ��ȡͼ��
		 */
		HICON GetBitmap() {
			return m_bitmap;
		}

	protected:
		/**
		 * ͼ��
		 */
		HICON m_bitmap;

	public:
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
		 * ���ð�ť����¼���Ӧ
		 */
		void SetClickEvent(ClickEvent click) {
			m_click = click;
		}

	protected:
		/**
		 * ��ť����¼���Ӧ
		 */
		ClickEvent m_click;

		// 
		// 1.��ͼ
		// 

	protected:
		/**
		 * ��������ǰ��
		 */
		virtual void OnPaint(Gdiplus::Graphics& graph);
	
		// 
		// 2.�¼�
		// 

	protected:
		/**
		 * ��굯���¼����ӿؼ���Ӧ֮ǰ��
		 */
		virtual void OnPreviewMouseUp(EventParam& param);

		/**
		 * ��굯���¼����ӿؼ���Ӧ֮��
		 */
		virtual void OnMouseUp(EventParam& param);

		/**
		 * ����ƶ��¼����ӿؼ���Ӧ֮ǰ��
		 */
		virtual void OnPreviewMouseMove(EventParam& param);

		/**
		 * ����ƶ��¼����ӿؼ���Ӧ֮��
		 */
		virtual void OnMouseMove(EventParam& param);

		/**
		 * ��갴���¼����ӿؼ���Ӧ֮ǰ��
		 */
		virtual void OnPreviewMouseDown(EventParam& param);

		/**
		 * ��갴���¼����ӿؼ���Ӧ֮��
		 */
		virtual void OnMouseDown(EventParam& param);
	};

}