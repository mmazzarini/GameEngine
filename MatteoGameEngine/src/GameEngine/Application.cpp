#include "GenginePCH.h"

#include "Application.h"
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"

#include <GLFW/glfw3.h>

namespace MGEngine {

	Application::Application()
	{
		AppWindow = std::unique_ptr<Window>(Window::Create());
		//We got unique ptr, so we dont have to manually handle AppWindow deletion when app terminates.
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		/*
		printf("SOME TEST DEBUG TEXT");
		MGEngine::WindowResizeEvent ResizeEv(1200, 720);
		//HOTFIX Cherno: https://github.com/TheCherno/Hazel/issues/683
		//It is possible that the EventFormatter needs the ToString() returned value.
		MGENGINE_TRACE(ResizeEv.ToString());
		*/

		while (bRunning)
		{
			if (AppWindow != nullptr)
			{
				glClearColor(1, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				AppWindow->OnUpdate();
			}
		}

		while (true);
	}
}

