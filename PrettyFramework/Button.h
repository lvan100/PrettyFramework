#pragma once

#include "UserControl.h"
#include "ButtonStyle.h"

namespace PrettyFramework {

	/**
	 * 按钮控件
	 */
	class Button : public UserControl
	{
	public:
		Button(LayoutControl* parent);
		virtual ~Button();

		// 
		// 0.属性
		// 

	public:
		/**
		 * 获取按钮样式
		 */
		shared_ptr<ButtonStyle>& GetStyle() {
			return m_style;
		}

	protected:
		/**
		 * 按钮样式
		 */
		shared_ptr<ButtonStyle> m_style;

	public:
		/**
		 * 设置图像
		 */
		void SetBitmap(HICON bitmap) {
			m_bitmap = bitmap;
		}

		/**
		 * 获取图像
		 */
		HICON GetBitmap() {
			return m_bitmap;
		}

	protected:
		/**
		 * 图像
		 */
		HICON m_bitmap;

	public:
		/**
		 * 获取文本内容
		 */
		CString GetText() {
			return m_text;
		}

		/**
		 * 设置文本内容
		 */
		void SetText(CString text) {
			m_text = text;
		}

	private:
		/**
		 * 文本内容
		 */
		CString m_text;

	public:
		/**
		 * 设置按钮点击事件响应
		 */
		void SetClickEvent(ClickEvent click) {
			m_click = click;
		}

	protected:
		/**
		 * 按钮点击事件响应
		 */
		ClickEvent m_click;

		// 
		// 1.绘图
		// 

	protected:
		/**
		 * 绘制自身当前层
		 */
		virtual void OnPaint(Gdiplus::Graphics& graph);
	
		// 
		// 2.事件
		// 

	protected:
		/**
		 * 鼠标弹起事件（子控件响应之前）
		 */
		virtual void OnPreviewMouseUp(EventParam& param);

		/**
		 * 鼠标弹起事件（子控件响应之后）
		 */
		virtual void OnMouseUp(EventParam& param);

		/**
		 * 鼠标移动事件（子控件响应之前）
		 */
		virtual void OnPreviewMouseMove(EventParam& param);

		/**
		 * 鼠标移动事件（子控件响应之后）
		 */
		virtual void OnMouseMove(EventParam& param);

		/**
		 * 鼠标按下事件（子控件响应之前）
		 */
		virtual void OnPreviewMouseDown(EventParam& param);

		/**
		 * 鼠标按下事件（子控件响应之后）
		 */
		virtual void OnMouseDown(EventParam& param);
	};

}