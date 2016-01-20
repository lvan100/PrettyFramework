#include "stdafx.h"
#include "WindowRes.h"

namespace PrettyFramework {

	shared_ptr<WindowRes> WindowRes::_instance;

	shared_ptr<WindowRes>& WindowRes::GetInstance() {
		if (_instance == nullptr) {
			_instance.reset(new WindowRes);
		}
		return _instance;
	}

}