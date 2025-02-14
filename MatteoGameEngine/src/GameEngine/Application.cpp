#include "GenginePCH.h"

#include "Application.h"
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"
#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace MGEngine {

	Application::Application()
	{
		//We got unique ptr, so we dont have to manually handle AppWindow deletion when app terminates.
		AppWindow = std::unique_ptr<Window>(Window::Create());
		AppWindow->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
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
	}

	void Application::OnEvent(Event& InEvent)
	{
		EventDispatcher EvDispatcher(InEvent);
		EvDispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		MGENGINE_CORE_TRACE("{0}", InEvent.ToString());
	}

	bool Application::OnWindowClose(WindowClosedEvent& InCloseEvent)
	{
		bRunning = false;
		return true;
	}
}

