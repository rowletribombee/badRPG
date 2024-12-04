#pragma once
#include "Player.h"
#include "Enemy.h"

class Boss : public Enemy{


    public:
        Boss() = delete;
        Boss(Stats& baseStats, int xCoord, int yCoord) : Enemy{baseStats, xCoord, yCoord}{};
        void Bonk(Player&);

};