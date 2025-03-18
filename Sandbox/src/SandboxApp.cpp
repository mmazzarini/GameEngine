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
		if (MGEngine::Input::IsKeyPressed(MGENGINE_KEY_TAB))
		{
			MGENGINE_TRACE("Tab key is pressed!");
		}

	}

	void OnEvent(MGEngine::Event& InEvent) override
	{
		//MGENGINE_INFO("{0}", InEvent.ToString());
		if (InEvent.GetEventType() == MGEngine::EventType::KeyPressed)
		{
			MGEngine::KeyPressedEvent& Ev = static_cast<MGEngine::KeyPressedEvent&>(InEvent);
			MGENGINE_TRACE("{0}", static_cast<char>(Ev.GetKeyCode()));
		}
	}
};

class Sandbox : public MGEngine::Application
{
public:

	Sandbox()
	{
		//In the sandbox app: at ctor time we add the layers we need on our LayerStack.
		PushLayer(new ExampleLayer());
		PushOverlay(new MGEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

MGEngine::Application* MGEngine::CreateApplication()
{
	return new Sandbox();
}