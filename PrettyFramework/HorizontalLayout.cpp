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

		Gdiplus::RectF rcMargined(rect_in_parent);

		rcMargined.X += m_margin.X;
		rcMargined.Y += m_margin.Y;
		rcMargined.Width -= m_margin.Width;
		rcMargined.Height -= m_margin.Height;

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
			Gdiplus::SizeF cFixSize = control->GetFixSize();

			if (cFixSize.Width > 0) {
				childWeight[i] = cFixSize.Width * 1.0f / rectWidth;
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

		int lastWidth = m_margin.GetLeft();

		if (allWeight < 1.0f) {
			float f = (1.0f - allWeight) / autoChild.size();
			for (size_t i = 0; i < autoChild.size(); i++) {
				childWeight[autoChild[i]] = f;
			}
		}

		for (size_t i = 0; i < childWeight.size(); i++) {
			auto& control = m_children.at(i);

			Gdiplus::RectF rcControl;

			Gdiplus::SizeF cFixSize = control->GetFixSize();

			int width = int(childWeight[i] * rectWidth);
			if (lastWidth + width > rectWidth) {
				width = rectWidth - lastWidth;
			}

			if (cFixSize.Width > 0) {
				width = cFixSize.Width;
			}

			// 目前是靠左、居中显示
			int height = rectHeight;
			if (cFixSize.Height > 0) {
				height = cFixSize.Height;
				rcControl.Y = (rectHeight - cFixSize.Height) / 2 + m_margin.GetTop();
			}
			else {
				rcControl.Y = m_margin.Y;
			}

			rcControl.X = lastWidth;
			rcControl.Width = width;
			rcControl.Height = height;

			control->SetRect(rcControl);
			lastWidth += width;
		}
	}

}