#pragma once

#include "GameEngine/Core.h"

/* Input manager class, provided on-Engine side. */

namespace MGEngine
{
	class MATTEO_GENGINE_API Input
	{
	public:

		inline static bool IsKeyPressed(int InKeyCode) { return Instance->IsKeyPressedImpl(InKeyCode); }
		
		inline static bool IsMouseButtonPressed(int InMouseButton) { return Instance->IsMouseButtonPressedImpl(InMouseButton); }
		inline static float GetMouseX() { return Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return Instance->GetMouseYImpl(); }
		inline static std::pair<double, double> GetMousePosition() { return Instance->GetMousePositionImpl(); }

	protected:

		//Inherit and override this, as it is declared pure virtual here.
		virtual bool IsKeyPressedImpl(int InKeyCode) = 0;

		virtual bool IsMouseButtonPressedImpl(int InMouseButton) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<double, double> GetMousePositionImpl() = 0;

	private:

		static Input* Instance;
	};
}