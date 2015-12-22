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
		rect_in_parent.SetRectEmpty();

		if (parent != nullptr) {
			m_window = parent->GetWindow();
		}
		
		m_gravity = Gravity::Left | Gravity::Top;
	}

	BaseControl::~BaseControl()
	{
	}

	// 
	// 目前的重绘机制没有采用“脏区域”、计时器刷新的方式，而是
	// 使用 WIN32 API 激活原生窗口的重绘机制，效果现在暂时未知。
	// 

	// 
	// 计时器刷新机制漫谈：启动界面线程，并将根控件绑定到此线程
	// ，采用硬件加速技术绘制界面，保持每隔16ms刷新一次的频率。
	// 
	
	void BaseControl::Redraw()
	{
		InvalidateRect((HWND)m_window, GetViewRect(), TRUE);
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

	CRect BaseControl::GetViewRect()
	{
		if (m_parent != nullptr) {
			CRect rcView(rect_in_parent);
			CRect rcParent = m_parent->GetViewRect();
			rcView.OffsetRect(rcParent.left, rcParent.top);
			return rcView; /* 转换为控件在窗口视图的位置 */
		} else {
			return rect_in_parent;
		}
	}

	BOOL BaseControl::HitTest(CPoint point)
	{
		return rect_in_parent.PtInRect(point);
	}

}