#pragma once

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

		// 
		// 1.��ͼ
		// 

	protected:
		/**
		 * ��������ǰ��
		 */
		virtual void OnPaint(Gdiplus::Graphics& graph);
	};

}