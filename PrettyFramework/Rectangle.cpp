#include "stdafx.h"
#include "Rectangle.h"

namespace PrettyFramework {

	Rectangle::Rectangle()
	{}

	Rectangle::~Rectangle()
	{}

	void Rectangle::Paint(Gdiplus::Graphics& graph)
	{
// 		if (!m_border_null) {
// 			int halfWidth0 = (m_border_width + 0) / 2;
// 			int halfWidth1 = (m_border_width + 1) / 2;
// 
// 			Gdiplus::PointF ptBegin(m_pt_begin);
// 			ptBegin.Offset(halfWidth0, halfWidth0);
// 
// 			Gdiplus::PointF ptEnd(m_pt_end);
// 			ptEnd.Offset(-halfWidth1, -halfWidth1);
// 
// 			CPen pen(m_border_style, m_border_width, m_border_color);
// 			CPen* pOldPen = dc.SelectObject(&pen);
// 			dc.MoveTo(ptBegin.x, ptBegin.y);
// 			dc.LineTo(ptEnd.x, ptBegin.y); // Top			
// 			dc.MoveTo(ptBegin.x, ptBegin.y);
// 			dc.LineTo(ptBegin.x, ptEnd.y); // Left
// 			dc.MoveTo(ptEnd.x, ptBegin.y);
// 			dc.LineTo(ptEnd.x, ptEnd.y); // Right
// 			dc.MoveTo(ptBegin.x, ptEnd.y);
// 			dc.LineTo(ptEnd.x, ptEnd.y); // Bottom		
// 			dc.SelectObject(pOldPen);
// 		}
// 
// 		if (!m_fill_null) {
// 			Gdiplus::RectF rect(m_pt_begin, m_pt_end);
// 			rect.DeflateRect(m_border_width, m_border_width);
// 			dc.FillSolidRect(rect, m_fill_color);
// 		}
	}

}