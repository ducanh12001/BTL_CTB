#include "Basket.h"

using namespace std;

Basket::Basket()
{
    frame_ = 0;
    x_pos_ = 0;
    y_pos_ = SCREEN_HEIGHT - 80;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;
    input_type_.left_ = 0;
    input_type_.right_ = 0;
}

Basket::~Basket()
{

}

bool Basket::LoadImg(string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path, screen);
    if (ret == true)
    {
        width_frame_ = rect_.w/4;
        height_frame_ = rect_.h;
    }
    return ret;
}

void Basket::set_clips()
{
    if (width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;
    }
}

void Basket::Show(SDL_Renderer* des)
{
    if (status_ == MOVE_LEFT || status_ == MOVE_RIGHT)
    {
        LoadImg("img/basket80.png", des);
    }

    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* current_clip = &frame_clip_[frame_];

    SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};

    SDL_RenderCopy(des, p_object_, current_clip, &renderQuad);

}

void Basket::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                status_ = MOVE_RIGHT;
                if (x_pos_ < SCREEN_WIDTH - 80)
                {
                    input_type_.right_ = 1;
                    input_type_.left_ = 0;
                    x_pos_ += 80;
                } else {
                    x_pos_ = SCREEN_WIDTH - 80;
                }
            }
            break;
        case SDLK_LEFT:
            {
                status_ = MOVE_LEFT;
                if (x_pos_ > 0)
                {
                input_type_.left_ = 1;
                input_type_.right_ = 0;
                x_pos_ -= 80;
                } else {
                    x_pos_ = 0;
                }
            }
            break;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        switch(events.key.keysym.sym)
        {
        case SDLK_RIGHT:
            {
                input_type_.right_ = 0;
            }
            break;
        case SDLK_LEFT:
            {
                input_type_.left_ = 0;
            }
            break;
        }
    }
}
