
#include <MatteoGameEngine.h>

class Sandbox : public MGEngine::Application
{
public:

	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

MGEngine::Application* MGEngine::CreateApplication()
{
	return new Sandbox();
}