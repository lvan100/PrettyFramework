#pragma once

namespace PrettyFramework {

	// 
	// ���ԭ��Ϊ�˼򵥣�ֻ��ʵ��Ϊ�����̳е�ϵͳ��
	// 

	// 
	// �κξ����Ӿ�Ч���Ķ�����Ҫ�̳� @Visual
	// �ӿڣ�������ؼ�����ͼ��״�ȣ�����̳д˽ӿڡ�
	// 

	/**
	 * �Ӿ��ӿ�
	 */
	class Visual
	{
	public:
		/**
		 * �����Ӿ���ʽ�Ļ�ͼ�ӿ�
		 */
		virtual void Paint(CDC& dc) = 0;
	};

}