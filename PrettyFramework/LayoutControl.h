#pragma once

#include "BaseControl.h"

namespace PrettyFramework {

	/**
	 * ���ֿؼ���ֻ�����ӿؼ��Ĳ��֣�û�н���
	 */
	class LayoutControl : public BaseControl
	{
		friend class UserControl;

	public:
		LayoutControl(BaseControl* control);
		virtual ~LayoutControl();

		/**
		 * ����ӿؼ�����Ȼ�����ظ�������Լ�
		 */
		void AddChild(shared_ptr<BaseControl> child);

		/**
		 * �Ƴ��ӿؼ�����Ȼ�����ظ���ɾ���Լ�
		 */
		void RemoveChild(shared_ptr<BaseControl> child);

		/**
		 * ��ȡ�ӿؼ��б�
		 */
		vector<shared_ptr<BaseControl>>& GetChildren() {
			return m_children;
		}

	protected:
		/**
		 * �ӿؼ��б�
		 */
		vector<shared_ptr<BaseControl>> m_children;

	protected:
		/**
		* ����ָ��ID�Ŀؼ�������ʧ�ܷ��ؿ�ָ��
		*/
		virtual BaseControl* OnFindControlById(CString id);

	protected:
		/**
		 * ֪ͨ�ؼ���Ҫ���л�ͼ
		 */
		virtual void Paint(CDC& dc);

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
		 * �����갴�µ��ӿؼ�
		 */
		shared_ptr<BaseControl> last_pressed;

		/**
		 * �������ȵ���ӿؼ�
		 */
		shared_ptr<BaseControl> last_hovered;

		/**
		 * �����ý�����ӿؼ�
		 */
		shared_ptr<BaseControl> last_focused;

	public:
		/**
		 * ����ؼ�����ϸ��Ϣ
		 */
		virtual void Dump();
	};

}