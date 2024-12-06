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
        Map& getMap() { return map; }
        Inventory& getInventory() { return inventory; }
        Player& getPlayer(){ return player; }
        void setFirstStageFalse();
        void setSecondStageFalse();
        void setThirdStageFalse();
        void setGameOver() { gameOver = true; }
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
        bool saveState = false;
};