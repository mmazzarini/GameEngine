#pragma once

#include "Core.h"
#include "Window.h"
#include "Input.h"
#include "GameEngine/Layers/LayersStack.h"
#include "GameEngine/Layers/ImGui/ImGuiLayer.h"

namespace MGEngine {

	class WindowClosedEvent;

	//Base engine class for our Application

	class MATTEO_GENGINE_API Application
	{
	public:
		
		Application();
		
		virtual ~Application();

		static Application& GetApplication();

		void Run();

		void OnEvent(Event& InEvent);

		void PushLayer(Layer* InLayer);

		void PushOverlay(Layer* InLayer);

		inline Window& GetWindow();

	private: 

		bool OnWindowClose(WindowClosedEvent& InCloseEvent);

		void OnUpdateLayers();

		std::unique_ptr<Window> AppWindow;
		ImGuiLayer* AppImGuiLayer;
	
		bool bRunning = true;
	
		LayersStack LayerStack;

		//Singleton ref to Application
		static Application* SingletonAppInstance;
	};
		
	//To be defined inside client
	Application* CreateApplication();
}

