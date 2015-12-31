#pragma once

#include <map>
using namespace std;

namespace PrettyFramework {

	// 
	// 界面刷新线程的工作原理: 界面刷新线程通过定时轮询（目前是16ms）
	// 触发所有本地窗口的刷新事件。所有的本地窗口都必须注册到界面线程
	// ，窗口销毁后也需要将其从界面线程删除。当用户触发控件重绘动作的
	// 时候，实际上只是通知界面线程在下一个轮询中刷新该控件所在窗口。
	// 

	/**
	 * 界面刷新线程
	 */
	class UIThread
	{
	public:
		UIThread();
		~UIThread();

		/**
		 * 添加本地窗口句柄
		 */
		void AddWindow(void* window);

		/**
		 * 移除本地窗口句柄
		 */
		void RemoveWindow(void* window);

		/**
		 * 通知刷新本地窗口
		 */
		void UpdateWindow(void* window);

	private:
		/**
		 * 本地刷新窗口列表
		 */
		map<void*, bool> windows;

	public:
		/**
		 * 启动线程
		 */
		void Start();

		/**
		 * 停止线程，如果超时将强制杀死
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