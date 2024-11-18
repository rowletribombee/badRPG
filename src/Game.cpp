#include "../lib/Game.h"
#include <iostream>

using namespace std;
Game::Game(){
    
}

void Game::startGame(){
    player.move(map);
    screen.displayMapScreen(map, player);
}
