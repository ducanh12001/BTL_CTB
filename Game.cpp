#include <iostream>
#include "Game.h"

using namespace std;

//luu tru huong di trong hang doi(bam nhieu nut ltuc)
void Game::processUserInput(Direction direction)
{
    inputQueue.push(direction);
}
