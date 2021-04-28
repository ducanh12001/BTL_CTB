#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <iostream>
#include "CommonFunc.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y) {rect.x = x, rect.y = y;}
    SDL_Rect GetRect() const {return rect;}
    SDL_Texture* GetObject() const {return p_object;}

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();

    SDL_Texture* p_object;
    SDL_Rect rect;
};

#endif // BASEOBJECT_H

