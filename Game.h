#ifndef GAME_H
#define GAME_H

#include "Basket.h"
#include "Position.h"

class Game
{
public:
	const int width;
	const int height;
private:
    std::queue<Direction> inputQueue;
    int score;
public:
    Game(int _width, int _height);

    void processUserInput(Direction direction);
};






#endif


