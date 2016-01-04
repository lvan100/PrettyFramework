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

// 		Rect rcMargined(rect_in_parent);
// 
// 		rcMargined.X += m_margin.X;
// 		rcMargined.Y += m_margin.Y;
// 		rcMargined.Width -= m_margin.Width;
// 		rcMargined.Height -= m_margin.Height;
// 
// 		float rectWidth = rcMargined.Width;
// 		float rectHeight = rcMargined.Height;
// 
// 		size_t itemCount = m_children.size();
// 
// 		float allWeight = 0.0f;
// 		for (size_t i = 0; i < itemCount; i++) {
// 			allWeight += m_children.at(i)->GetWeight();
// 		}
// 
// 		int lastHeight = m_margin.GetTop();
// 
// 		float fHeight = rectHeight / allWeight;
// 
// 		for (auto iter = m_children.begin(); iter != m_children.end(); iter++) {
// 			auto& control = (*iter);
// 
// 			float wg = control->GetWeight();
// 			Size fz = control->GetFixSize();
// 
// 			int height = max(int(wg * fHeight), 0);
// 
// 			if (lastHeight + height > rectHeight + m_margin.GetTop()) {
// 				height = m_margin.GetTop() + rectHeight - lastHeight;
// 			}
// 
// 			if (fz.Height > 0) {
// 				height = fz.Height;
// 			}
// 
// 			control->SetRect(Rect(m_margin.GetLeft(), lastHeight, rectWidth, height));
// 			lastHeight += height;
// 		}
	}

}