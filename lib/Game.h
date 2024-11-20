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
        void controls();
        void setFirstStageFalse();
        void setSecondStageFalse();
        void setThirdStageFalse();
    private:
        Map map;
        Player player;
        Screen screen;
        bool gameOver = false;
        bool firstStage = true;
        bool secondStage = false;
        bool thirdStage = false;
};