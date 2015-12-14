#include "stdafx.h"
#include "LayoutControl.h"

LayoutControl::LayoutControl(BaseControl* control)
	: BaseControl(control)
{
}

LayoutControl::~LayoutControl()
{
}

void LayoutControl::AddChild(shared_ptr<BaseControl> child)
{
	if (child != nullptr && child.get() != this) {
		m_children.push_back(child);
	}

	RecalcLayout();
}

void LayoutControl::RemoveChild(shared_ptr<BaseControl> child)
{
	if (child == nullptr || child.get() == this) {
		ASSERT(FALSE); /* 当然不能删除自己 */
		return;
	}

	for (auto iter = m_children.begin()
		; iter != m_children.end()
		; iter++) {

		if (child == (*iter)) {
			m_children.erase(iter);

			if (last_pressed == child) {
				last_pressed = nullptr;
			}

			if (last_hovered == child) {
				last_hovered = nullptr;
			}

			if (last_focused == child) {
				last_focused = nullptr;
			}

			break;
		}
	}

	RecalcLayout();
}

void LayoutControl::Paint(CDC& dc)
{
	for (auto iter = m_children.begin()
		; iter != m_children.end()
		; iter++) {

		CRgn rgn;
		auto& control = (*iter);

		CRect rect = control->GetPaintRect();
		rgn.CreateRectRgnIndirect(rect);
		dc.SelectClipRgn(&rgn);

		control->Paint(dc);
	}
}

void LayoutControl::OnButtonUp()
{

}

void LayoutControl::OnMouseMove()
{

}

void LayoutControl::OnButtonDown()
{

}