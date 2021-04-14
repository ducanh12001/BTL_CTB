#ifndef BALL_H
#define BALL_H

#include "CommonFunc.h"
#include "BaseObject.h"
#include "Basket.h"
#include "Game.h"

using namespace std;

class Ball
{

public:
    Ball();
    ~Ball();

    bool LoadImg(string path, SDL_Renderer* screen);
    void ballFall();
    void checkColision(Basket* basket);
    void setRandomPos(int min_x, int max_x);
    bool isMissed;

protected:
    int x_pos_b;
    float y_pos_b;

    int width_frame_b;
    int height_frame_b;
};

#endif // BALL_H
