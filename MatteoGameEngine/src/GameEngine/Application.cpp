#include "GenginePCH.h"

#include "Application.h"
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace MGEngine {

	Application::Application()
	{
		//We got unique ptr, so we dont have to manually handle AppWindow deletion when app terminates.
		AppWindow = std::unique_ptr<Window>(Window::Create());
		AppWindow->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		unsigned int Id;
		glad_glGenVertexArrays(1, &Id);

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
				
				OnUpdateLayers();

				AppWindow->OnUpdate();

			}
		}
	}

	void Application::OnEvent(Event& InEvent)
	{
		//The meaning of using Dispatch<_Type>(FnType) is that you wrap the Event around a generic call for <WindowClosedEvent> Type.
		//By doing so you can perform an a-priori check to see if the encapsulated function will process the input event,
		//by evaluating the EventType first and then passing it to the FnType function.
		EventDispatcher EvDispatcher(InEvent);
		EvDispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		MGENGINE_CORE_TRACE("{0}", InEvent.ToString());

		for (auto LIt = LayerStack.end(); LIt != LayerStack.begin(); )
		{
			--LIt;
			if ((*LIt) != nullptr)
			{
				(*LIt)->OnEvent(InEvent);
			}
			if (InEvent.Handled)
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer* InLayer)
	{
		LayerStack.PushLayer(InLayer);
	}

	void Application::PushOverlay(Layer* InLayer)
	{
		LayerStack.PushOverlay(InLayer);
	}

	bool Application::OnWindowClose(WindowClosedEvent& InCloseEvent)
	{
		bRunning = false;
		return true;
	}

	void Application::OnUpdateLayers()
	{
		for (Layer* layer : LayerStack)
		{
			layer->OnUpdate();
		}
	}
}

