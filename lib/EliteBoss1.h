#pragma once
#include "Player.h"

class EliteBoss1{

    private:
        int x, y; //not really sure if it needs this
        Stats bossStats;
        bool enraged = false;
        //drops a weapon on death, but never receives boosts
        

    public:
        EliteBoss1() = delete;
        EliteBoss1(Stats& baseStats, int xCoord, int yCoord) : x{xCoord}, y{yCoord}, bossStats{baseStats}{};
        Stats& getStats();
        void Slash(Player&);
        void Thrash(Player&);
        void Enrage();
};