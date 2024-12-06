#pragma once
#include "Player.h"
#include "Enemy.h"

class FinalBoss : public Enemy{
    public:
        int buffCounter = 0; //also indicates whether buffs need to be erased at phase change, decrements/resets per action
        int chargeCounter = 0; //accumulating counter, never resets
        FinalBoss() = delete;
        FinalBoss(Stats& baseStats) : Enemy{baseStats}{};
        void Slam(Player&);  //physical, 4
        void Charge(); //m.atk 2x, chargeCounter++ 
        void Explosion(Player&); //magic, 5
        void BackToFull();  //heals 9999 damage 
        void Cleave(Player&); //physical, 5 + chargeCounter
        void Brace(); //def,mdef ++
        void SpeedUp(); //spd++
        void TheEnd(Player&); //deals 9999 damage 
};