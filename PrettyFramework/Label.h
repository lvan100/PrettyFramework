#pragma once

#include "LabelStyle.h"
#include "UserControl.h"

namespace PrettyFramework {

	/**
	 * ��ǩ�ؼ�
	 */
	class Label : public UserControl
	{
	public:
		Label(LayoutControl* parent);
		virtual ~Label();
		
		// 
		// 0.����
		// 

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
		 * ���ñ�ǩ��ʽ
		 */
		void SetStyle(shared_ptr<LabelStyle> style) {
			m_style = style;
		}

		/**
		 * ��ȡ��ǩ��ʽ
		 */
		shared_ptr<LabelStyle>& GetStyle() {
			return m_style;
		}

	protected:
		/**
		 * ��ǩ��ʽ
		 */
		shared_ptr<LabelStyle> m_style;

		// 
		// 1.��ͼ
		// 

	protected:
		/**
		 * ��������ǰ��
		 */
		virtual void OnPaint(CDC& dc);
	};

}