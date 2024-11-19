#pragma once
#include <string>
using namespace std;
#include "Map.h"
class Player{
    public:
        Player();
        Player(string race);
        void move(Map& map);
        bool checkForWall(char dir);
        bool checkValidDir(char dir);
        int getPositionX() { return positionX; }
        int getPositionY() { return positionY; }
        friend class Screen;
    private:
        int positionX = 0;
        int positionY = 7;
        int baseHp;
        int baseAtk;
        int baseDef;
        int baseMatk;
        int baseMdef;
        int baseSpd;
        int baseLuck;       
};