#include "stdafx.h"

#include "Line.h"
#include "Typedef.h"

namespace PrettyFramework {

	Line::Line()
	{}
	
	Line::~Line()
	{}
	
	void Line::Paint0(Gdiplus::Graphics& graph)
	{
		// 
		// �����ڻ��Ƶ�ʱ��������������������1/2��ȡ�
		// 

		Gdiplus::Pen pen(m_border_color);
		pen.SetDashStyle(m_border_style);
		pen.SetWidth(m_border_width);

		pen.SetStartCap(Gdiplus::LineCap::LineCapFlat);
		pen.SetDashCap(Gdiplus::DashCap::DashCapFlat);
		pen.SetEndCap(Gdiplus::LineCap::LineCapFlat);

		auto& ptB = toGdiplusPoint(m_pt_begin);
		auto& ptE = toGdiplusPoint(m_pt_end);
		graph.DrawLine(&pen, ptB, ptE);
	}

}