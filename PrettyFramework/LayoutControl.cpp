#include "stdafx.h"
#include "LayoutControl.h"

namespace PrettyFramework {

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
			ASSERT(FALSE); /* ��Ȼ����ɾ���Լ� */
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
		CRgn rgnClient;
		CRect rcClient = GetPaintRect();
		rgnClient.CreateRectRgnIndirect(rcClient);

		for (auto iter = m_children.begin()
			; iter != m_children.end()
			; iter++) {

			CRgn rgn;
			auto& control = (*iter);

			CRect rect = control->GetPaintRect();
			rgn.CreateRectRgnIndirect(rect);

			// ��ֹ�ӿؼ���λ�ó������ؼ�����ʾ��Χ.
			rgn.CombineRgn(&rgnClient, &rgn, RGN_AND);
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

}