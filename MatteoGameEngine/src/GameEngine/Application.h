#pragma once

#include "Core.h"

namespace MGEngine {

	class MATTEO_GENGINE_API Application
	{
	public:
		
		Application();
		
		virtual ~Application();

		void Run();
	};
		
	//To be defined inside client
	Application* CreateApplication();

}

