#pragma once

#include "GameEngine/Layers/Layer.h"

#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/ApplicationEvent.h"

namespace MGEngine
{
	class MATTEO_GENGINE_API ImGuiLayer : public Layer
	{

	public:

		ImGuiLayer();

		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& InEvent) override;

	private:

		bool OnMouseButtonPressed(MouseButtonPressedEvent& InEvent);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& InEvent);
		bool OnMouseScrolled(MouseScrolledEvent& InEvent);
		bool OnMouseMoved(MouseMovedEvent& InEvent);
		bool OnKeyPressed(KeyPressedEvent& InEvent);
		bool OnKeyReleased(KeyReleasedEvent& InEvent);
		bool OnKeyTyped(KeyTypedEvent& InEvent);
		bool OnWindowResized(WindowResizeEvent& InEvent);

		void ShutDown();
		void ShutDownImplementations();

		float InnerTime = 0.0f;
	};
}