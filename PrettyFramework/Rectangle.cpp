#include "stdafx.h"
#include "Rectangle.h"

namespace PrettyFramework {

	Rectangle::Rectangle()
	{}

	Rectangle::~Rectangle()
	{}

	void Rectangle::Paint(Gdiplus::Graphics& graph)
	{
		Gdiplus::SizeF size(m_pt_end.X - m_pt_begin.X
			, m_pt_end.Y - m_pt_begin.Y);

		Gdiplus::RectF rect(m_pt_begin, size);

		// 
		// TODO ���ƾ��λ��ƣ������򵥹��þͺã���̫���ӡ�
		// 

		if (!m_border_null) {
			Gdiplus::Pen pen(m_border_color, m_border_width);
			graph.DrawRectangle(&pen, rect);
		}

		if (!m_fill_null) {
			Gdiplus::SolidBrush brush(m_fill_color);
			graph.FillRectangle(&brush, rect);
		}
	}

}