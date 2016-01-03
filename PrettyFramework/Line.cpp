#include "stdafx.h"

#include "Line.h"
#include "Typedef.h"

namespace PrettyFramework {

	Line::Line()
	{}
	
	Line::~Line()
	{}
	
	void Line::Paint(Gdiplus::Graphics& graph)
	{
		Gdiplus::Pen pen(m_border_color, m_border_width);
		pen.SetDashStyle(m_border_style);

		graph.DrawLine(&pen, toGdiplusPoint(m_pt_begin)
			, toGdiplusPoint(m_pt_end));
	}

}