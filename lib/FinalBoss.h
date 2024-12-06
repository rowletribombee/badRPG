#pragma once
#include "Player.h"
#include "Enemy.h"

class FinalBoss : public Enemy{


    public:
        int buffCounter = 0; //it's always going to be magic attack
        int chargeCounter = 0;
        FinalBoss() = delete;
        FinalBoss(Stats& baseStats, int xCoord, int yCoord) : Enemy{baseStats}{};
        void Slam(Player&);  //physical, 4
        void Charge(); //m.atk 2x, chargeCounter++ (no resets on either)
        void Explosion(Player&); //magic, 5
        void BackToFull(); 
        void Cleave(Player&); //physical, 5 + chargeCounter
        void Brace(); //def,mdef ++
        void SpeedUp(); //spd++
        void TheEnd(Player&);
};