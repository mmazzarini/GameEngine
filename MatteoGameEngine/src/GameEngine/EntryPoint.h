#pragma once

#include <stdio.h>

#ifdef MATTEO_GENGINE_PLATFORM_WINDOWS

extern MGEngine::Application* MGEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Starting Matteo Gengine\n");
	auto* app = MGEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif 
