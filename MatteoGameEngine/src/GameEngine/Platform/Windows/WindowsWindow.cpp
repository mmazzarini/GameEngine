#include "GenginePCH.H"

#include "GameEngine/Platform/Windows/WindowsWindow.h"

#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Log.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace MGEngine
{

	static bool bGLFWInitialized = false;

	static void GLFWErrCallback(int InError, const char* InDescription)
	{
		MGENGINE_CORE_ERROR("GLFW Error ({0}): ({1})", InError, InDescription);
	}

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
			glfwSetErrorCallback(GLFWErrCallback);
			bGLFWInitialized = true;
		}

		InnerWindow = glfwCreateWindow((int)InProperties.Width, (int)InProperties.Height, InProperties.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(InnerWindow);

		//Initialize Glad
		int Status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MGENGINE_ASSERT(status, "Failed to initialize Glad!");
		glfwSetWindowUserPointer(InnerWindow, &InnerData);
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(InnerWindow, [](GLFWwindow* InWindow, int InWidth, int InHeigth)
			{
				WindowData& WData = *(WindowData*)glfwGetWindowUserPointer(InWindow);
				WData.Width = InWidth;
				WData.Height = InHeigth;

				WindowResizeEvent ResEvent(InWidth, InHeigth);
				WData.EventCallback(ResEvent);
			});

		glfwSetWindowCloseCallback(InnerWindow, [](GLFWwindow* InWindow)
			{
				WindowData& WData = *(WindowData*)glfwGetWindowUserPointer(InWindow);
				WindowClosedEvent ClEvent;
				WData.EventCallback(ClEvent);


			});

		glfwSetKeyCallback(InnerWindow, [](GLFWwindow* InWindow, int InKey, int InScancode, int InAction, int InMods)
			{
				WindowData& WData = *(WindowData*)glfwGetWindowUserPointer(InWindow);
				switch (InAction)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent KPrEvent(InKey, 0);
					WData.EventCallback(KPrEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent KRepEvent(InKey, 1);
					WData.EventCallback(KRepEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent KRelEvent(InKey);
					WData.EventCallback(KRelEvent);
					break;
				}
				default:
				{
					break;
				}
				}
			});

		// In principle, I could also return the old callback, i.e. the old ptr stored in InnerWindow->callbacks.mouseButton callback ptr. 
		// See:
		// GLFWmousebuttonfun OldCallback = glfwSetMouseButtonCallback(InnerWindow, [](GLFWwindow* InWindow, int InButton, int InAction, int InMods)
		// But we won't be using any of these ptrs. 
		GLFWmousebuttonfun OldCallback = glfwSetMouseButtonCallback(InnerWindow, [](GLFWwindow* InWindow, int InButton, int InAction, int InMods)
			{
				WindowData& WData = *(WindowData*)glfwGetWindowUserPointer(InWindow);

				switch (InAction)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent MousePressEvent(InButton);
					WData.EventCallback(MousePressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent MouseRelEvent(InButton);
					WData.EventCallback(MouseRelEvent);
					break;
				}
				default:
				{
					break;
				}
				}
			});

		glfwSetScrollCallback(InnerWindow, [](GLFWwindow* InWindow, double InXOffset, double InYOffset)
			{
				WindowData& WData = *(WindowData*)glfwGetWindowUserPointer(InWindow);

				MouseScrolledEvent ScrollEvent((float)InXOffset, (float)InYOffset);
				WData.EventCallback(ScrollEvent); 
			});

		//typedef void (*GLFWcursorposfun)(GLFWwindow* window, double xpos, double ypos);
		glfwSetCursorPosCallback(InnerWindow, [](GLFWwindow* InWindow, double InX, double InY)
			{
				WindowData& WData = *(WindowData*)glfwGetWindowUserPointer(InWindow);

				MouseMovedEvent MouseMoveEvent((float)InX, (float)InY);
				WData.EventCallback(MouseMoveEvent);
			});
	}

	void WindowsWindow::Shutdown()
	{
		//Just destroy the window
		glfwDestroyWindow(InnerWindow);
	}
}