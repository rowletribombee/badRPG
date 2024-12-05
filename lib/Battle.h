#pragma once
#include "FinalBoss.h"
#include "EliteBoss1.h"
#include "EliteBoss2.h"
#include "BasicBoss.h"
#include "Player.h"
#include <iostream>

class Battle{

    public:
        Battle(){}; //initiate once at the beginning to track turns
        
        int finalBoss(Player&, FinalBoss&); //returns 1 for a victory, returns -1 for a loss
        int eliteEnemy1(Player&, EliteBoss1&); 
        int eliteEnemy2(Player&, EliteBoss2&);
        int basicBoss(Player&, BasicBoss&);
        int getTurnCount(){ return turnCount; };

    private:
        int turnCount = 0; //total turncount after all battles
        void takeTurn(Player&, Stats& target); //prompt the player to take their move
        int moveCountPlayer(Player&, Stats&); //moves per turn
        int moveCountEnemy(Player&, Stats&); //moves per turn for enemy (inverse of the other)
        void endTurn(Player& user); //makes sure buffs end, etc;
};