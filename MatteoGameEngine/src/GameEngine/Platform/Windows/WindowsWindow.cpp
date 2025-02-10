#include "GenginePCH.H"

#include "GameEngine/Platform/Windows/WindowsWindow.h"

#include "GameEngine/Log.h"

namespace MGEngine
{

	static bool bGLFWInitialized = false;

	Window* Window::Create(const WindowProps& InProperties)
	{
		//Usage example: you can store in a unique_ptr the WindowsWindow ptr returned here
		return new WindowsWindow(InProperties);
	}

	WindowsWindow::WindowsWindow(const WindowProps& InProperties)
	{
		Init(InProperties);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	unsigned int WindowsWindow::GetWidth() const
	{
		return InnerData.Width;
	}

	unsigned int WindowsWindow::GetHeight() const
	{
		return InnerData.Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn& InCallback)
	{
		InnerData.EventCallback = InCallback;
	}

	void WindowsWindow::SetVSync(bool bInEnabled)
	{
		if (bInEnabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		InnerData.bVSync = bInEnabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return InnerData.bVSync;
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(InnerWindow);
	}
	
	void WindowsWindow::Init(const WindowProps& InProperties)
	{
		//We can create multiple windows but we initialize GLFW only once
		InnerData.Title = InProperties.Title;
		InnerData.Width = InProperties.Width;
		InnerData.Height = InProperties.Height;

		MGENGINE_CORE_INFO("Creating window {0} ({1}, {2})", InProperties.Title, InProperties.Width, InProperties.Height);

		if (!bGLFWInitialized)
		{
			//#TODO: glfwTerminate on system shutdown			
			bool bSuccess = glfwInit();
			MGENGINE_CORE_ASSERT(bSuccess, "ERROR: Could not initialize GLFW!");

			bGLFWInitialized = true;
		}

		InnerWindow = glfwCreateWindow((int)InProperties.Width, (int)InProperties.Height, InProperties.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(InnerWindow);
		glfwSetWindowUserPointer(InnerWindow, &InnerData);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		//Just destroy the window
		glfwDestroyWindow(InnerWindow);
	}
}