#pragma once

#include "GameEngine/Layers/Layer.h"

#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/ApplicationEvent.h"

struct ImGuiIO;
struct ImGuiWindow;

namespace MGEngine
{
	class MATTEO_GENGINE_API ImGuiLayer : public Layer
	{

	public:

		ImGuiLayer();

		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		// * * * OLD * * * //
		// virtual void OnUpdate() override;

		void Begin();
		void End();
		//void OnEvent(Event& InEvent) override;

	private:

		void ShutDown();
		void ShutDownImplementation();

		float InnerTime = 0.0f;

		ImGuiIO* DEBUG_ImGui_Ptr;

		ImGuiWindow* NewWiewport;

	};
} 