#pragma once
#include "Player.h"

class FinalBoss{

    private:
        int x, y; //not really sure if it needs this
        Stats bossStats;
        //drops a weapon on death, but never receives boosts
        

    public:
        bool revivedOnce = false;
        int buffCounter = 0; //it's always going to be magic attack
        int chargeCounter = 0;
        FinalBoss() = delete;
        FinalBoss(Stats& baseStats, int xCoord, int yCoord) : x{xCoord}, y{yCoord}, bossStats{baseStats}{};
        Stats& getStats();
        void Slam(Player&);
        void Charge();
        void Explosion(Player&);
        void BackToFull();
        void Cleave(Player&);
        void Brace();
        void SpeedUp();
        void TheEnd(Player&);
};