#pragma once

namespace PrettyFramework {

	/**
	 * �����߳�
	 */
	class UIThread
	{
	public:
		UIThread();
		~UIThread();

		/**
		 * �����߳�
		 */
		void Start();

		/**
		 * ֹͣ�߳�
		 */
		void Stop();

		/**
		 * �߳�ִ��
		 */
		int Run();

	private:
		/**
		 * �����߳�
		 */
		HANDLE thread;
	};
	
	/**
	 * ��ȡΨһ�Ľ����̶߳���
	 */
	UIThread& GetUIThread();

}