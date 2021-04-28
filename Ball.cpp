#include "Ball.h"
#include "CommonFunc.h"
#include "BaseObject.h"
//BaseObject bo;

Ball::Ball()
{
    x_pos = 0.;
    y_pos = 0.;
    width_frame = 80.;
    height_frame = 80.;
}

Ball::~Ball() {}

bool Ball::loadImg(SDL_Renderer* des)
{
    SDL_Surface* load_surface = IMG_Load(ball_path.c_str());
    if (load_surface != NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        ball_img = SDL_CreateTextureFromSurface(des, load_surface);
        SDL_FreeSurface(load_surface);
    }
    return true;
}

void Ball::renderBall(SDL_Renderer* des)
{
    //bo.rect.x = x_pos;
    //bo.rect.y = y_pos;

    SDL_FRect renderQuad = {x_pos, y_pos, width_frame, height_frame};
    SDL_RenderCopyF(des, ball_img, NULL, &renderQuad);
}

void Ball::ballMove()
{
    y_pos += ball_speed;
}

void Ball::resetBall()
{
    if(y_pos >= SCREEN_HEIGHT || check_catched)
    {
        y_pos = 0;
        if(!check_catched) check = true;
        check_catched = false;
        x_pos = rand() % int(SCREEN_WIDTH / width_frame) * width_frame;
    }
}

void Ball::update_speed()
{
    //std::cout<<count_frame<< std::endl;
    count_frame = (count_frame + 1)%limit_frame;
    if(count_frame % limit_frame == 0)
    {
        ball_speed += (double)increase_speed;
        //std::cout<<ball_speed<< std::endl;
    }
}

