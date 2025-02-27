#pragma once

#include "GameEngine/Window.h"

struct GLFWwindow;

namespace  MGEngine
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& InProperties);
		virtual ~WindowsWindow();

		virtual unsigned int GetWidth() const override;
		virtual unsigned int GetHeight() const override;

		virtual void SetEventCallback(const EventCallbackFn& InCallback) override;
		virtual void SetVSync(bool bInEnabled) override;
		virtual bool IsVSync() const override;

		void OnUpdate() override;

	private:

		virtual void Init(const WindowProps& InProperties);
		virtual void Shutdown();

		//Struct that defines WindowData
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool bVSync;
			EventCallbackFn EventCallback;
		};

		WindowData InnerData;
		GLFWwindow* InnerWindow;
	};
}