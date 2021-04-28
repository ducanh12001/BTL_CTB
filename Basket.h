#ifndef BASKET_H
#define BASKET_H

#include "Ball.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "BaseObject.h"
#include "CommonFunc.h"

using namespace std;

class Basket
{
public:
    Basket();
    ~Basket();
    bool loadImg(SDL_Renderer* des);
    void renderBasket(SDL_Renderer* des);
    void moveBasket(SDL_Event e);
    bool checkCollision(Ball &ball);
    bool isCatched(Ball &ball);

    float x_pos;
    float y_pos;

    int width_frame;
    int height_frame;

    float value_move = 100;

    SDL_Texture *basket_img;
    string basket_path = "img/basket80.png";
    SDL_FRect basket_rect;

    int live = LIVE;
    void catchFail(Ball&, bool &is_quit);
};

#endif // BASKET_H
