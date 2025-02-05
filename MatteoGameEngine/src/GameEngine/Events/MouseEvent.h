#pragma once

#include "GameEngine/Events/Event.h"
#include "GameEngine/Utilities/MouseCodes.h"

namespace MatteoGameEngine {

	//Judging from the cherno's code:
	//https://github.com/TheCherno/Hazel/blob/master/Hazel/src/Hazel/Events/MouseEvent.h
	//The strategy adopted is: MouseScrolled: 1 class. MouseButton: 1 class. MouseMovced: 1 class
	//We derive mousebutton clicked/Released classes from MouseButton class

	class MATTEO_GENGINE_API MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(const float InXOff, const float InYOff)
			:
			XOffset(InXOff),
			YOffset(InYOff)
		{}
		
		inline float GetXOffset() const { return XOffset; }
		inline float GetYOffset() const { return YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent X,Y: " << XOffset << " , " << YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse);

	private:
		float XOffset;
		float YOffset;
	};

	class MATTEO_GENGINE_API MouseButtonEvent : public Event
	{

	public:

		KeyCode GetKeyCode() const { return MouseButtonValue; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton);

	protected:

		MouseButtonEvent(MouseCode InMouseCode)
			:
			MouseButtonValue(InMouseCode)
		{
		}

		MouseCode MouseButtonValue;
	};

	class MATTEO_GENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(MouseCode InMouseCode)
			:MouseButtonEvent(InMouseCode)
			{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << MouseButtonValue;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class MATTEO_GENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonReleasedEvent(MouseCode InMouseCode)
			:MouseButtonEvent(InMouseCode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << MouseButtonValue;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);

	};

	class MATTEO_GENGINE_API MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(const float InX, const float InY)
			:
			X(InX),
			Y(InY)
		{
		}

		inline float GetX() const { return X; }
		inline float GetY() const { return Y; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent X,Y: " << X << " , " << Y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse);

	private:
		float X;
		float Y;
	};
}