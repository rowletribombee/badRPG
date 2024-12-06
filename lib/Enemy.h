#pragma once
#include "Player.h"
#include <iostream>

class Enemy{

    protected:
        Stats bossStats;
        int damageEnemyPhys(Player&, int); //helper functions that check accuracy, crit, and do damage (Damage formula)
        int damageEnemyMagic(Player&, int); //these should not be pure virtual, the damage formula is the same for every move

    public:
        Enemy() = delete;
        Enemy(Stats& baseStats) : bossStats{baseStats}{};
        Stats& getStats();

};