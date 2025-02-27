#include <MatteoGameEngine.h>

class ExampleLayer : public MGEngine::Layer
{
public:

	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//MGENGINE_INFO("Example layer::Update");
	}

	void OnEvent(const MGEngine::Event& InEvent) override
	{
		MGENGINE_INFO("{0}", InEvent.ToString());
	}
};

class Sandbox : public MGEngine::Application
{
public:

	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

MGEngine::Application* MGEngine::CreateApplication()
{
	return new Sandbox();
}