#pragma once
#include "Player.h"
#include "Enemy.h"

class BasicBoss : public Enemy{


    public:
        BasicBoss() = delete;
        BasicBoss(Stats& baseStats) : Enemy{baseStats}{};
        void Bonk(Player&);

    private:
};