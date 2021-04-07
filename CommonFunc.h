#ifndef COMMONFUNC_H
#define COMMONFUNC_H

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//Screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;
const int RENDER_DRAW_COLOR = 0xff;

typedef struct Input
{
    int left_, right_;
};

#endif // COMMONFUNC_H
