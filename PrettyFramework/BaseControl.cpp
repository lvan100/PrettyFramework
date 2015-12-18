#include "stdafx.h"
#include "BaseControl.h"

namespace PrettyFramework {

	BaseControl::BaseControl(BaseControl* parent)
		: m_weight(1.0f)
		, m_parent(parent)
		, m_fix_size(0, 0)
		, m_window(nullptr)
		, m_auto_width(TRUE)
		, m_auto_height(TRUE)
	{
		rect_in_parent.SetRectEmpty();

		if (parent != nullptr) {
			m_window = parent->GetWindow();
		}
		
		m_gravity = Gravity::Left | Gravity::Top;
	}

	BaseControl::~BaseControl()
	{
	}

	// 
	// Ŀǰ���ػ����û�в��á������򡱡���ʱ��ˢ�µķ�ʽ������
	// ʹ�� WIN32 API ����ԭ�����ڵ��ػ���ƣ�Ч��������ʱδ֪��
	// 
	
	void BaseControl::Redraw()
	{
		InvalidateRect((HWND)m_window, GetPaintRect(), TRUE);
	}

	CRect BaseControl::GetPaintRect()
	{
		if (m_parent != nullptr) {
			CRect rcPaint(rect_in_parent);
			CRect rcParent = m_parent->GetPaintRect();
			rcPaint.OffsetRect(rcParent.left, rcParent.top);
			return rcPaint; /* ת��Ϊ�ؼ��ڴ�����ͼ��λ�� */
		} else {
			return rect_in_parent;
		}
	}

}