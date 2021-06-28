#pragma once

#include "Core.h"

#include "Window.h"
#include "Potato\LayerStack.h"
#include "Potato\Events\Event.h"
#include "Potato/Events/ApplicationEvent.h"



namespace Potato {


	class POTATO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To Be defined by Client
	Application* CreateApplication();
}
