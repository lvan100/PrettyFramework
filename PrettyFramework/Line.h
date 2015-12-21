#pragma once

#include "Shape.h"

namespace PrettyFramework {

	/**
	 * 线条，具有起点和终点等属性。
	 */
	class Line : public Shape
	{
	public:
		Line();
		virtual ~Line();

	public:
		/**
		 * 设置线条起始点
		 */
		void SetBeginPoint(CPoint point) {
			m_pt_begin = point;
		}

		/**
		 * 获取线条起始点
		 */
		CPoint GetBeginPoint() {
			return m_pt_begin;
		}

	protected:
		/**
		 * 线条起始点
		 */
		CPoint m_pt_begin;

	public:
		/**
		 * 设置线条结束点
		 */
		void SetEndPoint(CPoint point) {
			m_pt_end = point;
		}

		/**
		 * 获取线条结束点
		 */
		CPoint GetEndPoint() {
			return m_pt_end;
		}

	protected:
		/**
		 * 线条结束点
		 */
		CPoint m_pt_end;

	public:
		/**
		 * 定义视觉样式的绘图接口
		 */
		virtual void Paint(CDC& dc);
	};

}