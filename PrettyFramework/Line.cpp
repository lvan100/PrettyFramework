#include "stdafx.h"
#include "Line.h"

namespace PrettyFramework {

	Line::Line()
	{}
	
	Line::~Line()
	{}
	
	void Line::Paint(Gdiplus::Graphics& graph)
	{
		// 
		// TODO �����������ƣ������򵥹��þͺã���̫���ӡ�
		// 

		Gdiplus::Pen pen(m_border_color, m_border_width);
		graph.DrawLine(&pen, m_pt_begin, m_pt_end);
	}

}