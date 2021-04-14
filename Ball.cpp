#include "Ball.h"

using namespace std;

Game game;

Ball::Ball()
{
    x_pos_b = 0;
    y_pos_b = 0;
    width_frame_b = 0;
    height_frame_b = 0;
}

Ball::~Ball()
{

}

bool Ball::LoadImg(string path, SDL_Renderer* screen)
{

}

void Ball::ballFall()
{
    y_pos_b += ball_speed;

    if (y_pos_b > SCREEN_HEIGHT)
    {
        getLives()--;
        isMissed = 1;
    }
}

void Ball::checkColision(Basket* basket)
{
    if (x_pos_b == basket->x_pos_ && y_pos_b == basket->y_pos_)
    {
        y_pos_b = 0;
        getScore() += 50;
        isMissed = 0;
    }
    else
    {
        isMissed = 1;
    }

    if (y_pos_b >= basket->y_pos_)
    {
        if (x_pos_b == basket->x_pos_)
        {
            isMissed = false;
            x_pos_b = 0;
            y_pos_b = 0;
            setRandomPos(0, SCREEN_WIDTH - 80);
            game.getScore()++;
        }
        else
        {
            isMissed = true;
            game.getLives()--;
        }
    }
}

void Ball::setRandomPos(int min_x, int max_x)
{
    int x = rand() % (max_x);
    if (x < min_x) x = min_x;
    this->x_pos_b = x;
}


