#pragma once
#include "Player.h"

class Enemy{

    protected:
        Stats bossStats;

    public:
        Enemy() = delete;
        Enemy(Stats& baseStats) : bossStats{baseStats}{};
        int damageEnemyPhys(Player&, int);
        int damageEnemyMagic(Player&, int);
        Stats& getStats();

};