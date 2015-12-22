#include "stdafx.h"
#include "HorizontalLayout.h"

namespace PrettyFramework {

	HorizontalLayout::HorizontalLayout(BaseControl* control)
		: LayoutControl(control)
	{}
	
	HorizontalLayout::~HorizontalLayout()
	{}

	void HorizontalLayout::RecalcLayout()
	{
		CRect rcMargined(rect_in_parent);
		rcMargined.DeflateRect(m_margin);

		int rectWidth = rcMargined.Width();
		int rectHeight = rcMargined.Height();

		size_t itemCount = m_children.size();

		// 重新计算每个控件的 Weight 属性
		vector<float> childWeight(itemCount);

		// 自动宽度的控件索引
		vector<size_t> autoChild;

		float allWeight = 0.0f;
		for (size_t i = 0; i < itemCount; i++) {

			auto& control = m_children.at(i);
			CSize cFixSize = control->GetFixSize();

			if (cFixSize.cx > 0) {
				childWeight[i] = cFixSize.cx * 1.0f / rectWidth;
			}
			else {
				if (control->IsAutoWidth()) {
					childWeight[i] = 0.0f;
					autoChild.push_back(i);
				}
				else {
					childWeight[i] = m_children.at(i)->GetWeight();
				}
			}

			allWeight += childWeight[i];
		}

		int lastWidth = m_margin.left;

		if (allWeight < 1.0f) {
			float f = (1.0f - allWeight) / autoChild.size();
			for (size_t i = 0; i < autoChild.size(); i++) {
				childWeight[autoChild[i]] = f;
			}
		}

		for (size_t i = 0; i < childWeight.size(); i++) {
			auto& control = m_children.at(i);

			CRect rcControl;

			CSize cFixSize = control->GetFixSize();

			int width = int(childWeight[i] * rectWidth);
			if (lastWidth + width > rectWidth) {
				width = rectWidth - lastWidth;
			}

			if (cFixSize.cx > 0) {
				width = cFixSize.cx;
			}

			// 目前是靠左、居中显示
			int height = rectHeight;
			if (cFixSize.cy > 0) {
				height = cFixSize.cy;
				rcControl.top = (rectHeight - cFixSize.cy) / 2 + m_margin.top;
			}
			else {
				rcControl.top = m_margin.top;
			}

			rcControl.left = lastWidth;
			rcControl.right = lastWidth + width;
			rcControl.bottom = rcControl.top + height;

			control->SetRect(rcControl);
			lastWidth += width;
		}
	}

}