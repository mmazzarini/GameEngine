#pragma once

//"Stealing" GLFW mouse button codes here
// from glfw3.h
//Reason is we need some sort of engine-native mousecode definitions,
// that the user on client-app side can refer to when coding.

#define MGENGINE_MOUSE_BUTTON_1         0
#define MGENGINE_MOUSE_BUTTON_2         1
#define MGENGINE_MOUSE_BUTTON_3         2
#define MGENGINE_MOUSE_BUTTON_4         3
#define MGENGINE_MOUSE_BUTTON_5         4
#define MGENGINE_MOUSE_BUTTON_6         5
#define MGENGINE_MOUSE_BUTTON_7         6
#define MGENGINE_MOUSE_BUTTON_8         7
#define MGENGINE_MOUSE_BUTTON_LAST      MGENGINE_MOUSE_BUTTON_8
#define MGENGINE_MOUSE_BUTTON_LEFT      MGENGINE_MOUSE_BUTTON_1
#define MGENGINE_MOUSE_BUTTON_RIGHT     MGENGINE_MOUSE_BUTTON_2
#define MGENGINE_MOUSE_BUTTON_MIDDLE    MGENGINE_MOUSE_BUTTON_3