#pragma once

#include "UserControl.h"

namespace PrettyFramework {

	/**
	 * 图像控件
	 */
	class Image : public UserControl
	{
	public:
		Image(LayoutControl* parent);
		virtual ~Image();

		/**
		 * 设置图像
		 */
		void SetBitmap(HICON bitmap) {
			m_bitmap = bitmap;
		}

		/**
		 * 获取图像
		 */
		HICON GetBitmap() {
			return m_bitmap;
		}

	protected:
		/**
		 * 图像
		 */
		HICON m_bitmap;

	protected:
		/**
		 * 绘制自身当前层
		 */
		virtual void OnPaint(Gdiplus::Graphics& graph);
	};

}