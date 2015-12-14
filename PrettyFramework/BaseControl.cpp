#include "stdafx.h"
#include "BaseControl.h"

BaseControl::BaseControl(BaseControl* parent)
	: m_parent(parent)
	, m_weight(1.0f)
{
}

BaseControl::~BaseControl()
{
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