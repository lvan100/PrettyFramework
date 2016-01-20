#pragma once

#include "Coordinate.h"

namespace PrettyFramework {

	// 
	// 设计原则：为了简单，只能实现为单根继承的系统。
	// 

	// 
	// 任何具有视觉效果的对象都需要继承 @Visual 接口
	// ，比如基础控件、绘图形状等，都会继承该接口。
	// 

	// 
	// 考虑到跨平台性，绘图库使用 Gdiplus（跨平台）。
	// 

	/**
	 * 视觉接口
	 */
	class Visual
	{
	public:
		/**
		 * 完成绘图过程
		 */
		void Paint(Gdiplus::Graphics& graph) {
			if (!_paintFrozen) {
				Paint0(graph);
			}
		}

		/**
		 * 冻结绘图过程
		 */
		void FreezePaint(BOOL freeze) {
			_paintFrozen = freeze;
		}

		/**
		 * 绘图是否冻结
		 */
		BOOL PaintFrozen() {
			return _paintFrozen;
		}

	protected:
		/**
		 * 绘图是否冻结
		 */
		BOOL _paintFrozen = FALSE;

	protected:
		/**
		 * 子类实现绘图接口
		 */
		virtual void Paint0(Gdiplus::Graphics& graph) = 0;
	};

}