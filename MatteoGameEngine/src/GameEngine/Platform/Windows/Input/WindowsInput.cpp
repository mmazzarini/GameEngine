#include "GenginePCH.h"
#include "GameEngine/Platform/Windows/Input/WindowsInput.h"
#include "GameEngine/Application.h"

#include <GLFW/glfw3.h>

namespace MGEngine
{
	Input* Input::Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int InKeyCode)
	{
		Application& App = Application::GetApplication();
		Window& AppWindow = App.GetWindow();
		auto State = glfwGetKey(static_cast<GLFWwindow*>(AppWindow.GetNativeWindow()), InKeyCode);
		return State == GLFW_PRESS || State == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int InKeyCode)
	{
		Application& App = Application::GetApplication();
		Window& AppWindow = App.GetWindow();
		auto State = glfwGetMouseButton(static_cast<GLFWwindow*>(AppWindow.GetNativeWindow()), InKeyCode);
		return State == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl()
	{
		std::pair<double, double> MousePostion = GetMousePositionImpl();
		return static_cast<float>(MousePostion.first);
	}

	float WindowsInput::GetMouseYImpl()
	{
		std::pair<double, double> MousePostion = GetMousePositionImpl();
		return static_cast<float>(MousePostion.second);
	}

	std::pair<double, double> WindowsInput::GetMousePositionImpl()
	{
		Application& App = Application::GetApplication();
		Window& AppWindow = App.GetWindow();
		double XPos, YPos;
		glfwGetCursorPos(static_cast<GLFWwindow*>(AppWindow.GetNativeWindow()), &XPos, &YPos);
		return std::pair<float, float>(XPos, YPos);
	}

}

