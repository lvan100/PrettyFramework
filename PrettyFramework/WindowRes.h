#pragma once

#include <map>
#include <memory>
using namespace std;

namespace PrettyFramework {

	/**
	 * ������Դ
	 */
	class WindowRes {

	protected:
		WindowRes() {}

	public:
		/**
		 * ��ȡ��������ľ��
		 */
		static shared_ptr<WindowRes>& GetInstance();

	protected:
		/**
		 * ��������ľ��
		 */
		static shared_ptr<WindowRes> _instance;

	};

}