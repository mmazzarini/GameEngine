#include "GenginePCH.h"

#include "GameEngine/Layers/ImGui/ImGuiLayer.h"

#include "imgui.h"

//#define IMGUI_IMPL_API

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

/*
The idea of an ImGui layer is to use ImGui functionalities to handle 
events related to the User Interface
We adopted ImGui framework and functionalities to give the user the base system 
to handle UI.
BUT: we need some reaction to events, otherwise the UI does not know how to work :)
REMEMBER: we already have a system developed in this Engine that binds to Events.
We have created a Events and a Event-handler system to react to the many 
KeyPressed, KeyReleased, mouse button etc...
So the idea is: we employ these to handle user interface by means of our Events system.
You press a key -> the ImGui layer reacts to this key pressure with the proper event handler (OnEvent()). And so on.
*/

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
		std::cout << "GLFW Version: " << glfwGetVersionString() << std::endl;
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		DEBUG_ImGui_Ptr = &io;
		// Setup Dear ImGui context
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

		//InnerIo.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
		io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;
		io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports; //we need this for renderer correctly showiung docked viewports

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
 		ImGuiStyle& style = ImGui::GetStyle();

		Application& app = Application::GetApplication();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

		//Setup platform renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		ShutDown();
	}

	void ImGuiLayer::OnImGuiRender()
	{
		static bool bShow = true;
		ImGui::ShowDemoWindow(&bShow);
	}

	void ImGuiLayer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::GetApplication();
		Window& window = app.GetWindow();
		io.DisplaySize = ImVec2(window.GetWidth(), window.GetHeight());
		ImGui::Render();
		ImDrawData* DrawData = ImGui::GetDrawData();
		ImGui_ImplOpenGL3_RenderDrawData(DrawData);
	
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImGuiLayer::ShutDown()
	{
		ShutDownImplementation();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::ShutDownImplementation()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	}
}