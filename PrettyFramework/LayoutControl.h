#pragma once

#include "BaseControl.h"
#include "TwoPointShape.h"

namespace PrettyFramework {

	/**
	 * ���ֿؼ��������ӿؼ��ڸ��ؼ��ڵĲ���
	 */
	class LayoutControl : public BaseControl
	{
		friend class UserControl;

	public:
		LayoutControl(BaseControl* control);
		virtual ~LayoutControl();

		// 
		// 0.����
		// 

	public:
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
		 * �ӿؼ��б������ӿؼ����������ڡ�
		 */
		vector<shared_ptr<BaseControl>> m_children;
		
		// 
		// 1.��ͼ
		// 

	public:
		/**
		 * ��ȡ���ֿؼ��ı�������
		 */
		shared_ptr<TwoPointShape>& GetBkgndShape() {
			return m_bkgnd_shape;
		}

	protected:
		/**
		 * ���ֿؼ��ı�������
		 */
		shared_ptr<TwoPointShape> m_bkgnd_shape;

	protected:
		/**
		 * ����ʵ�ֻ�ͼ�ӿ�
		 */
		virtual void Paint0(Gdiplus::Graphics& graph);

		// 
		// 2.�¼�
		// 

	protected:
		/**
		 * ��굯���¼�
		 */
		virtual void OnMouseUp(Point point);

		/**
		 * ����ƶ��¼�
		 */
		virtual void OnMouseMove(Point point);

		/**
		 * ��갴���¼�
		 */
		virtual void OnMouseDown(Point point);

	protected:
		/**
		 * �����갴�µ��ӿؼ��������ӿؼ�
		 */
		weak_ptr<BaseControl> last_pressed;

		/**
		 * �������ȵ���ӿؼ��������ӿؼ�
		 */
		weak_ptr<BaseControl> last_hovered;

		/**
		 * �����ý�����ӿؼ��������ӿؼ�
		 */
		weak_ptr<BaseControl> last_focused;
		
		// 
		// 3.����
		// 

	protected:
		/**
		 * ���¼������ؼ��Ĳ���
		 */
		virtual void RecalcLayout();

	public:
		/**
		 * ����ָ��ID�Ŀؼ�������ʧ�ܷ��ؿ�ָ��
		 */
		virtual BaseControl* FindControlById(CString id);
		
		// 
		// 4.����
		// 

	public:
		/**
		 * ����ؼ�����ϸ��Ϣ
		 */
		virtual void Dump();
	};

}