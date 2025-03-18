#pragma once

//"Stealing" GLFW keycodes here
// from glfw3.h
//Reason is we need some sort of engine-native keycode definitions,
// that the user on client-app side can refer to when coding.

#define MGENGINE_KEY_SPACE              32
#define MGENGINE_KEY_APOSTROPHE         39  /* ' */
#define MGENGINE_KEY_COMMA              44  /* , */
#define MGENGINE_KEY_MINUS              45  /* - */
#define MGENGINE_KEY_PERIOD             46  /* . */
#define MGENGINE_KEY_SLASH              47  /* / */
#define MGENGINE_KEY_0                  48
#define MGENGINE_KEY_1                  49
#define MGENGINE_KEY_2                  50
#define MGENGINE_KEY_3                  51
#define MGENGINE_KEY_4                  52
#define MGENGINE_KEY_5                  53
#define MGENGINE_KEY_6                  54
#define MGENGINE_KEY_7                  55
#define MGENGINE_KEY_8                  56
#define MGENGINE_KEY_9                  57
#define MGENGINE_KEY_SEMICOLON          59  /* ; */
#define MGENGINE_KEY_EQUAL              61  /* = */
#define MGENGINE_KEY_A                  65
#define MGENGINE_KEY_B                  66
#define MGENGINE_KEY_C                  67
#define MGENGINE_KEY_D                  68
#define MGENGINE_KEY_E                  69
#define MGENGINE_KEY_F                  70
#define MGENGINE_KEY_G                  71
#define MGENGINE_KEY_H                  72
#define MGENGINE_KEY_I                  73
#define MGENGINE_KEY_J                  74
#define MGENGINE_KEY_K                  75
#define MGENGINE_KEY_L                  76
#define MGENGINE_KEY_M                  77
#define MGENGINE_KEY_N                  78
#define MGENGINE_KEY_O                  79
#define MGENGINE_KEY_P                  80
#define MGENGINE_KEY_Q                  81
#define MGENGINE_KEY_R                  82
#define MGENGINE_KEY_S                  83
#define MGENGINE_KEY_T                  84
#define MGENGINE_KEY_U                  85
#define MGENGINE_KEY_V                  86
#define MGENGINE_KEY_W                  87
#define MGENGINE_KEY_X                  88
#define MGENGINE_KEY_Y                  89
#define MGENGINE_KEY_Z                  90
#define MGENGINE_KEY_LEFT_BRACKET       91  /* [ */
#define MGENGINE_KEY_BACKSLASH          92  /* \ */
#define MGENGINE_KEY_RIGHT_BRACKET      93  /* ] */
#define MGENGINE_KEY_GRAVE_ACCENT       96  /* ` */
#define MGENGINE_KEY_WORLD_1            161 /* non-US #1 */
#define MGENGINE_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define MGENGINE_KEY_ESCAPE             256
#define MGENGINE_KEY_ENTER              257
#define MGENGINE_KEY_TAB                258
#define MGENGINE_KEY_BACKSPACE          259
#define MGENGINE_KEY_INSERT             260
#define MGENGINE_KEY_DELETE             261
#define MGENGINE_KEY_RIGHT              262
#define MGENGINE_KEY_LEFT               263
#define MGENGINE_KEY_DOWN               264
#define MGENGINE_KEY_UP                 265
#define MGENGINE_KEY_PAGE_UP            266
#define MGENGINE_KEY_PAGE_DOWN          267
#define MGENGINE_KEY_HOME               268
#define MGENGINE_KEY_END                269
#define MGENGINE_KEY_CAPS_LOCK          280
#define MGENGINE_KEY_SCROLL_LOCK        281
#define MGENGINE_KEY_NUM_LOCK           282
#define MGENGINE_KEY_PRINT_SCREEN       283
#define MGENGINE_KEY_PAUSE              284
#define MGENGINE_KEY_F1                 290
#define MGENGINE_KEY_F2                 291
#define MGENGINE_KEY_F3                 292
#define MGENGINE_KEY_F4                 293
#define MGENGINE_KEY_F5                 294
#define MGENGINE_KEY_F6                 295
#define MGENGINE_KEY_F7                 296
#define MGENGINE_KEY_F8                 297
#define MGENGINE_KEY_F9                 298
#define MGENGINE_KEY_F10                299
#define MGENGINE_KEY_F11                300
#define MGENGINE_KEY_F12                301
#define MGENGINE_KEY_F13                302
#define MGENGINE_KEY_F14                303
#define MGENGINE_KEY_F15                304
#define MGENGINE_KEY_F16                305
#define MGENGINE_KEY_F17                306
#define MGENGINE_KEY_F18                307
#define MGENGINE_KEY_F19                308
#define MGENGINE_KEY_F20                309
#define MGENGINE_KEY_F21                310
#define MGENGINE_KEY_F22                311
#define MGENGINE_KEY_F23                312
#define MGENGINE_KEY_F24                313
#define MGENGINE_KEY_F25                314
#define MGENGINE_KEY_KP_0               320
#define MGENGINE_KEY_KP_1               321
#define MGENGINE_KEY_KP_2               322
#define MGENGINE_KEY_KP_3               323
#define MGENGINE_KEY_KP_4               324
#define MGENGINE_KEY_KP_5               325
#define MGENGINE_KEY_KP_6               326
#define MGENGINE_KEY_KP_7               327
#define MGENGINE_KEY_KP_8               328
#define MGENGINE_KEY_KP_9               329
#define MGENGINE_KEY_KP_DECIMAL         330
#define MGENGINE_KEY_KP_DIVIDE          331
#define MGENGINE_KEY_KP_MULTIPLY        332
#define MGENGINE_KEY_KP_SUBTRACT        333
#define MGENGINE_KEY_KP_ADD             334
#define MGENGINE_KEY_KP_ENTER           335
#define MGENGINE_KEY_KP_EQUAL           336
#define MGENGINE_KEY_LEFT_SHIFT         340
#define MGENGINE_KEY_LEFT_CONTROL       341
#define MGENGINE_KEY_LEFT_ALT           342
#define MGENGINE_KEY_LEFT_SUPER         343
#define MGENGINE_KEY_RIGHT_SHIFT        344
#define MGENGINE_KEY_RIGHT_CONTROL      345
#define MGENGINE_KEY_RIGHT_ALT          346
#define MGENGINE_KEY_RIGHT_SUPER        347
#define MGENGINE_KEY_MENU               348