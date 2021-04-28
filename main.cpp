#include <iostream>
#include <ctime>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SDL_utils.h"
#include "Basket.h"
#include "Ball.h"
#include "CommonFunc.h"
#include "BaseObject.h"
#include "TextObject.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* g_screen;
SDL_Event g_event;

BaseObject g_background;
TTF_Font* font;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
    {
        cout << " Error: " << SDL_GetError() <<endl;
        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        cout << " Error: " << SDL_GetError() <<endl;
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
        {
            cout << " Error: " << SDL_GetError()<<endl;
            success = false;
        }
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
            {
                cout << " Error: " << IMG_GetError() <<endl;
                success = false;
            }
        }
        if (TTF_Init() == -1)
        {
            success = false;
        }
        font = TTF_OpenFont("dlxfont_.ttf", 15);
        if (font == NULL)
        {
            success = false;
        }
    }
    return success;
}

bool loadBackGround()
{
    bool ret = g_background.LoadImg("img/background.png", g_screen);
    if (ret == false)
        return false;
    return true;
}

void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    srand(time(0));
    if (InitData() == false)
        return -1;

    if (loadBackGround() == false)
        return -1;

    Basket basket;
    basket.loadImg(g_screen);
    Ball ball;
    ball.loadImg(g_screen);

    TextObject game_score;
    game_score.setColor(TextObject::WHITE_TEXT);
    int score_val = 0;

    TextObject game_live;
    game_live.setColor(TextObject::WHITE_TEXT);

    bool is_quit = false;
    while(!is_quit)
    {
        ball.update_speed();
        if (basket.isCatched(ball) == true)
        {
            score_val+=10;
        }
        ball.resetBall();
        basket.catchFail(ball, is_quit);
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
            basket.moveBasket(g_event);
        }
        ball.ballMove();
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);

        basket.renderBasket(g_screen);
        ball.renderBall(g_screen);

        //chi so game
        string val_str_score = to_string(score_val);
        string str_score("Score:");
        str_score += val_str_score;
        game_score.setText(str_score);
        game_score.LoadFromRenderText(font, g_screen);
        game_score.RenderText(g_screen, SCREEN_WIDTH*0.5 - 50, 15);

        string val_str_live = to_string(basket.live);
        string str_live("Live:");
        str_live += val_str_live;
        game_live.setText(str_live);
        game_live.LoadFromRenderText(font, g_screen);
        game_live.RenderText(g_screen, 10, 15);

        SDL_RenderPresent(g_screen);
    }
    if (MessageBox(NULL, "Game Over", "Info", MB_OK | MB_ICONSTOP) == IDOK)
    {
        close();
        return 0;
    }
    // close();
    return 0;
}
