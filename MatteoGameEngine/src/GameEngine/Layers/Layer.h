#pragma once

#include "GameEngine/Core.h"
#include "GameEngine/Events/Event.h"

namespace MGEngine
{
	class MATTEO_GENGINE_API Layer
	{
	public:

		Layer(const std::string& InName = "Layer");

		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& InEvent) {}

		inline const std::string& GetName();

	protected:

		std::string DebugName;
	};
}