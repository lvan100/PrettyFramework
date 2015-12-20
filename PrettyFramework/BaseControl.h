#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Constant.h"

namespace PrettyFramework {

	//
	// �Զ���ؼ�ģ�ͣ�����ʵ�ֲο�Android����ģ�͵ĸ��
	//

	//
	// �Զ���ؼ������Ͽ��Է�Ϊ[����ؼ�]��[���ֿؼ�]���֡�
	// ����ؼ�������ʾ���ݵĿؼ���������Ӧ���ͼ�����Ϣ��
	// ���ֿؼ���ͨ��ָ�������ӿؼ������ڸ��ؼ��ڵĿؼ���
	//
	
	// 
	// ���ֿؼ����������κοؼ����丸�ؼ��ȿ����ǲ��ֿؼ���
	// Ҳ�����ǽ���ؼ���������ؼ���ֻ�ܰ���һ�����ֿؼ���
	// �丸�ؼ�Ҳֻ���ǲ��ֿؼ���
	// 
	
	//
	// �������Ϲ������ɵ� XML ��ʽ�Ľ��������ļ���ʽ���£�
	// 
	// <LayoutControl id="root">
	//		<LayoutControl id="title">
	//			<UserControl id="app_icon">
	//				<LayoutControl />
	//			</UserControl>
	//		</LayoutControl>
	//		<UserControl id="content" />
	//		<LayoutControl id="status">
	//			<UserControl id="tip">
	//				<LayoutControl />
	//			</UserControl>
	//		</LayoutControl>
	// </LayoutControl>
	//

	// 
	// �ڴ�ģ���У����ֿؼ���������б������߿�Ƚ������ԡ�
	// 

	// 
	// ���ֿؼ��ڼ���ؼ�Ȩ�ص�ʱ�򣬹̶���С�Ŀؼ��ᰴ��
	// ��ռ���ؼ��ı��ؼ��㣬ָ��Ȩ�صĿؼ����������õ�Ȩ
	// �ؼ��㣬�Զ��߶Ȼ��߿�ȵĿؼ������ȷ���ʣ��Ȩ�ء�
	// 
	
	// 
	// һ����ԣ��ؼ���Ȩ�ر�����[0.0f, 1.0f]�м��ĳ��ֵ��
	// 

	// 
	// �û�ֻ�ܲٿؽ���ؼ����¼������¼���������WPF�Ĵ���
	// ��Ϊ�����ð���������ͣ�������¼��п�����ֹð���¼�
	// �ķ����������¼��Ĵ��������̳к��¼�ע���������档
	// 

	/**
	 * �����ؼ���������[����ؼ�]��[���ֿؼ�]�����������ԡ�
	 */
	class BaseControl
	{
		friend class UserControl;
		friend class LayoutControl;

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
		void* GetWindow() {
			return m_window;
		}

	protected:
		/**
		 * ���ñ��ش���ָ��
		 */
		void SetWindow(void* window) {
			m_window = window;
		}

	protected:
		/**
		 * ���ش���ָ��
		 */
		void* m_window;

	public:
		/**
		 * ���ÿؼ��ڸ��ؼ�������
		 */
		void SetRect(CRect rect) {
			rect_in_parent = rect;
			RecalcLayout();
		}

		/**
		 * ��ȡ�ؼ��ڸ��ؼ�������
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
		 * ���ÿؼ��Ĺ̶����
		 */
		void SetFixSize(CSize size) {
			m_fix_size = size;
		}

		/**
		 * ��ȡ�ؼ��Ĺ̶����
		 */
		CSize GetFixSize() {
			return m_fix_size;
		}

	protected:
		/**
		 * �ؼ��Ĺ̶����
		 */
		CSize m_fix_size;

	public:
		/**
		 * ���ÿؼ��Ĳ���Ȩ��
		 */
		void SetWeight(float weight) {
			m_weight = weight;
		}

		/**
		 * ��ȡ�ؼ��Ĳ���Ȩ��
		 */
		float GetWeight() {
			return m_weight;
		}

	protected:
		/**
		 * �ؼ��Ĳ���Ȩ��
		 */
		float m_weight;

	public:
		/**
		 * ���ÿؼ��Ƿ�����Զ����
		 */
		void SetAutoWidth(BOOL autoWidth) {
			m_auto_width = autoWidth;
		}

		/**
		 * ��ѯ�ؼ��Ƿ�����Զ����
		 */
		BOOL IsAutoWidth() {
			return m_auto_width;
		}

	protected:
		/**
		 * �Ƿ�����Զ����
		 */
		BOOL m_auto_width;

	public:
		/**
		 * ���ÿؼ��Ƿ�����Զ��߶�
		 */
		void SetAutoHeight(BOOL autoHeight) {
			m_auto_height = autoHeight;
		}

		/**
		 * ��ѯ�ؼ��Ƿ�����Զ��߶�
		 */
		BOOL IsAutoHeight() {
			return m_auto_height;
		}

	protected:
		/**
		 * �Ƿ�����Զ��߶�
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
		 * ���ÿؼ����ڱ߾�
		 */
		void SetMargin(CRect margin) {
			m_margin = margin;
		}

		/**
		 * ��ȡ�ؼ����ڱ߾�
		 */
		CRect GetMargin() {
			return m_margin;
		}

	protected:
		/**
		 * �ؼ����ڱ߾�
		 */
		CRect m_margin;

	protected:
		/**
		 * �ػ�ؼ�
		 */
		void Redraw();

		/**
		 * ��ȡ�ؼ�����ͼ����
		 */
		CRect GetViewRect();

		/**
		 * ֪ͨ�ؼ���Ҫ���л�ͼ
		 */
		virtual void Paint(CDC& dc) = 0;

	protected:
		/**
		 * ��굯���¼�
		 */
		virtual void OnMouseUp(CPoint point) = 0;

		/**
		 * ����ƶ��¼�
		 */
		virtual void OnMouseMove(CPoint point) = 0;

		/**
		 * ��갴���¼�
		 */
		virtual void OnMouseDown(CPoint point) = 0;

	protected:
		/**
		 * ���¼����ӿؼ��Ĳ���
		 */
		virtual void RecalcLayout() = 0;

	public:
		/**
		 * ����ָ��ID�Ŀؼ�������ʧ�ܷ��ؿ�ָ��
		 */
		BaseControl* FindControlById(CString id) {
			return OnFindControlById(id);
		}

	protected:
		/**
		 * ����һ���������ID���ҿؼ��Ľӿں���
		 */
		virtual BaseControl* OnFindControlById(CString id) = 0;

	public:
		/**
		 * ����ؼ�����ϸ��Ϣ
		 */
		virtual void Dump() = 0;
	};

}