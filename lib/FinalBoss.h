#pragma once
#include "Player.h"
#include "Enemy.h"

class FinalBoss : public Enemy{


    public:
        bool revivedOnce = false;
        int buffCounter = 0; //it's always going to be magic attack
        int chargeCounter = 0;
        FinalBoss() = delete;
        FinalBoss(Stats& baseStats, int xCoord, int yCoord) : Enemy{baseStats, xCoord, yCoord}{};
        void Slam(Player&);
        void Charge();
        void Explosion(Player&);
        void BackToFull();
        void Cleave(Player&);
        void Brace();
        void SpeedUp();
        void TheEnd(Player&);
};