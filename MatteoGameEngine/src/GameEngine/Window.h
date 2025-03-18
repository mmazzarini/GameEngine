#pragma once

#include "GenginePCH.h"

#include "GameEngine/Core.h"
#include "GameEngine/Events/Event.h"

namespace MGEngine
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Matteo Game Engine",
			unsigned int InWidth = 1280,
			unsigned int InHeight = 720)
			: Title(title),
			Width(InWidth),
			Height(InHeight)
		{
		}
	};

		//This is the Window interface class defining the window abstraction and properties.
		//This class is platform independent


	class MATTEO_GENGINE_API Window
	{
	public:

		//This is the std object wrapping a function that can be executed on argument (in this case on Event)
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Attributes
		virtual void SetEventCallback(const EventCallbackFn& InCallback) = 0;
		virtual void SetVSync(bool bInEnabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
 
		//This is to be implemented per platform
		//E.g. return a WindowsWindow or a MacWindow depending on the platform you are
		static Window* Create(const WindowProps& InProperties = WindowProps());
	};
}