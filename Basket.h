#ifndef BASKET_H
#define BASKET_H

#include <queue>
#include <vector>
#include "Position.h"
#include "CommonFunc.h"
#include "BaseObject.h"

using namespace std;

class Basket : public BaseObject //ke thua
{
public:
    Basket();
    ~Basket();

    enum MoveType
    {
        MOVE_RIGHT = 0,
        MOVE_LEFT = 1
    };

    bool LoadImg(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clips();
    //void doPlayer();
private:
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[5];
    Input input_type_;
    int frame_;
    int status_;//trang thai

};

#endif // BASKET_H
