#pragma once

namespace PrettyFramework {

	// 
	// ���ԭ��Ϊ�˼򵥣�ֻ��ʵ��Ϊ�����̳е�ϵͳ��
	// 

	// 
	// �κξ����Ӿ�Ч���Ķ�����Ҫ�̳� @VisualStyle
	// �ӿڣ�������ؼ�����ͼ��״�ȣ�����̳д˽ӿڡ�
	// 

	/**
	 * �Ӿ���ʽ�ӿ�
	 */
	class VisualStyle
	{
	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc) = 0;
	};

}