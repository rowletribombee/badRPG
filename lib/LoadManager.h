#pragma once
#include "Game.h"
#include "Screen.h"
class LoadManager{
    public:
        LoadManager();
        Game loadGame();
        Game& loading(Game& game);
    private:
        Screen screen;
};