#include "stdafx.h"
#include "VerticalLayout.h"

namespace PrettyFramework {

	VerticalLayout::VerticalLayout(BaseControl* control)
		: LayoutControl(control)
	{}
	
	VerticalLayout::~VerticalLayout()
	{}

	void VerticalLayout::RecalcLayout()
	{
		LayoutControl::RecalcLayout();

		CRect rcMargined(rect_in_parent);
		rcMargined.DeflateRect(m_margin);

		int rectWidth = rcMargined.Width();
		int rectHeight = rcMargined.Height();

		size_t itemCount = m_children.size();

		float allWeight = 0.0f;
		for (size_t i = 0; i < itemCount; i++) {
			allWeight += m_children.at(i)->GetWeight();
		}

		int lastHeight = m_margin.top;

		float fHeight = rectHeight / allWeight;

		for (auto iter = m_children.begin(); iter != m_children.end(); iter++) {
			auto& control = (*iter);

			float wg = control->GetWeight();
			CSize fz = control->GetFixSize();

			int height = max(int(wg * fHeight), 0);

			if (lastHeight + height > rectHeight + m_margin.top) {
				height = m_margin.top + rectHeight - lastHeight;
			}

			if (fz.cy > 0) {
				height = fz.cy;
			}

			control->SetRect(CRect(m_margin.left, lastHeight, m_margin.left + rectWidth, lastHeight + height));
			lastHeight += height;
		}
	}

}