#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	/**
	 * 界面线程
	 */
	class UIThread
	{
	public:
		UIThread();
		~UIThread();

		/**
		 * 添加本地窗口
		 */
		void AddWindow(void* window);

		/**
		 * 移除本地窗口
		 */
		void RemoveWindow(void* window);

		/**
		 * 刷新窗口
		 */
		void UpdateWindow(void* window);

	private:
		/**
		 * 刷新窗口列表
		 */
		map<void*, bool> windows;

	public:
		/**
		 * 启动线程
		 */
		void Start();

		/**
		 * 停止线程，若超时将强制杀死
		 */
		void Stop(int timeout = INFINITE);

		/**
		 * 线程执行
		 */
		int Run();

	private:
		/**
		 * 本地线程句柄
		 */
		HANDLE thread;

		/**
		 * 本地线程ID号
		 */
		DWORD thread_id;

		/**
		 * 即将结束线程，用于通知线程必须退出
		 */
		volatile bool will_exit;

		/**
		 * 线程退出事件，用于通知线程已经退出
		 */
		HANDLE exit_event;
	};
	
	/**
	 * 获取唯一的界面线程对象
	 */
	UIThread& GetUIThread();

}