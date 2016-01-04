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
		LayoutControl::RecalcLayout();

		Rect rcMargined(rect_in_parent);
		rcMargined.DeflateRect(m_margin);

		float rectWidth = rcMargined.Width;
		float rectHeight = rcMargined.Height;

		size_t itemCount = m_children.size();

		// 重新计算每个控件的 Weight 属性
		vector<float> childWeight(itemCount);

		// 自动宽度的控件索引
		vector<size_t> autoChild;

		float allWeight = 0.0f;
		for (size_t i = 0; i < itemCount; i++) {

			auto& control = m_children.at(i);
			Size cFixSize = control->GetFixSize();

			if (cFixSize.Width > 0) {
				childWeight[i] = cFixSize.Width / rectWidth;
			} else {
				if (control->IsAutoWidth()) {
					childWeight[i] = 0.0f;
					autoChild.push_back(i);
				} else {
					childWeight[i] = m_children.at(i)->GetWeight();
				}
			}

			allWeight += childWeight[i];
		}

		float lastLeft = m_margin.Left;

		if (allWeight < 1.0f) {
			float f = (1.0f - allWeight) / autoChild.size();
			for (size_t i = 0; i < autoChild.size(); i++) {
				childWeight[autoChild[i]] = f;
			}
		}

		for (size_t i = 0; i < childWeight.size(); i++) {
			auto& control = m_children.at(i);
			Size cFixSize = control->GetFixSize();

			float width = childWeight[i] * rectWidth;
			if (lastLeft + width > rectWidth) {
				width = rectWidth - lastLeft;
			}

			if (cFixSize.Width > 0) {
				width = cFixSize.Width;
			}

			Rect rcControl;

			// 目前是靠左、居中显示
			float height = rectHeight;

			if (cFixSize.Height > 0) {
				height = cFixSize.Height;
				rcControl.Top = (rectHeight - cFixSize.Height) / 2.0f + m_margin.Top;
			} else {
				rcControl.Top = m_margin.Top;
			}

			rcControl.Width = width;
			rcControl.Height = height;
			rcControl.Left = lastLeft;

			control->SetRect(rcControl);

			lastLeft += width;
		}
	}

}