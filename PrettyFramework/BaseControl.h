#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Constant.h"
#include "VisualStyle.h"

namespace PrettyFramework {

	//
	// �����ؼ�ģ�ͣ�����ʵ�ֲο�Android��WPF����ģ�͸��
	//

	//
	// ����ͳ�������MFC��ATL��ֻ��һ�ֿؼ��ĸ���������
	// ����������Щ����ⶼ�ڿؼ������ϱ�¶���˺ܴ�Ĳ��㡣
	// �������ֵ�WPF��Ȼ����[�����ؼ�]�ĸ��������ʵ����
	// ��Ȼ���������ܼ����ڽ���ؼ�֮�ڣ���������֪���ǣ�WPF
	// ��ѧϰ���ߺܶ����Ҿ���һ�󲿷���Դ��WPF����ģ�͵ĸ���
	// ������򵥡�ʵ��������ʹ�õĽ���ģ�͸����ʵ���أ�
	// ���������˼��֮���������л����ܹ������Լ��Ĵ𰸣���
	// 

	// 
	// ����һֱ��QT�Ľ���ģ�ͺܸ���Ȥ��������ְҵ���ĵĺܶ�ʱ
	// ������û�л���ȥ�˽��������Ҵ��¹�һ��ʱ���Android��
	// �̺��ҷ���Android�Ľ���ģ�ͺ�����˼��Ҳ�ܼ򵥡����
	// ����һ�����Ϲ������������MFC����ʱ�����ڽ�������Ҫ
	// �����ƻ�����Ե�ɺ�֮��������˼����һ�½Ӵ����ļ�������
	// ģ�ͣ������Լ��Ľ���ģ��������Ҳ�ƺ�����ģ����Ȼ��һ��
	// ʵ��������Խ�������ҵ�˼·Ӧ������ȷ�ġ���
	// 

	// 
	// �Ұѿؼ���Ϊ[����ؼ�]��[���ֿؼ�]���֡�����ؼ�����չ
	// ʾ���ݸ��û����Ŀؼ�����������Ӧ���ͼ�����Ϣ��������
	// ����������Ӧ�������ֿؼ�����ֻ��ͨ�������ӿؼ�������
	// ���ؼ��ڵĿؼ�����ֻ���б����ͱ߿������ּ򵥵��Ӿ�Ч����
	//
	
	// 
	// �����ϣ����ֿؼ����������κ����͵Ŀؼ���Ҳ����˵������ֻ
	// ӵ�н���ؼ���Ҳ����ֻӵ�в��ֿؼ���������ͬʱӵ�н����
	// ���Ͳ��ֿؼ����������趨��ʵ���ǡ������ؼ��������ʵ�֡�
	// ���Ҳ��ֿؼ��ĸ��ؼ��ȿ����ǲ��ֿؼ���Ҳ�����ǽ���ؼ���
	// ��Ȼ�ܿ�����һ�������ĵ����飬����ȫ���ɲ��ֿؼ����ɵĽ�
	// ��ģ����������Ҳ�ǳ����ģ�������ϻ�ͼ��״���һ��������
	// 
	
	//
	// һ������ؼ�ֻ��ӵ��һ�����ֿؼ��������丸�ؼ�Ҳֻ���ǲ�
	// �ֿؼ����������趨�����˽���ؼ������������������ԡ��ᣡ
	// 
	
	//
	// �������Ͽؼ��������ɵ�XML��ʽ�Ľ���ģ�������ļ���ʽ���£�
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
	// ���ֿؼ��ڼ���ؼ�Ȩ�ص�ʱ�򣬹̶���С�Ŀؼ��ᰴ������ռ��
	// �ؼ��Ŀ�߱��ؼ��㣬ָ��Ȩ�صĿؼ����������õ�Ȩ�ؽ��м���
	// �����趨���Զ��߶Ȼ����Զ���ȵĿؼ������ȷ���ʣ���Ȩ�ء�
	// 
	
	// 
	// һ����ԣ��ؼ���Ȩ�ر�����[0.0f,1.0f]�м��ĳ��ֵ�������丸
	// �ؼ���Ȩ���ܺ���1.0f����ô����ӿؼ���Ȩ���ܺͳ�����1.0f��
	// ����ζ����Щ�ӿؼ����ܿ�����������ʾ��������
	// 

	// 
	// �ý���ģ�͵��¼����Ʋ�������WPF�Ĵ�����Ϊ�����ð��������
	// �ͣ��û�����������¼�����ֹð���¼��ķ�������ʵ������¼���
	// ��ʽ������̳к��¼�ע�����֣�������ʹ���Ͼ��кܸߵ�����ԡ�
	// 

	//  
	// ���еĿؼ�Ĭ�϶��Ǿ��Σ����ǲ��ų���������οؼ������Կؼ���
	// ��������Ӧ����ȫ�ɿؼ��Լ���������@BaseControl::HitTest��
	// 

	// 
	// ����ؼ��Ļ�ͼ��ʽ����ģ����ʽ��������ؼ���ֱ�ӻ��ƽ��棬����
	// ����ί�и�һ����ͼģ�壬����������ͨ���滻ģ��ʵ�ָ����Ч����
	// 

	/**
	 * �����ؼ��ӿڣ�������Щ[����ؼ�]��[���ֿؼ�]��������������ԡ�
	 */
	class BaseControl : public VisualStyle
	{
		friend class UserControl;
		friend class LayoutControl;

	public:
		BaseControl(BaseControl* parent);
		virtual ~BaseControl();

		// 
		// 0.����
		// 

	public:
		/**
		 * ��ȡ���ؼ�ָ��
		 */
		BaseControl* GetParent() {
			return m_parent;
		}

	protected:
		/**
		 * ���ؼ�ָ��
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
		 * �ؼ��ڸ��ؼ�������
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

		// 
		// 1.��ͼ
		// 
		
	public:
		/**
		 * �ػ�ؼ�
		 */
		void Redraw();

		/**
		 * ��ȡ�ؼ�����ͼ����
		 */
		CRect GetViewRect();

		// 
		// 2.�¼�
		// 

	public:
		/**
		 * �ؼ��Ƿ񱻻���
		 */
		virtual BOOL HitTest(CPoint point);

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

		// 
		// 3.����
		// 

	protected:
		/**
		 * ���¼����ӿؼ��Ĳ���
		 */
		virtual void RecalcLayout() = 0;

	public:
		/**
		 * ����ָ��ID�Ŀؼ�������ʧ�ܷ��ؿ�ָ��
		 */
		virtual BaseControl* FindControlById(CString id) = 0;

		// 
		// 4.����
		// 

	public:
		/**
		 * ����ؼ�����ϸ��Ϣ
		 */
		virtual void Dump() = 0;
	};

}