#pragma once

#include "GameEngine/Events/Event.h"
#include "GameEngine/Utilities/KeyCodes.h"

namespace MatteoGameEngine {

	class MATTEO_GENGINE_API KeyEvent : public Event
	{

	protected: 
		KeyEvent(const KeyCode InKeyCode)
			: KeyValue(InKeyCode) {
		}

	public:

		KeyCode GetKeyCode() const { return KeyValue; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard);

	protected:

		KeyCode KeyValue;
	};

	class MATTEO_GENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:

		KeyPressedEvent(KeyCode InKeyValue, bool InIsRepeat = false)
			:
			KeyEvent(InKeyValue),
			IsRepeat(InIsRepeat)
		{
		}

		bool GetIsRepeat() {
			return IsRepeat;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << KeyValue << " (repeat = " << IsRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
		 
	private:

		bool IsRepeat = false;
	};

	class MATTEO_GENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(KeyCode InKeyValue)
			:KeyEvent(InKeyValue)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << KeyValue;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

	class MATTEO_GENGINE_API KeyTypedEvent : public KeyEvent
	{
	public:

		KeyTypedEvent(KeyCode InKeyValue)
			:KeyEvent(InKeyValue)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << KeyValue;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped);

	};
}