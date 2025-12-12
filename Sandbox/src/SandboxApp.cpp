#include <MatteoGameEngine.h>

/* example using GLM, taken from GLM github repo */
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}
/* end example importing GLM stuff */

class ExampleLayer : public MGEngine::Layer
{
public:

	ExampleLayer()
		:Layer("Example")
	{
		glm::mat4 cam = camera(5.f, { 0.5f, 0.5f });
	}

	void OnUpdate() override
	{
		//Simple example of OnUpdate() override
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
		//PushOverlay(new MGEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

MGEngine::Application* MGEngine::CreateApplication()
{
	return new Sandbox();
}