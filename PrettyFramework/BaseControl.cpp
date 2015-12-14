#include "stdafx.h"
#include "BaseControl.h"

BaseControl::BaseControl(BaseControl* parent)
	: m_window(nullptr)
	, m_parent(parent)
	, m_weight(1.0f)
{
}

BaseControl::~BaseControl()
{
}

void* BaseControl::GetWindow()
{
	if (m_parent != nullptr) {
		return m_parent->GetWindow();
	} else {
		return m_window;
	}
}

CRect BaseControl::GetPaintRect()
{
	if (m_parent != nullptr) {
		CRect rcPaint(rect_in_parent);
		CRect rcParent = m_parent->GetPaintRect();
		rcPaint.OffsetRect(rcParent.left, rcParent.top);
		return rcPaint; /* 转换为控件在窗口视图的位置 */
	} else {
		return rect_in_parent;
	}
}