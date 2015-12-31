#pragma once

#include <map>
using namespace std;

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
		 * ��ӱ��ش���
		 */
		void AddWindow(void* window);

		/**
		 * �Ƴ����ش���
		 */
		void RemoveWindow(void* window);

		/**
		 * ˢ�´���
		 */
		void UpdateWindow(void* window);

	private:
		/**
		 * ˢ�´����б�
		 */
		map<void*, bool> windows;

	public:
		/**
		 * �����߳�
		 */
		void Start();

		/**
		 * ֹͣ�̣߳�����ʱ��ǿ��ɱ��
		 */
		void Stop(int timeout = INFINITE);

		/**
		 * �߳�ִ��
		 */
		int Run();

	private:
		/**
		 * �����߳̾��
		 */
		HANDLE thread;

		/**
		 * �����߳�ID��
		 */
		DWORD thread_id;

		/**
		 * ���������̣߳�����֪ͨ�̱߳����˳�
		 */
		volatile bool will_exit;

		/**
		 * �߳��˳��¼�������֪ͨ�߳��Ѿ��˳�
		 */
		HANDLE exit_event;
	};
	
	/**
	 * ��ȡΨһ�Ľ����̶߳���
	 */
	UIThread& GetUIThread();

}