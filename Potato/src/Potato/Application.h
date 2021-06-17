#pragma once

#include "Core.h"
#include "Events\Event.h"

namespace Potato {


	class POTATO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To Be defined by Client
	Application* CreateApplication();
}
