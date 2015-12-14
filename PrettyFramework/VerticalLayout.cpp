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

	float allWeight = 0.0f;
	for (size_t i = 0; i < itemCount; i++) {
		allWeight += m_children.at(i)->GetWeight();
	}

	int lastHeight = 0;

	float fHeight = rectHeight / allWeight;

	for (auto iter = m_children.begin(); iter != m_children.end(); iter++) {
		auto& control = (*iter);

		float w = control->GetWeight();
		CSize s = control->GetMinSize();

		int h = max(int(w * fHeight), s.cy);
		if (lastHeight + h > rectHeight) {
			h = rectHeight - lastHeight;
		}

		control->SetRect(CRect(0, lastHeight, rectWidth, lastHeight + h));
		lastHeight += h;
	}
}