#pragma once
#include "Player.h"

class Enemy{

    protected:
        int x, y; //not really sure if it needs this
        Stats bossStats;
        //holds a weapon without actually receiving the stats

    public:
        Enemy() = delete;
        Enemy(Stats& baseStats, int xCoord, int yCoord) : x{xCoord}, y{yCoord}, bossStats{baseStats}{};
        int damageEnemyPhys(Player&, int);
        int damageEnemyMagic(Player&, int);
        Stats& getStats();

};