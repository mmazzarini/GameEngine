#pragma once

#include <stdio.h>

#ifdef MATTEO_GENGINE_PLATFORM_WINDOWS

//Comment: this method is declared here but it will be likely defined somewhere else, due to the extern keyword
extern MGEngine::Application* MGEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Starting Matteo Gengine\n");
	printf("Created application 7.0\n");

	//Initializing logger
	MGEngine::Log::Init();
	MGENGINE_CORE_WARN("Initialized Log!");
	int a = 3;
	MGENGINE_INFO("Hello! Var={0}", a);

	//Using the previously declared CreateApp() method --> N.B. we don't care about its impl at this stage!
	auto* app = MGEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif 
