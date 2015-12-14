#include "stdafx.h"
#include "VerticalLayout.h"

VerticalLayout::VerticalLayout(BaseControl* control)
	: LayoutControl(control)
{
}

VerticalLayout::~VerticalLayout()
{
}

void VerticalLayout::RecalcLayout()
{
	if (m_children.size() == 0) {
		return;
	}

	int rectWidth = rect_in_parent.Width();
	int rectHeight = rect_in_parent.Height();

	size_t itemCount = m_children.size();
	int itemHeight = rectHeight / itemCount;

	for (size_t i = 0; i < itemCount; i++) {
		CRect rc(0, itemHeight * i, rectWidth, itemHeight * (i + 1));
		m_children.at(i)->SetRect(rc);
	}
}