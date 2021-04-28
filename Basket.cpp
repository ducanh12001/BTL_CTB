#include "Basket.h"
#include "BaseObject.h"

using namespace std;

BaseObject bo;

Basket::Basket()
{
    x_pos = 0;
    y_pos = SCREEN_HEIGHT - 80;
    width_frame = 0;
    height_frame = 0;
}

Basket::~Basket() {}

bool Basket::loadImg(SDL_Renderer* screen)
{
    bool ret = bo.LoadImg(basket_path, screen);
    basket_img = bo.p_object;
    if (ret == true)
    {
        width_frame = bo.rect.w;
        height_frame = bo.rect.h;
    }
    return ret;
}

void Basket::renderBasket(SDL_Renderer* des)
{
    bo.rect.x = x_pos;
    bo.rect.y = y_pos;

    SDL_Rect renderQuad = {bo.rect.x, bo.rect.y, width_frame, height_frame};

    SDL_RenderCopy(des, basket_img, NULL, &renderQuad);
}

void Basket::moveBasket(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_RIGHT)
        {
            x_pos += value_move;
            if (x_pos > SCREEN_WIDTH - width_frame)
            {
                x_pos = SCREEN_WIDTH - width_frame;
            }
        }
        if (e.key.keysym.sym == SDLK_LEFT)
        {
            x_pos -= value_move;
            if (x_pos < 0)
            {
                x_pos = 0;
            }
        }
    }
}

bool Basket::checkCollision(Ball &ball)
{
    int l1_x = x_pos + 11;
    int l1_y = y_pos + 50;
    int r1_x = l1_x + width_frame - 24;
    int r1_y = l1_y + height_frame - 70;
    int l2_x = ball.x_pos;
    int l2_y = ball.y_pos;
    int r2_x = l2_x + ball.width_frame;
    int r2_y = l2_y + ball.height_frame;

    if(l1_x >= r2_x || l2_x >= r1_x) return false;
    if(l1_y >= r2_y || l2_y >= r1_y) return false;
    return true;
}

bool Basket::isCatched(Ball &ball)
{
    if(checkCollision(ball))
    {
        int x1 = ball.x_pos + (ball.width_frame / 2);
        int x2 = x_pos;
        if(x1 < x2 || x1 > x2 + width_frame)
        {
            return false;
        }
        else
        {
            //cout<<1;
            ball.check_catched = true;
            return true;
        }
    }
    return false;
}
void Basket::catchFail(Ball &ball, bool &is_quit)
{
    if(ball.check)
    {
        live -= 1;
        ball.check = false;
        if(!live)
        {
            is_quit = true;
        }
    }
}
