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
		 * ����ָ��ID�Ŀؼ�������ʧ�ܷ��ؿ�ָ��
		 */
		virtual BaseControl* OnFindControlById(CString id);

	public:
		/**
		 * �����ϸ��Ϣ
		 */
		virtual void Dump();
	};

}