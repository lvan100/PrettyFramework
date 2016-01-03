#pragma once

#include <vector>
#include <memory>
using namespace std;

#include "Visual.h"
#include "Typedef.h"

namespace PrettyFramework {

	//
	// �����ؼ�ģ�ͣ�����ʵ�ֲο�Android��WPF����ģ�͸��
	//

	// 
	// ���ߵ�Ը��: ʹ���ִ�C++��������Android��WPF��QT������
	// ������֮��������򵥡����á���ȫ���ִ�C++�����ܡ�
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
	// �Ұѿؼ���Ϊ[�û��ؼ�]��[���ֿؼ�]���֡��û��ؼ�����չ
	// ʾ���ݸ��û����Ŀؼ�����������Ӧ���ͼ�����Ϣ��������
	// ����������Ӧ�������ֿؼ�����ֻ��ͨ�������ӿؼ�������
	// ���ؼ��ڵĿؼ�����ֻ���б����ͱ߿������ּ򵥵��Ӿ�Ч����
	//
	
	// 
	// �����ϣ����ֿؼ����������κ����͵Ŀؼ���Ҳ����˵������ֻ
	// ӵ���û��ؼ���Ҳ����ֻӵ�в��ֿؼ���������ͬʱӵ���û���
	// ���Ͳ��ֿؼ����������趨��ʵ���ǡ������ؼ��������ʵ�֡�
	// ���Ҳ��ֿؼ��ĸ��ؼ��ȿ����ǲ��ֿؼ���Ҳ�������û��ؼ���
	// ��Ȼ�ܿ�����һ�������ĵ����飬����ȫ���ɲ��ֿؼ����ɵĽ�
	// ��ģ����������Ҳ�ǳ����ģ�������ϻ�ͼ��״���һ��������
	// 
	
	//
	// һ���û��ؼ�ֻ��ӵ��һ�����ֿؼ��������丸�ؼ�Ҳֻ���ǲ�
	// �ֿؼ����������趨�������û��ؼ������������������ԡ��ᣡ
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
	// ÿ�ֿؼ�������̶�����ʾ���򣬵���ͨ���Կؼ���ͼ�񡢱�������
	// ����ɫ�����ԵĶ��ƻ�������ʹ�ؼ��ı�����ʽ���ֶ��������ǳ���
	// �ֶ��ƻ�Ϊ Style����ʽ����ͨ�� Style����ʽ�����ǿ����ڳ�����
	// �п�ʼ��ʱ�򽫿ؼ���ʾ��������Ҫ����ۣ�����ȴ�����������и�
	// ����������ڳ������й����иı�ؼ���ۣ�����Ҫ Theme�����⣩��
	// 

	// 
	// Theme�����⣩��������һ�� Style����ʽ���ļ��ϣ���ͬ�� Theme
	// �����⣩֮������໥�л���������Щ�����໥�л��� Theme�����⣩
	// ���������ͬ�� Style����ʽ���Ķ��塣
	// 

	// 
	// Style����ʽ��֮������м̳й�ϵ����������ʽ�Ḳ�Ǹ���ʽ�е���
	// ͬ���á����ּ̳й�ϵ����ͨ�� XML �ļ����б���:
	// 
	// <Rectangle Name="NormalBackground">
	//     <Item Name="BorderWidth" Value="3" />
	//     <Item Name="CornerSize" Value="10" />
	// </Rectangle>
	// 
	// <Style Name="BigButtonStyle">
	//     <Item Name="FocusColor" Value="#FFFFFFFF" />
	//     <Item Name="Background" Ref="NormalBackground" />
	// </Style>
	// 
	// <Style Name="OtherButtonStyle" Parent="BigButtonStyle" />
	// 

	// 
	// Theme�����⣩֮��Ҳ���м̳й�ϵ��������Ḳ�Ǹ��������ͬ����
	// �����ּ̳й�ϵ����ͨ�� XML �ļ����б���:
	// 
	// <Theme Name="Win7Black">
	//     <Style Name="BigButtonStyle"> ... </Style>
	//     <Style Name="SmallButtonStyle"> ... </Style>
	// </Theme>
	// 
	// <Theme Name="MyWin7Black" Parent="Win7Black">
	//     <Style Name="BigButtonStyle"> ... </Style>
	//     <Style Name="SmallButtonStyle"> ... </Style>
	// </Theme>
	// 

	// 
	// shared_ptr �� weak_ptr ����ʹ��: shared_ptr ���Թ�����������
	// ���ڣ��� weak_ptr ����ͨ���ж� shared_ptr �Ƿ���ڼ���ԭʼ����
	// 

	/**
	 * �����ؼ��ӿڣ����� [�û��ؼ�] �� [���ֿؼ�] ��������������ԡ�
	 */
	class BaseControl : public Visual
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
		// 
		// �ӿؼ������ڸ��ؼ����������ڣ�
		// ��˸��ؼ�ָ����Ա���ȫӵ�С�
		// 

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
		void SetRect(Rect rect) {
			rect_in_parent = rect;
			RecalcLayout();
		}

		/**
		 * ��ȡ�ؼ��ڸ��ؼ�������
		 */
		Rect GetRect() {
			return rect_in_parent;
		}

	protected:
		/**
		 * �ؼ��ڸ��ؼ�������
		 */
		Rect rect_in_parent;

	public:
		/**
		 * ���ÿؼ��Ĺ̶����
		 */
		void SetFixSize(Size size) {
			m_fix_size = size;
		}

		/**
		 * ��ȡ�ؼ��Ĺ̶����
		 */
		Size GetFixSize() {
			return m_fix_size;
		}

	protected:
		/**
		 * �ؼ��Ĺ̶����
		 */
		Size m_fix_size;

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
		void SetMargin(Margin margin) {
			m_margin = margin;
		}

		/**
		 * ��ȡ�ؼ����ڱ߾�
		 */
		Margin GetMargin() {
			return m_margin;
		}

	protected:
		/**
		 * �ؼ����ڱ߾�
		 */
		Margin m_margin;

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
		Rect GetViewRect();

		// 
		// 2.�¼�
		// 

	public:
		/**
		 * �ؼ��Ƿ񱻻���
		 */
		virtual BOOL HitTest(Point point);

	protected:
		/**
		 * ��굯���¼�
		 */
		virtual void OnMouseUp(Point point) = 0;

		/**
		 * ����ƶ��¼�
		 */
		virtual void OnMouseMove(Point point) = 0;

		/**
		 * ��갴���¼�
		 */
		virtual void OnMouseDown(Point point) = 0;

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