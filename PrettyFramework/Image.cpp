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
	
	void Image::OnPaint(Gdiplus::Graphics& graph)
	{
// 		Rect rcView = GetViewRect();
// 		if (!rcView.IsRectEmpty()) {
// 
// 			Rect rcMargined(rcView);
// 			rcMargined.DeflateRect(m_margin);
// 
// 			Rect rcIcon;
// 			Size szIcon = GetIconSize(m_bitmap);
// 
// 			if ((m_gravity & Gravity::Left) == Gravity::Left) {
// 				rcIcon.right = rcView.right - m_margin.right;
// 				rcIcon.left = rcView.left + m_margin.left;
// 			}
// 			
// 			if ((m_gravity & Gravity::CenterH) == Gravity::CenterH) {
// 
// 
// 				int offX = (rcMargined.Width() - szIcon.cx) / 2;
// 
// 				rcIcon.left = rcMargined.left + offX;
// 				rcIcon.right = rcIcon.left + szIcon.cx;
// 			}
// 
// 			if ((m_gravity & Gravity::Right) == Gravity::Right) {
// 				rcIcon.right = rcView.right - m_margin.right;
// 				rcIcon.left = rcView.left + m_margin.left;
// 			}
// 
// // 			if ((m_gravity & Gravity::Top) == Gravity::Top) {
// // 				nFormat |= DT_TOP;
// // 			}
// // 
// // 			if ((m_gravity & Gravity::CenterV) == Gravity::CenterV) {
// // 				nFormat |= DT_VCENTER;
// // 			}
// // 
// // 			if ((m_gravity & Gravity::Bottom) == Gravity::Bottom) {
// // 				nFormat |= DT_BOTTOM;
// // 			}
// 
// 
// 
// 			DrawIconEx(dc.GetSafeHdc(), rcMargined.left, rcMargined.top
// 				, m_bitmap, rcMargined.Width(), rcMargined.Height()
// 				, 0, nullptr, DI_NORMAL);
// 
// 			// dc.FrameRect(rcMargined, &CBrush(RGB(0, 0, 0))); 
// 			// dc.FrameRect(GetViewRect(), &CBrush(RGB(0, 0, 0)));
// 
// 		}
	}

}