#pragma once
#include "FinalBoss.h"
#include "EliteBoss1.h"
#include "EliteBoss2.h"
#include "Boss.h"
#include "Player.h"

class Battle{

    public:
        int FinalBoss(Player&, FinalBoss&); 
        int EliteEnemy1(Player&, EliteBoss1&);
        int EliteEnemy2(Player&, EliteBoss2&);
        int Boss(Player&, Boss&);
};