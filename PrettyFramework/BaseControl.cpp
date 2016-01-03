#include "stdafx.h"
#include "BaseControl.h"

namespace PrettyFramework {

	BaseControl::BaseControl(BaseControl* parent)
		: m_weight(1.0f)
		, m_parent(parent)
		, m_window(nullptr)
		, m_auto_width(TRUE)
		, m_auto_height(TRUE)
	{
		if (parent != nullptr) {
			m_window = parent->GetWindow();
		}
		
		m_gravity = Gravity::Left | Gravity::Top;
	}

	BaseControl::~BaseControl()
	{
	}
	
	// 
	// �������ؿ��Ǻ�ʵ��������ʹ�õ����߳�ˢ�½��档
	// 

	void BaseControl::Redraw()
	{
#if 0
		CRect rect = toGdiRect(GetViewRect());
		InvalidateRect((HWND)m_window, rect, TRUE);
#else
		InvalidateRect((HWND)m_window, NULL, TRUE);
#endif
	}

	// 
	// ���������ʾ��ͼ��� @BaseControl::GetViewRect �ļ��㷽ʽ��
	// 
	// | (0,0) ������������������������������������������������ |
	// |                                                        |
	// |          | (80,40) | (0,0) �������������� |            |
	// |          |                                |            |
	// |          |     | (80,40) ���������� |     |            |
	// |          |     |                    |     |            |
	// |          |     |��������������������|     |            |
	// |          |                                |            |
	// |          |��������������������������������|            |
	// |                                                        |
	// |��������������������������������������������������������|
	// 

	Rect BaseControl::GetViewRect()
	{
		if (m_parent != nullptr) {
			Rect rcParent = m_parent->GetViewRect();
			Rect rcView = rect_in_parent;
			rcView.Left += rcParent.Left;
			rcView.Top += rcParent.Top;
			/* �ؼ��ڴ�����ͼ��λ�� */
			return rcView;
		} else {
			return rect_in_parent;
		}
	}

	BOOL BaseControl::HitTest(Point point)
	{
		return rect_in_parent.Contains(point);
	}

}