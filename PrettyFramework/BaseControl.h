#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Constant.h"

namespace PrettyFramework {

	//
	// �Զ���ؼ�ģ�ͣ��ο�Android����ģ�ͣ�������ͬ�����ɺϣ�
	//

	//
	// �Զ���ؼ����Է�Ϊ����ؼ��Ͳ��ֿؼ����֡�һ�����ֿؼ�
	// ���԰���������ֿؼ����߶������ؼ��������ݲ�ͬ�Ĺ���
	// ���ӿؼ������ڸ��ؼ��ڡ����ֿؼ��ĸ��ؼ������ǲ��ֿؼ���
	// Ҳ�����ǽ���ؼ�����һ������ؼ���ֻ�ܰ���һ�����ֿؼ���
	//

	//
	// �������Ϲ����γɵ�XML���������ļ���ʽ���£�
	// 
	// <LayoutControl>
	//		<LayoutControl>
	//			<UserControl>
	//				<LayoutControl />
	//			</UserControl>
	//		</LayoutControl>
	//		<UserControl />
	//		<LayoutControl />
	//		<UserControl />
	// </LayoutControl>
	//

	// 
	// �ڵ�ǰ��ģ���У����ֿؼ����Բ����б������߿�Ƚ������ԡ�
	// 

	// 
	// �ؼ���Ȩ�أ�һ����ԣ�Ȩ����һ��[0.0f,1.0f]�м��ĳ��ֵ��
	// ���ĳ���ؼ���Ȩ�س�����1.0f������Ϊ�ÿؼ��Զ������С.
	// 

	// 
	// �ڼ���ؼ�Ȩ�ص�ʱ�򣬹̶���С�ᰴ����ռ���ؼ��ı��ؼ��㣬
	// ָ��Ȩ�صĿؼ����������õı��ؼ��㣬�Զ��߶Ȼ��߿�ȵĿؼ�
	// ������ʣ��Ȩ�ؾ��ȷ���.���ؼ���Ƚ�����1.0����Ȩ�ؽ��м���
	// 

	/**
	 * �����ؼ�
	 */
	class BaseControl
	{
	public:
		BaseControl(BaseControl* parent);
		virtual ~BaseControl();

		/**
		 * ��ȡ���ؼ�
		 */
		BaseControl* GetParent() {
			return m_parent;
		}

	protected:
		/**
		 * ���ؼ�
		 */
		BaseControl* m_parent;

	public:
		/**
		 * ���ÿؼ���ID
		 */
		void SetId(CString id) {
			m_id = id;
		}

		/**
		 * ��ȡ�ؼ���ID
		 */
		CString GetId() {
			return m_id;
		}

	protected:
		/**
		 * �ؼ���ID
		 */
		CString m_id;

	public:
		/**
		 * ��ȡ���ش���ָ��
		 */
		void* GetWindow();

	protected:
		/**
		 * ���ñ��ش���ָ��
		 */
		void SetWindow(void* window) {
			m_window = window;
		}

	private:
		/**
		 * ���ش���ָ��
		 */
		void* m_window;

	public:
		/**
		 * ���ÿؼ���ʾ����
		 */
		void SetRect(CRect rect) {
			rect_in_parent = rect;
			RecalcLayout();
		}

		/**
		 * ��ȡ�ؼ���ʾ����
		 */
		CRect GetRect() {
			return rect_in_parent;
		}

	protected:
		/**
		 * �ڸ��ؼ�����ʾ����
		 */
		CRect rect_in_parent;

	public:
		/**
		 * ���ù̶���С
		 */
		void SetFixSize(CSize size) {
			m_fix_size = size;
		}

		/**
		 * ��ȡ�̶���С
		 */
		CSize GetFixSize() {
			return m_fix_size;
		}

	protected:
		/**
		 * �̶���С
		 */
		CSize m_fix_size;

	public:
		/**
		 * ���ÿؼ���λ��Ȩ��
		 */
		void SetWeight(float weight) {
			m_weight = weight;
		}

		/*
		 * ��ȡ�ؼ���λ��Ȩ��
		 */
		float GetWeight() {
			return m_weight;
		}

	protected:
		/**
		 * �ؼ���Ȩ��
		 */
		float m_weight;

	public:
		/**
		 * �����Զ����
		 */
		void SetAutoWidth(BOOL autoWidth) {
			m_auto_width = autoWidth;
		}

		/**
		 * �Ƿ��������Զ����
		 */
		BOOL IsAutoWidth() {
			return m_auto_width;
		}

	protected:
		/**
		 * �Զ����
		 */
		BOOL m_auto_width;

	public:
		/**
		 * �����Զ��߶�
		 */
		void SetAutoHeight(BOOL autoHeight) {
			m_auto_height = autoHeight;
		}

		/**
		 * �Ƿ��������Զ��߶�
		 */
		BOOL IsAutoHeight() {
			return m_auto_height;
		}

	protected:
		/**
		 * �Զ��߶�
		 */
		BOOL m_auto_height;

	public:
		/**
		 * �������ݵĶ��뷽ʽ��@Gravity
		 */
		void SetGravity(int gravity) {
			m_gravity = gravity;
		}

		/**
		 * ��ȡ���ݵĶ��뷽ʽ��@Gravity
		 */
		int GetGravity() {
			return m_gravity;
		}

	protected:
		/**
		 * ���ݵĶ��뷽ʽ��@Gravity
		 */
		int m_gravity;

	public:
		/**
		 * ��ȡ�ؼ��Ļ�ͼ����
		 */
		CRect GetPaintRect();

		/**
		 * ��ͼ
		 */
		virtual void Paint(CDC& dc) = 0;

	public:
		/**
		 * ��굯��
		 */
		virtual void OnButtonUp() = 0;

		/**
		 * ����ƶ�
		 */
		virtual void OnMouseMove() = 0;

		/**
		 * ��갴��
		 */
		virtual void OnButtonDown() = 0;

	protected:
		/**
		 * ���¼������ؼ��Ĳ���
		 */
		virtual void RecalcLayout() = 0;
	};

}