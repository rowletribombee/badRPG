#include <iostream>
#include "../lib/Game.h"
#include "../lib/LoadManager.h"
int main(){
    LoadManager loadmanager;
    Game game;
    loadmanager.loadGame(game);
    game.startGame();
    return 0;
}