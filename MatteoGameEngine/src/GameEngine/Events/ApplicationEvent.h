#pragma once

#include "GameEngine/Events/Event.h"
#include <sstream>

namespace MatteoGameEngine {

	class MATTEO_GENGINE_API WindowClosedEvent : public Event
	{
	public:

		WindowClosedEvent() = default;

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class MATTEO_GENGINE_API WindowResizeEvent : public Event
	{
	public:

		WindowResizeEvent(unsigned int InWidth, unsigned int InHeight)
			:
			Width(InWidth),
			Height(InHeight)
		{
		}

		inline unsigned int GetWidth() { return Width;}
		inline unsigned int GetHeight() { return Height; }

		std::string ToString() const override
		{
			std::stringstream Sstream;
			Sstream << "WindowResizedEvent: " << Width << ", " << Height << std::endl;
			return Sstream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	private:

		unsigned int Width;
		unsigned int Height;
	};
}

//N:B: non vedo più la WindowFocusLost/WindowFocus nelle ultime versioni (jan 2025-feb2025)...possibile che siano state rimosse?