#pragma once
#include "FinalBoss.h"
#include "EliteBoss1.h"
#include "EliteBoss2.h"
#include "Boss.h"
#include "Player.h"

class Battle{

    public:
        Battle(){};
        int moveCountPlayer(Stats&, Stats&);
        int moveCountEnemy(Stats&, Stats&);
        int fBoss(Player&, FinalBoss&); 
        int eEnemy1(Player&, EliteBoss1&);
        int eEnemy2(Player&, EliteBoss2&);
        int basicBoss(Player&, Boss&);
        int takeTurn(Player&); //prompt the player to take their move
};