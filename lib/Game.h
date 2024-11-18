#pragma once
#include <vector>
#include "tiles/Tile.h"
#include "Map.h"
#include "Player.h"
#include "Screen.h"
#include <string> // this is only temporary
using namespace std;

class Game{
    public:
        Game();
        void startGame(); // this is where we will be prompted to load or start a new game
        friend class Screen;
        friend class Map;
    private:
        Map map;
        Player player;
        Screen screen;
};