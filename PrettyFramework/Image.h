#pragma once

#include "UserControl.h"

namespace PrettyFramework {

	/**
	 * ͼ��ؼ�
	 */
	class Image : public UserControl
	{
	public:
		Image(LayoutControl* parent);
		virtual ~Image();

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

	protected:
		/**
		 * ��������ǰ��
		 */
		virtual void OnPaint(CDC& dc);
	};

}