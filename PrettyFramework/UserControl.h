#pragma once

#include "LayoutControl.h"

namespace PrettyFramework {

	// 
	// ����ؼ���״̬�У���ͨ���ȵ㡢���¡����㡢�����ܹ�����״̬��
	// ��Ӧ�Ľ���ؼ���ÿ��״̬�µı�����ɫ���߿���ɫ���ᷢ���仯��
	// 

	/**
	 * ����ؼ�������һ��ͬ����С�Ĳ��ֿؼ�
	 */
	class UserControl : public BaseControl
	{
		friend class LayoutControl;

	public:
		UserControl(LayoutControl* parent);
		virtual ~UserControl();

		/**
		 * ���ò��ֿؼ���Ĭ�ϵĲ������κβ��ֿؼ�������β�ڵ�����
		 */
		void SetLayoutControl(shared_ptr<LayoutControl> layout) {
			m_layout = layout;
			RecalcLayout();
		}

		/**
		 * ��ȡ���ֿؼ������Զ�̬���򲼾ֿؼ�����ɾ�ؼ�
		 */
		shared_ptr<LayoutControl>& GetLayoutControl() {
			return m_layout;
		}

	protected:
		/**
		 * ���ֿؼ���Ĭ�ϲ������κβ��ֿؼ�
		 */
		shared_ptr<LayoutControl> m_layout;

	protected:
		/**
		 * ���㲼�ֿؼ����ӿؼ��Ĳ���
		 */
		virtual void RecalcLayout();

	public:
		/**
		 * ��ȡ��ͬ״̬�µı�����ɫ
		 */
		COLORREF GetBkColor(State state);

		/**
		 * ���ò�ͬ״̬�µı�����ɫ
		 */
		void SetBkColor(State state, COLORREF clr);

	protected:
		/**
		 * �ؼ���ͬ״̬�µı�����ɫ
		 */
		StateColor m_bk_color;

	public:
		/**
		 * ��ȡ��ͬ״̬�µı߿���ɫ
		 */
		COLORREF GetBorderColor(State state);

		/**
		 * ���ò�ͬ״̬�µı߿���ɫ
		 */
		void SetBorderColor(State state, COLORREF clr);

	protected:
		/**
		 * �ؼ���ͬ״̬�µı߿���ɫ
		 */
		StateColor m_border_color;

	protected:
		/**
		 * ֪ͨ�ؼ���Ҫ���л�ͼ
		 */
		virtual void Paint(CDC& dc);

		/**
		 * �̳д˿ؼ��Ŀؼ�������������
		 */
		virtual void OnPaint(CDC& dc) = 0;

	public:
		/**
		 * �Ƿ��ڰ���״̬
		 */
		BOOL IsPressed() {
			return ((m_state & State::Pressed) == State::Pressed);
		}

		/**
		 * �Ƿ��ڽ���״̬
		 */
		BOOL IsFocused() {
			return ((m_state & State::Focused) == State::Focused);
		}

		/**
		 * �Ƿ����ȵ�״̬
		 */
		BOOL IsHovered() {
			return ((m_state & State::Hovered) == State::Hovered);
		}

	public:
		/**
		 * �Ƿ��ڽ���״̬
		 */
		BOOL IsDisable() {
			return ((m_state & State::Disable) == State::Disable);
		}

		/**
		 * ���ÿؼ��Ƿ��ڽ���״̬
		 */
		void SetDisable(BOOL disable);

	protected:
		/**
		 * �����Ƿ��ڰ���״̬
		 */
		void SetPressed(BOOL pressed);

		/**
		 * �����Ƿ��ڽ���״̬
		 */
		void SetFocused(BOOL focused);

		/**
		 * �����Ƿ����ȵ�״̬
		 */
		void SetHovered(BOOL hovered);

	protected:
		/**
		 * �ؼ�״̬��@State
		 */
		int m_state;

	protected:
		/**
		 * ��굯���¼�
		 */
		virtual void OnMouseUp(CPoint point);

		/**
		 * ����ƶ��¼�
		 */
		virtual void OnMouseMove(CPoint point);

		/**
		 * ��갴���¼�
		 */
		virtual void OnMouseDown(CPoint point);
		
	protected:
		/**
		 * ��굯���¼����ӿؼ���Ӧ֮ǰ��
		 */
		virtual void OnPreviewMouseUp(EventParam& param) {
			if (m_preview_mouse_up_event) {
				m_preview_mouse_up_event(param);
			}
		}

		/**
		 * ��굯���¼����ӿؼ���Ӧ֮��
		 */
		virtual void OnMouseUp(EventParam& param) {
			if (m_mouse_up_event) {
				m_mouse_up_event(param);
			}
		}

		/**
		 * ����ƶ��¼����ӿؼ���Ӧ֮ǰ��
		 */
		virtual void OnPreviewMouseMove(EventParam& param) {
			if (m_preview_mouse_move_event) {
				m_preview_mouse_move_event(param);
			}
		}

		/**
		 * ����ƶ��¼����ӿؼ���Ӧ֮��
		 */
		virtual void OnMouseMove(EventParam& param) {
			if (m_mouse_move_event) {
				m_mouse_move_event(param);
			}
		}

		/**
		 * ��갴���¼����ӿؼ���Ӧ֮ǰ��
		 */
		virtual void OnPreviewMouseDown(EventParam& param) {
			if (m_preview_mouse_down_event) {
				m_preview_mouse_down_event(param);
			}
		}

		/**
		 * ��갴���¼����ӿؼ���Ӧ֮��
		 */
		virtual void OnMouseDown(EventParam& param) {
			if (m_mouse_down_event) {
				m_mouse_down_event(param);
			}
		}

	public:
		/**
		 * ������굯���¼����ӿؼ���Ӧ֮ǰ�����¼���Ӧ
		 */
		void SetPreviewMouseUpEvent(MouseEvent event) {
			m_preview_mouse_up_event = event;
		}

		/**
		 * ������굯���¼����ӿؼ���Ӧ֮�󣩵��¼���Ӧ
		 */
		void SetMouseUpEvent(MouseEvent event) {
			m_mouse_up_event = event;
		}

		/**
		 * ��������ƶ��¼����ӿؼ���Ӧ֮ǰ�����¼���Ӧ
		 */
		void SetPreviewMouseMoveEvent(MouseEvent event) {
			m_preview_mouse_move_event = event;
		}

		/**
		 * ��������ƶ��¼����ӿؼ���Ӧ֮�󣩵��¼���Ӧ
		 */
		void SetMouseMoveEvent(MouseEvent event) {
			m_mouse_move_event = event;
		}

		/**
		 * ������갴���¼����ӿؼ���Ӧ֮ǰ�����¼���Ӧ
		 */
		void SetPreviewMouseDownEvent(MouseEvent event) {
			m_preview_mouse_down_event = event;
		}

		/**
		 * ������갴���¼����ӿؼ���Ӧ֮�󣩵��¼���Ӧ
		 */
		void SetMouseDownEvent(MouseEvent event) {
			m_mouse_down_event = event;
		}

	protected:
		/**
		 * ��굯���¼����ӿؼ���Ӧ֮ǰ�����¼���Ӧ
		 */
		MouseEvent m_preview_mouse_up_event;

		/**
		 * ������굯���¼����ӿؼ���Ӧ֮�󣩵��¼���Ӧ
		 */
		MouseEvent m_mouse_up_event;

		/**
		 * ��������ƶ��¼����ӿؼ���Ӧ֮ǰ�����¼���Ӧ
		 */
		MouseEvent m_preview_mouse_move_event;

		/**
		 * ��������ƶ��¼����ӿؼ���Ӧ֮�󣩵��¼���Ӧ
		 */
		MouseEvent m_mouse_move_event;

		/**
		 * ������갴���¼����ӿؼ���Ӧ֮ǰ�����¼���Ӧ
		 */
		MouseEvent m_preview_mouse_down_event;

		/**
		 * ������갴���¼����ӿؼ���Ӧ֮�󣩵��¼���Ӧ
		 */
		MouseEvent m_mouse_down_event;

	protected:
		/**
		 * ����ָ��ID�Ŀؼ�������ʧ�ܷ��ؿ�ָ��
		 */
		virtual BaseControl* FindControlById(CString id);

	public:
		/**
		 * �����ϸ��Ϣ
		 */
		virtual void Dump();
	};

}