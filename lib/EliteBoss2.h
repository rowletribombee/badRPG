#pragma once
#include "Player.h"
#include "Enemy.h"

class EliteBoss2 : public Enemy{

        

    public:
        EliteBoss2() = delete;
        EliteBoss2(Stats& baseStats) : Enemy{baseStats}{};
        void Burn(Player&); //Magic, 4
        void Inferno(Player&);  //Magic, 5, does 5 extra true damage
};