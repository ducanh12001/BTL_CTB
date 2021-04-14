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
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;
const int RENDER_DRAW_COLOR = 0xff;

const int SCORE = 0;
const int LIVES = 3;
const int BALL_SPEED = 0.8;

typedef struct Input
{
    int left_, right_;
};

#endif // COMMONFUNC_H
