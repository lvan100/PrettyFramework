#pragma once

#include "UserControl.h"

namespace PrettyFramework {

	class Window : public UserControl
	{
	public:
		Window(LayoutControl* parent);
		virtual ~Window();
	};

}