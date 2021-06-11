#pragma once

#include "Core.h"

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
