#pragma once

#include <map>
#include <memory>
using namespace std;

namespace PrettyFramework {

	/**
	 * 窗口资源
	 */
	class WindowRes {

	protected:
		WindowRes() {}

	public:
		/**
		 * 获取单例对象的句柄
		 */
		static shared_ptr<WindowRes>& GetInstance();

	protected:
		/**
		 * 单例对象的句柄
		 */
		static shared_ptr<WindowRes> _instance;

	};

}