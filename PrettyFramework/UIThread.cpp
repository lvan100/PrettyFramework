#include "stdafx.h"
#include "UIThread.h"

namespace PrettyFramework {

	/**
	 * 唯一的界面线程对象
	 */
	UIThread theUIThread;

	UIThread& GetUIThread() {
		return theUIThread;
	}

	UIThread::UIThread()
	{}
	
	UIThread::~UIThread()
	{}

	/**
	 * 界面线程执行函数入口
	 */
	static DWORD WINAPI UIThreadEntry(LPVOID pParam)
	{
		UIThread* ui = (UIThread*)pParam;
		if (ui != nullptr) {
			return ui->Run();
		}
		return 0;
	}

	void UIThread::Start()
	{
		DWORD nThreadId;
		HANDLE handle = CreateThread(NULL, 0, UIThreadEntry, (LPVOID)this, CREATE_SUSPENDED, &nThreadId);
		SetThreadPriority(handle, THREAD_PRIORITY_ABOVE_NORMAL);
		ResumeThread(handle);
	}

	void UIThread::Stop()
	{

	}

	int UIThread::Run()
	{
		return 0;
	}

}