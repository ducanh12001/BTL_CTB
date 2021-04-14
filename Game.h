#ifndef GAME_H
#define GAME_H

#include "CommonFunc.h"
#include "Basket.h"
#include "Ball.h"

class Game
{
public:
    int mapHeight;
    int mapWidth;
    int score = SCORE;
    int lives = LIVES;
    int ball_speed = BALL_SPEED;
    bool isOver = false;
    bool quitGame = false;

    Game(int w, int h);
    int getScore();
    int getLives();
    void play();
};

#endif


