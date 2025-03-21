#pragma once
//Header file To be included by client applications that employ MatteoGameEngine
//This is to offer an ordered include-files interface to the external apps that load&use this Engine dll.

#include "GameEngine/Application.h"
#include "GameEngine/Input.h"
#include "GameEngine/Layers/Layer.h"
#include "GameEngine/Layers/ImGui/ImGuiLayer.h"
#include "GameEngine/Log.h"
#include "GameEngine/Utilities/MGEngineKeyCodes.h"
#include "GameEngine/Utilities/MGEngineMouseCodes.h"

//------------ ENTRY POINT ----------------

#include "GameEngine/EntryPoint.h"
