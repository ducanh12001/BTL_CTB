#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(int w, int h)
{
    this->mapWidth = w;
    this->mapHeight = h;
}

int Game::getScore()
{
    return score;
}

int Game::getLives()
{
    return lives;
}

void Game::play()
{
    isOver = false;
    score = 0;
    Basket basket = new Basket();
    Ball ball = new Ball();
    ball->setRandomPos(0, maxWidth - 1);

    int frames = 0;
    while (!isOver)
    {
        if (frames % 2 == 0)
            ball->ballFall();
        frames++;
        ball->checkColision(basket);
        if (quitGame)
        {

        }

    }

    if (isOver)
    {

    }
}
