#pragma once
#include <vector>
#include "tiles/Tile.h"
#include "Map.h"
#include "Screen.h"
using namespace std;

class Game{
    public:
        Game();
        void startGame(); // this is where we will be prompted to load or start a new game
        Screen& getScreen();
        friend class Screen;
        friend class Map;
    private:
        Map map;
        Screen screen; 
};