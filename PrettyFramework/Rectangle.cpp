#include "stdafx.h"

#include "Typedef.h"
#include "Rectangle.h"

namespace PrettyFramework {

	Rectangle::Rectangle()
	{}

	Rectangle::~Rectangle()
	{}

	void Rectangle::Paint(Gdiplus::Graphics& graph)
	{
		// 
		// 线条在绘制的时候以中心线向两侧延伸1/2宽度。
		// 

		float halfBorderWidth = m_border_width / 2;

		Gdiplus::PointF ptBegin;
		ptBegin.X = m_pt_begin.X + halfBorderWidth;
		ptBegin.Y = m_pt_begin.Y + halfBorderWidth;

		Gdiplus::SizeF szRect;
		szRect.Width = m_pt_end.X - m_pt_begin.X - m_border_width;
		szRect.Height = m_pt_end.Y - m_pt_begin.Y - m_border_width;

		Gdiplus::RectF rect(ptBegin, szRect);

		if (!m_border_null) {

			Gdiplus::Pen pen(m_border_color);
			pen.SetDashStyle(m_border_style);
			pen.SetWidth(m_border_width);

			pen.SetLineJoin(Gdiplus::LineJoin::LineJoinMiter);
			pen.SetStartCap(Gdiplus::LineCap::LineCapFlat);
			pen.SetDashCap(Gdiplus::DashCap::DashCapFlat);
			pen.SetEndCap(Gdiplus::LineCap::LineCapFlat);

			graph.DrawRectangle(&pen, rect);
		}

		DeflateRect(rect, halfBorderWidth);

		if (!m_fill_null) {
			Gdiplus::SolidBrush brush(m_fill_color);
			graph.FillRectangle(&brush, rect);
		}
	}

}