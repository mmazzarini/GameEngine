#pragma once
//Header file To be included by client applications that employ MatteoGameEngine
//This is to offer an ordered include-files interface to the external apps that load&use this Engine dll.

#include "GameEngine/Application.h"
#include "GameEngine/Log.h"

//------------ ENTRY POINT ----------------

#include "GameEngine/EntryPoint.h"

//------------ EVENTS ---------------------

#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/MouseEvent.h"
