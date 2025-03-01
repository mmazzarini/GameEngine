#pragma once

#include "GameEngine/Layers/Layer.h"

namespace MGEngine
{
	class ImGuiLayer : public Layer
	{

	public:

		ImGuiLayer();

		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(const Event& InEvent) override;

	private:
	};
}