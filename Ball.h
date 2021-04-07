#ifndef BALL_H
#define BALL_H

#include "CommonFunc.h"
#include "BaseObject.h"

using namespace std;

class Ball : public BaseObject
{
public:
    Ball();
    ~Ball();

    bool LoadImg(string path, SDL_Renderer* screen);

private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;
};

#endif // BALL_H
