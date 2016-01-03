#include "stdafx.h"
#include "BaseControl.h"

namespace PrettyFramework {

	BaseControl::BaseControl(BaseControl* parent)
		: m_weight(1.0f)
		, m_parent(parent)
		, m_fix_size(0, 0)
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
		InvalidateRect((HWND)m_window, NULL, TRUE);
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

	Gdiplus::RectF BaseControl::GetViewRect()
	{
		if (m_parent != nullptr) {
			Gdiplus::RectF rcView(rect_in_parent);
			Gdiplus::RectF rcParent = m_parent->GetViewRect();
			rcView.Offset(rcParent.GetLeft(), rcParent.GetTop());
			return rcView; /* 转换为控件在窗口视图的位置 */
		} else {
			return rect_in_parent;
		}
	}

	BOOL BaseControl::HitTest(Gdiplus::PointF point)
	{
		return rect_in_parent.Contains(point);
	}

}