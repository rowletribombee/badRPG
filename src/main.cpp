#include <iostream>
#include "../lib/Game.h"
#include "../lib/LoadManager.h"
int main(){
    LoadManager loadmanager;
    loadmanager.loadGame().startGame();
    return 0;
}