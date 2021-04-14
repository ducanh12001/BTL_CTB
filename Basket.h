#ifndef BASKET_H
#define BASKET_H

#include "CommonFunc.h"
#include "BaseObject.h"
#include "Game.h"

using namespace std;

class Basket
{
public:
    Basket();
    ~Basket();

    enum MoveType
    {
        MOVE_RIGHT = 0, MOVE_LEFT = 1
    };

    bool LoadImg(string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clips();
protected:
    float x_val_;
    float y_val_;

    //vi tri hien tai
    float x_pos_;
    float y_pos_;

    //kich thuoc thuc 1 frame
    int width_frame_;
    int height_frame_;

    Input input_type_;
    static SDL_Rect frame_clip_[4];
    int frame_; // dang o frame nao
    int status_;

};

#endif // BASKET_H
