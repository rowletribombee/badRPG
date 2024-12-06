#pragma once
#include "Player.h"
#include "Enemy.h"


class EliteBoss1 : public Enemy{

    private:
        bool enraged = false;
        //drops a weapon on death, but never receives boosts
        

    public:
        EliteBoss1() = delete;
        EliteBoss1(Stats& baseStats) : Enemy{baseStats}{};
        void Slash(Player&);
        void Thrash(Player&);
        void Enrage();
};