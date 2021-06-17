#include "popch.h"
#include "Application.h"

#include "Potato/Events/ApplicationEvent.h"
#include "Potato/Log.h"

namespace Potato {


	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		PO_TRACE(e);

		while (true);
	}
}