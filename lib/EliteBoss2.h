#pragma once
#include "Player.h"

class EliteBoss2{

    private:
        int x, y; //not really sure if it needs this
        Stats bossStats;
        //drops a weapon on death, but never receives boosts
        

    public:
        EliteBoss2() = delete;
        EliteBoss2(Stats& baseStats, int xCoord, int yCoord) : x{xCoord}, y{yCoord}, bossStats{baseStats}{};
        Stats& getStats();
        void Burn(Player&);
        void Inferno(Player&);
};