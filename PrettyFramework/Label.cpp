#include "stdafx.h"

#include "Label.h"

namespace PrettyFramework {

	Label::Label(LayoutControl* parent)
		: UserControl(parent)
	{
		m_style.reset(new LabelStyle(this));
	}

	Label::~Label()
	{
	}

	void Label::OnPaint(Gdiplus::Graphics& graph)
	{
// 		if (m_style != nullptr) {
// 			m_style->Paint(dc);
// 		}
	}

}