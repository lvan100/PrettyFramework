#pragma once

namespace PrettyFramework {

	// 
	// ���ԭ��Ϊ�˼򵥣�ֻ��ʵ��Ϊ�����̳е�ϵͳ��
	// 

	// 
	// �κξ����Ӿ�Ч���Ķ�����Ҫ�̳� @Visual �ӿ�
	// ��������ؼ�����ͼ��״�ȣ�����̳д˽ӿڡ�
	// 

	// 
	// ���ǵ���ƽ̨�ԣ���ͼ��ʹ�� Gdiplus ����ƽ̨����
	// 

	/**
	 * �Ӿ��ӿ�
	 */
	class Visual
	{
	public:
		/**
		 * �����Ӿ���ͼ�ӿ�
		 */
		virtual void Paint(Gdiplus::Graphics& graph) = 0;
	};

}