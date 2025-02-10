#pragma once

#include "Core.h"
#include "Window.h"

namespace MGEngine {

	class MATTEO_GENGINE_API Application
	{
	public:
		
		Application();
		
		virtual ~Application();

		void Run();

	private: 
		std::unique_ptr<Window> AppWindow;
		bool bRunning = true;
	};
		
	//To be defined inside client
	Application* CreateApplication();

}

