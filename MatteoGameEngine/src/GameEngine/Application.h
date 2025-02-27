#pragma once

#include "Core.h"
#include "Window.h"
#include "GameEngine/Layers/LayersStack.h"

namespace MGEngine {

	class WindowClosedEvent;

	class MATTEO_GENGINE_API Application
	{
	public:
		
		Application();
		
		virtual ~Application();

		void Run();

		void OnEvent(Event& InEvent);

		void PushLayer(Layer* InLayer);

		void PushOverlay(Layer* InLayer);

	private: 

		bool OnWindowClose(WindowClosedEvent& InCloseEvent);

		void OnUpdateLayers();

		std::unique_ptr<Window> AppWindow;
	
		bool bRunning = true;
	
		LayersStack LayerStack;
	};
		
	//To be defined inside client
	Application* CreateApplication();

}

