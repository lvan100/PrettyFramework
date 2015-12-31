#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	// 
	// ����ˢ���̵߳Ĺ���ԭ��: ����ˢ���߳�ͨ����ʱ��ѯ��Ŀǰ��16ms��
	// �������б��ش��ڵ�ˢ���¼������еı��ش��ڶ�����ע�ᵽ�����߳�
	// ���������ٺ�Ҳ��Ҫ����ӽ����߳�ɾ�������û������ؼ��ػ涯����
	// ʱ��ʵ����ֻ��֪ͨ�����߳�����һ����ѯ��ˢ�¸ÿؼ����ڴ��ڡ�
	// 

	/**
	 * ����ˢ���߳�
	 */
	class UIThread
	{
	public:
		UIThread();
		~UIThread();

		/**
		 * ��ӱ��ش��ھ��
		 */
		void AddWindow(void* window);

		/**
		 * �Ƴ����ش��ھ��
		 */
		void RemoveWindow(void* window);

		/**
		 * ֪ͨˢ�±��ش���
		 */
		void UpdateWindow(void* window);

	private:
		/**
		 * ����ˢ�´����б�
		 */
		map<void*, bool> windows;

	public:
		/**
		 * �����߳�
		 */
		void Start();

		/**
		 * ֹͣ�̣߳������ʱ��ǿ��ɱ��
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