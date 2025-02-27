#pragma once

#include "GameEngine/Core.h"

namespace MGEngine {

	//Defining events here. These are objects that are handled immediately, i.e, they are processed in a blocking way.

	//Enum containing kind of event. Right now, for each event we have a corresponding class to handle that kind of event.
	enum class EventType
	{
		None = 0,

		//WindowEvents
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		//AppEvents	
		AppTick,
		AppUpdate,
		AppRender,

		//Keys
		KeyPressed,
		KeyReleased,
		KeyTyped, //This is for handling character insertion in text

		//MouseEvents
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(EvType) static EventType GetStaticType() {return EventType::EvType;}\
								 virtual EventType GetEventType() const override {return GetStaticType();}\
								 virtual const char* GetEventName() const override{return #EvType; }

#define EVENT_CLASS_CATEGORY(EvCategory) virtual int GetCategoryFlags() const override {return EventCategory::EvCategory;}

	class MATTEO_GENGINE_API Event
	{
	public:

		friend class EventDispatcher;

		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetEventName(); }

		bool IsInCategory(EventCategory InCategory) const
		{
			return GetCategoryFlags() & InCategory;
		}

		bool Handled = false;

	};

	//Class representing the entity that dispatches events
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:

		EventDispatcher(Event& InEvent)
			: HandledEvent(InEvent)
		{
		}

		//templated function to describe the dispatch of an event
		template<typename T>
		bool Dispatch(EventFn<T> Func)
		{
			if (HandledEvent.GetEventType() == T::GetStaticType())
			{
				HandledEvent.Handled = Func(*(T*)&HandledEvent);
				return true;
			}
			//Default return
			return false;
		}
	private:

		Event& HandledEvent;
	};

	inline std::ostream& operator<<(std::ostream& OStream, const Event& InEvent)
	{
		return OStream << InEvent.ToString();
	}

}