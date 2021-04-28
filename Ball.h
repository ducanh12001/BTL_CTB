#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Ball
{
public:
    Ball();
    ~Ball();
    bool check = false;
    bool loadImg(SDL_Renderer* res);
    void renderBall(SDL_Renderer* res);
    void ballMove();
    void resetBall();
    bool check_catched = false;

    float x_pos;
    float y_pos;
    double increase_speed = 0.1;
    int count_frame = 0;
    int limit_frame = 5000;
    void update_speed();
    int width_frame;
    int height_frame;

    double ball_speed = 0.2;

    SDL_Texture *ball_img;
    std::string ball_path = "img/ball80.png";
    SDL_Rect ball_rect;
};

#endif // BALL_H
