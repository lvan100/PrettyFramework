#include "stdafx.h"

#include "Button.h"
#include "BaseTheme.h"

namespace PrettyFramework {

	Button::Button(LayoutControl* parent)
		: UserControl(parent)
		, m_bitmap(nullptr)
	{
	}

	Button::~Button()
	{
	}

	void Button::OnPaint(Gdiplus::Graphics& graph)
	{
// 		if (m_style != nullptr) {
// 			m_style->Paint(dc);
// 		}
	}
	
	void Button::OnPreviewMouseUp(EventParam& param)
	{
		UserControl::OnPreviewMouseUp(param);

		if (m_click) {
			 m_click(ClickParam{this});
		}
	}
	
	void Button::OnMouseUp(EventParam& param)
	{
		UserControl::OnMouseUp(param);
	}
	
	void Button::OnPreviewMouseMove(EventParam& param)
	{
		UserControl::OnPreviewMouseMove(param);
	}

	void Button::OnMouseMove(EventParam& param)
	{
		UserControl::OnMouseMove(param);
	}

	void Button::OnPreviewMouseDown(EventParam& param)
	{
		UserControl::OnPreviewMouseDown(param);
	}
	
	void Button::OnMouseDown(EventParam& param)
	{
		UserControl::OnMouseDown(param);
	}
	
}