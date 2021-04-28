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

    bool loadImg(SDL_Renderer* screen);
    void renderBall(SDL_Renderer* screen);
    void ballMove();
    void resetBall();
    void update_speed();
    bool check_catched = false;
    bool check_missed = false;

    float x_pos;
    float y_pos;
    int width_frame;
    int height_frame;

    double ball_speed = 0.3;
    double max_speed = 1.7;
    double increase_speed = 0.1;
    int count_frame = 0;
    int limit_frame = 5000;

    SDL_Texture *ball_img;
    std::string ball_path = "img/ball80.png";
    SDL_Rect ball_rect;
};

#endif // BALL_H
