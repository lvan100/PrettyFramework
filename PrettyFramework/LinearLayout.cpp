#include "stdafx.h"
#include "LinearLayout.h"

LinearLayout::LinearLayout(BaseControl* control, BOOL horizontal)
	: LayoutControl(control)
	, m_horizontal(horizontal)
{
}

LinearLayout::~LinearLayout()
{
}

void LinearLayout::RecalcLayout()
{
	if (m_children.size() > 0) {
		if (m_horizontal) {
			RecalcLayoutH();
		} else {
			RecalcLayoutV();
		}
	}
}

void LinearLayout::RecalcLayoutH()
{
	int rectWidth = rect_in_parent.Width();
	int rectHeight = rect_in_parent.Height();

	size_t itemCount = m_children.size();

	float allWeight = 0.0f;
	for (size_t i = 0; i < itemCount; i++) {
		allWeight += m_children.at(i)->GetWeight();
	}

	int lastWidth = 0;

	float fWidth = rectWidth / allWeight;

	for (auto iter = m_children.begin(); iter != m_children.end(); iter++) {
		auto& control = (*iter);

		float wg = control->GetWeight();
		CSize sz = control->GetMinSize();

		int width = max(int(wg * fWidth), sz.cx);
		if (lastWidth + width > rectWidth) {
			width = rectWidth - lastWidth;
		}

		control->SetRect(CRect(lastWidth, 0, lastWidth + width, rectHeight));
		lastWidth += width;
	}
}

void LinearLayout::RecalcLayoutV()
{
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

		float wg = control->GetWeight();
		CSize sz = control->GetMinSize();

		int height = max(int(wg * fHeight), sz.cy);
		if (lastHeight + height > rectHeight) {
			height = rectHeight - lastHeight;
		}

		control->SetRect(CRect(0, lastHeight, rectWidth, lastHeight + height));
		lastHeight += height;
	}
}