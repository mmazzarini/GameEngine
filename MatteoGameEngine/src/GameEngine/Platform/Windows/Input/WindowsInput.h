#pragma once

#include "GameEngine/Input.h"

namespace MGEngine
{
	class MATTEO_GENGINE_API WindowsInput : public Input
	{

	protected:

		virtual bool IsKeyPressedImpl(int InKeyCode) override;

		virtual bool IsMouseButtonPressedImpl(int InKeyCode) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<double, double> GetMousePositionImpl() override;
	};
}