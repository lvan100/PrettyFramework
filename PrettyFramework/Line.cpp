#include "stdafx.h"
#include "Line.h"

namespace PrettyFramework {

	Line::Line()
	{}
	
	Line::~Line()
	{}
	
	void Line::Paint(CDC& dc)
	{
		// 
		// 在WIN32绘图模式下，只有线条宽度为1时线条样式才起作用。
		// 

		CPen pen(m_border_style, m_border_width, m_border_color);

		CPen* pOldPen = dc.SelectObject(&pen);
		dc.MoveTo(m_pt_begin.x, m_pt_begin.y);
		dc.LineTo(m_pt_end.x, m_pt_end.y);
		dc.SelectObject(pOldPen);
	}

}