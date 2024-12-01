#pragma once
#include "Player.h"

class Boss{

    private:
        int x, y; //not really sure if it needs this
        Stats bossStats;
        //holds a weapon without actually receiving the stats

    public:
        Boss() = delete;
        Boss(Stats& baseStats, int xCoord, int yCoord) : x{xCoord}, y{yCoord}, bossStats{baseStats}{};
        Stats& getStats();
        void Bonk(Player&);

};