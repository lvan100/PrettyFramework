#pragma once

namespace PrettyFramework {

	// 
	// �κξ����Ӿ�Ч���Ķ�����Ҫ�̳� @VisualStyle
	// �ӿڣ���������ؼ�����ͼ��״������̳д˽ӿڡ�
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