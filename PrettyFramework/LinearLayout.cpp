#include "stdafx.h"
#include "LinearLayout.h"

namespace PrettyFramework {

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

		// 重新计算每个控件的 Weight 属性
		vector<float> childWeight(itemCount);

		// 自动宽度的控件索引
		vector<int> autoChild;

		float allWeight = 0.0f;
		for (size_t i = 0; i < itemCount; i++) {

			auto& control = m_children.at(i);
			CSize cFixSize = control->GetFixSize();

			if (cFixSize.cx > 0) {
				childWeight[i] = cFixSize.cx * 1.0f / rectWidth;
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

		int lastWidth = 0;

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
				rcControl.top = (rectHeight - cFixSize.cy ) / 2;
				height = cFixSize.cy;
			}

			rcControl.left = lastWidth;
			rcControl.right = lastWidth + width;
			rcControl.bottom = rcControl.top + height;

			control->SetRect(rcControl);
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
			// CSize sz = control->GetMinSize();
			CSize fz = control->GetFixSize();

			int height = max(int(wg * fHeight), 0);

			if (lastHeight + height > rectHeight) {
				height = rectHeight - lastHeight;
			}

			if (fz.cy > 0) {
				height = fz.cy;
			}

			control->SetRect(CRect(0, lastHeight, rectWidth, lastHeight + height));
			lastHeight += height;
		}
	}

}