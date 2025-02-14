#pragma once

#include "Core.h"
#include "Window.h"

namespace MGEngine {

	class WindowClosedEvent;

	class MATTEO_GENGINE_API Application
	{
	public:
		
		Application();
		
		virtual ~Application();

		void Run();

		void OnEvent(Event& InEvent);

	private: 

		bool OnWindowClose(WindowClosedEvent& InCloseEvent);

		std::unique_ptr<Window> AppWindow;
		bool bRunning = true;
	};
		
	//To be defined inside client
	Application* CreateApplication();

}

