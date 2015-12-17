#include "stdafx.h"
#include "BaseControl.h"

namespace PrettyFramework {

	BaseControl::BaseControl(BaseControl* parent)
		: m_window(nullptr)
		, m_parent(parent)
		, m_weight(1.0f)
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