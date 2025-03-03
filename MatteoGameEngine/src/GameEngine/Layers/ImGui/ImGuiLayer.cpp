#include "GenginePCH.h"

#include "GameEngine/Layers/ImGui/ImGuiLayer.h"

#include "imgui.h"
#include "GameEngine/Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GameEngine/Layers/ImGui/GLFW/ImGuiGLFWImplementation.h"
#include "GameEngine/Platform/Windows/WindowsWindow.h"
#include "imgui_internal.h"
#include "GameEngine/Log.h"

//#MATTEO_TODO Temporary, remove this include in the future
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// - - - - - - - - - - - - - - - - 

#include "GameEngine/Application.h"

namespace MGEngine {

	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
		ShutDown();
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& Io = ImGui::GetIO();
		Io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		Io.BackendFlags != ImGuiBackendFlags_HasSetMousePos;

		bool PressedKeyBools[2] = { false, true };
		for (bool bPressed : PressedKeyBools)
		{
			Io.AddKeyEvent(ImGuiKey_Tab, bPressed);
			Io.AddKeyEvent(ImGuiKey_LeftArrow, bPressed);
			Io.AddKeyEvent(ImGuiKey_RightArrow, bPressed);
			Io.AddKeyEvent(ImGuiKey_UpArrow, bPressed);
			Io.AddKeyEvent(ImGuiKey_DownArrow, bPressed);
			Io.AddKeyEvent(ImGuiKey_PageUp, bPressed);
			Io.AddKeyEvent(ImGuiKey_PageDown, bPressed);
			Io.AddKeyEvent(ImGuiKey_Home, bPressed);
			Io.AddKeyEvent(ImGuiKey_End, bPressed);
			Io.AddKeyEvent(ImGuiKey_Insert, bPressed);
			Io.AddKeyEvent(ImGuiKey_Delete, bPressed);
			Io.AddKeyEvent(ImGuiKey_Backspace, bPressed);
			Io.AddKeyEvent(ImGuiKey_Space, bPressed);
			Io.AddKeyEvent(ImGuiKey_Enter, bPressed);
			Io.AddKeyEvent(ImGuiKey_Escape, bPressed);

		}

		//initialize opengl3 version
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
		//Setup IO
		ImGuiIO& Io = ImGui::GetIO();
		Application* App = Application::GetApplication();
		Io.DisplaySize = ImVec2(App->GetWindow().GetWidth(), App->GetWindow().GetHeight());

		//Update times
		float PreviousTime = 0.f;
		float CurrentTime = static_cast<float>(glfwGetTime());
		Io.DeltaTime = InnerTime > 0.0f ? (CurrentTime - InnerTime) : (1.0f / 60.0f);
		InnerTime = CurrentTime;

		//New frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		//Demo Window
		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		//We render here
		ImGui::Render();
	
		//Draw data
		ImDrawData* DrawData = ImGui::GetDrawData();
		ImGui_ImplOpenGL3_RenderDrawData(DrawData);		
	}

	void ImGuiLayer::OnEvent(Event& InEvent)
	{
		EventDispatcher EvDispatcher(InEvent);
		//#MATTEO_TODO Define macro for binding event functions pls!!
		EvDispatcher.Dispatch<MouseButtonPressedEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnMouseButtonPressed));
		EvDispatcher.Dispatch<MouseButtonReleasedEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnMouseButtonReleased));
		EvDispatcher.Dispatch<MouseScrolledEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnMouseScrolled));
		EvDispatcher.Dispatch<MouseMovedEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnMouseMoved));
		EvDispatcher.Dispatch<KeyPressedEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnKeyPressed));
		EvDispatcher.Dispatch<KeyReleasedEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnKeyReleased));
		EvDispatcher.Dispatch<KeyTypedEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnKeyTyped));
		EvDispatcher.Dispatch<WindowResizeEvent>(MGENGINE_BIND_FN(ImGuiLayer::OnWindowResized));
	}

	bool ImGuiLayer::OnMouseButtonPressed(MouseButtonPressedEvent& InEvent)
	{
		ImGuiIO& Io = ImGui::GetIO();
		if (InEvent.GetKeyCode() >= 0 && InEvent.GetKeyCode() < ImGuiMouseButton_COUNT)
		{
			Io.AddMouseButtonEvent(InEvent.GetKeyCode(), true);
		}
		MGENGINE_CORE_INFO("ImGuiLayer: called Mouse button pressed event with key: {0}", static_cast<unsigned short>(InEvent.GetKeyCode()));

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleased(MouseButtonReleasedEvent& InEvent)
	{
		ImGuiIO& Io = ImGui::GetIO();
		if (InEvent.GetKeyCode() >= 0 && InEvent.GetKeyCode() < ImGuiMouseButton_COUNT)
		{
			Io.AddMouseButtonEvent(InEvent.GetKeyCode(), false);
		}
		MGENGINE_CORE_INFO("ImGuiLayer: called Mouse button released event with key: {0}", static_cast<unsigned short>(InEvent.GetKeyCode()));

		return false;
	}

	bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& InEvent)
	{
		ImGuiIO& Io = ImGui::GetIO();
		Io.AddMouseWheelEvent(static_cast<float>(InEvent.GetXOffset()), static_cast<float>(InEvent.GetYOffset()));
		MGENGINE_CORE_INFO("ImGuiLayer: called Mouse button scrolled event: {0}", InEvent.ToString());

		return false;
	}

	bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& InEvent)
	{
		ImGuiIO& Io = ImGui::GetIO();
		Io.AddMousePosEvent(static_cast<float>(InEvent.GetX()), static_cast<float>(InEvent.GetY()));
		MGENGINE_CORE_INFO("ImGuiLayer: called Mouse button moved event: {0}", InEvent.ToString());

		return false;
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& InEvent)
	{

		ImGuiIO& Io = ImGui::GetIO();
		Io.AddKeyEvent(ImGui_ImplGlfw_KeyToImGuiKey(InEvent.GetKeyCode(), 0), true);
		MGENGINE_CORE_INFO("ImGuiLayer: called key pressed event on: {0}!", static_cast<unsigned short>(InEvent.GetKeyCode()));

		return false;
	}

	bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& InEvent)
	{
		ImGuiIO& Io = ImGui::GetIO();
		Io.AddKeyEvent(ImGui_ImplGlfw_KeyToImGuiKey(InEvent.GetKeyCode(), 0), false);
		MGENGINE_CORE_INFO("ImGuiLayer: called key released event on: {0}!", static_cast<unsigned short>(InEvent.GetKeyCode()));

		return false;
	}

	bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& InEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
		int KeyCode = InEvent.GetKeyCode();
		if (KeyCode > 0 && KeyCode < 0x10000)
		{
			io.AddInputCharacter(InEvent.GetKeyCode());
		}
		MGENGINE_CORE_INFO("ImGuiLayer: called key typed event on: {0}!", static_cast<unsigned short>(InEvent.GetKeyCode()));

		return false;
	}

	bool ImGuiLayer::OnWindowResized(WindowResizeEvent& InEvent)
	{
		ImGuiIO& Io = ImGui::GetIO();
		Io.DisplaySize = ImVec2(InEvent.GetWidth(), InEvent.GetHeight());
		Io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, InEvent.GetWidth(), InEvent.GetHeight());
		MGENGINE_CORE_INFO("ImGuiLayer: called Window resize event: {0} ", InEvent.ToString());
		return false;
	}

	void ImGuiLayer::ShutDown()
	{
		ShutDownImplementations();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::ShutDownImplementations()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	}
}

// #TODO: We almost did everything. 
// We need to map gflw keys to imgui keys in a proper way