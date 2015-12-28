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