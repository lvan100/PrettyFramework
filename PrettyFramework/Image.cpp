#include "stdafx.h"

#include "Image.h"

namespace PrettyFramework {

	Image::Image(LayoutControl* parent)
		: UserControl(parent)
		, m_bitmap(nullptr)
	{
	}
	
	Image::~Image()
	{
	}
	
	void Image::OnPaint(CDC& dc)
	{
		CRect rcPaint = GetPaintRect();
		if (!rcPaint.IsRectEmpty()) {
			DrawIconEx(dc.GetSafeHdc(), rcPaint.left, rcPaint.top
				, m_bitmap, rcPaint.Width(), rcPaint.Height()
				, 0, nullptr, DI_NORMAL);
		}
	}

}