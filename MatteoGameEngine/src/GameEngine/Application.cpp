#include "Application.h"
#include <stdio.h>
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Log.h"

namespace MGEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		printf("SOME TEST DEBUG TEXT");

		MatteoGameEngine::WindowResizeEvent ResizeEv(1200, 720);
		//HOTFIX Cherno: https://github.com/TheCherno/Hazel/issues/683
		//It is possible that the EventFormatter needs the ToString() returned value.
		MGENGINE_TRACE(ResizeEv.ToString());

		while (true);
	}
}

