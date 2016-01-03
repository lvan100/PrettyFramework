#include "stdafx.h"
#include "BaseControl.h"

namespace PrettyFramework {

	BaseControl::BaseControl(BaseControl* parent)
		: m_weight(1.0f)
		, m_parent(parent)
		, m_window(nullptr)
		, m_auto_width(TRUE)
		, m_auto_height(TRUE)
	{
		if (parent != nullptr) {
			m_window = parent->GetWindow();
		}
		
		m_gravity = Gravity::Left | Gravity::Top;
	}

	BaseControl::~BaseControl()
	{
	}
	
	// 
	// 经过慎重考虑和实践，不能使用单独线程刷新界面。
	// 

	void BaseControl::Redraw()
	{
#if 0
		CRect rect = toGdiRect(GetViewRect());
		InvalidateRect((HWND)m_window, rect, TRUE);
#else
		InvalidateRect((HWND)m_window, NULL, TRUE);
#endif
	}

	// 
	// 参照下面的示意图理解 @BaseControl::GetViewRect 的计算方式。
	// 
	// | (0,0) ———————————————————————— |
	// |                                                        |
	// |          | (80,40) | (0,0) ——————— |            |
	// |          |                                |            |
	// |          |     | (80,40) ————— |     |            |
	// |          |     |                    |     |            |
	// |          |     |——————————|     |            |
	// |          |                                |            |
	// |          |————————————————|            |
	// |                                                        |
	// |————————————————————————————|
	// 

	Rect BaseControl::GetViewRect()
	{
		if (m_parent != nullptr) {
			Rect rcParent = m_parent->GetViewRect();
			Rect rcView = rect_in_parent;
			rcView.Left += rcParent.Left;
			rcView.Top += rcParent.Top;
			/* 控件在窗口视图的位置 */
			return rcView;
		} else {
			return rect_in_parent;
		}
	}

	BOOL BaseControl::HitTest(Point point)
	{
		return rect_in_parent.Contains(point);
	}

}