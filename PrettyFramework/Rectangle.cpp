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
		Gdiplus::RectF rect(m_pt_begin.X, m_pt_begin.Y
			, m_pt_end.X - m_pt_begin.X
			, m_pt_end.Y - m_pt_begin.Y);

		if (!m_border_null) {
			Gdiplus::Pen pen(m_border_color, m_border_width);
			pen.SetDashStyle(m_border_style);
			graph.DrawRectangle(&pen, rect);
		}

		DeflateRect(rect, m_border_width);

		if (!m_fill_null) {
			Gdiplus::SolidBrush brush(m_fill_color);
			graph.FillRectangle(&brush, rect);
		}
	}

}