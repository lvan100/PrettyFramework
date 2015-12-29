#pragma once

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
		 * 启动线程
		 */
		void Start();

		/**
		 * 停止线程
		 */
		void Stop();

		/**
		 * 线程执行
		 */
		int Run();

	private:
		/**
		 * 本地线程
		 */
		HANDLE thread;
	};
	
	/**
	 * 获取唯一的界面线程对象
	 */
	UIThread& GetUIThread();

}