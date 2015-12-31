#include "stdafx.h"
#include "UIThread.h"
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
		if (parent != nullptr) {
			m_window = parent->GetWindow();
		}
		
		m_gravity = Gravity::Left | Gravity::Top;
	}

	BaseControl::~BaseControl()
	{
	}
	
	void BaseControl::Redraw()
	{
		GetUIThread().UpdateWindow(m_window);
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

	Gdiplus::RectF BaseControl::GetViewRect()
	{
		if (m_parent != nullptr) {
			Gdiplus::RectF rcView(rect_in_parent);
			Gdiplus::RectF rcParent = m_parent->GetViewRect();
			rcView.Offset(rcParent.GetLeft(), rcParent.GetTop());
			return rcView; /* ת��Ϊ�ؼ��ڴ�����ͼ��λ�� */
		} else {
			return rect_in_parent;
		}
	}

	BOOL BaseControl::HitTest(Gdiplus::PointF point)
	{
		return rect_in_parent.Contains(point);
	}

}