#pragma once
#include "Map.h"
#include "Player.h"
#include "Screen.h"
#include "Inventory.h"
using namespace std;

class Game{
    public:
        Game();
        void startGame(); // this is where we will be prompted to load or start a new game
        void controls();
        void save();
        void setFirstStageFalse();
        void setSecondStageFalse();
        void setThirdStageFalse();
    private:
        Map map;
        Player player;
        Screen screen;
        Inventory inventory;
        bool gameOver = false;
        bool firstStage = true;
        bool secondStage = false;
        bool thirdStage = false;
        bool isSavedGame = false;
};