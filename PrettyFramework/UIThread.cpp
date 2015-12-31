#include "stdafx.h"
#include "UIThread.h"

namespace PrettyFramework {

	/**
	 * Ψһ�Ľ����̶߳���
	 */
	UIThread theUIThread;

	UIThread& GetUIThread() {
		return theUIThread;
	}

	UIThread::UIThread()
		: exit_event(INVALID_HANDLE_VALUE)
		, thread(INVALID_HANDLE_VALUE)
		, will_exit(false)
		, thread_id(0)
	{}
	
	UIThread::~UIThread()
	{}

	void UIThread::AddWindow(void* window)
	{
		windows.insert(make_pair(window, false));
	}
	
	void UIThread::RemoveWindow(void* window)
	{
		auto& iter = windows.find(window);
		if (iter != windows.end()) {
			windows.erase(iter);
		}
	}

	void UIThread::UpdateWindow(void* window)
	{
		auto& iter = windows.find(window);
		if (iter != windows.end()) {
			(*iter).second = true;
		}
	}

	/**
	 * �����߳�ִ�к������
	 */
	static DWORD WINAPI UIThreadEntry(LPVOID param)
	{
		UIThread* ui = (UIThread*)param;
		if (ui != nullptr) {
			return ui->Run();
		}
		return 0;
	}

	void UIThread::Start()
	{
		if (thread != INVALID_HANDLE_VALUE) {
			DWORD dwResult = WaitForSingleObject(thread, 0);
			if (WAIT_TIMEOUT == dwResult) {
				return; // ������
			}
		}

		if (exit_event == INVALID_HANDLE_VALUE) {
			exit_event = CreateEvent(nullptr, TRUE, FALSE, nullptr);
		}

		// ������ֱ���������߳�
		thread = CreateThread(NULL, 0, UIThreadEntry, (LPVOID)this
			, CREATE_SUSPENDED, &thread_id);

		// �������̵߳����ȼ�����
		SetThreadPriority(thread, THREAD_PRIORITY_ABOVE_NORMAL);

		// �����˳��¼���֪ͨ�ź�
		ResetEvent(exit_event);
		will_exit = false;

		// ���������߳�
		ResumeThread(thread);
	}

	void UIThread::Stop(int timeout)
	{
		will_exit = true; /* �����˳� */

		DWORD dwResult = WaitForSingleObject(exit_event, timeout);
		if (WAIT_OBJECT_0 != dwResult) { /* δ�ܳɹ��˳� */
			TerminateThread(thread, 0);
		}

		thread = INVALID_HANDLE_VALUE;
		thread_id = 0;

		ResetEvent(exit_event);
		will_exit = false;
	}

	int UIThread::Run()
	{
		while (!will_exit) {

			DWORD dwTick = GetTickCount();

			for (auto& iter = windows.begin();
				 iter != windows.end();
				 iter++)
			{
				if ((*iter).second) {
					::RedrawWindow((HWND)(*iter).first, nullptr, nullptr
						, RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
				}
			}

			DWORD dwRedraw = GetTickCount() - dwTick;
			Sleep(16 - dwRedraw % 16); /* �ȴ� */
		}

		// ֪ͨ�̳߳ɹ��˳�
		SetEvent(exit_event);

		return 0;
	}

}