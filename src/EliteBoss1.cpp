#include "../lib/EliteBoss1.h"



void EliteBoss1::Slash(Player& target){
    cout << "The Sookenstein just Slashed you! Damage dealt: "  << damageEnemyPhys(target, 4) << " damage" << endl;
}

void EliteBoss1::Thrash(Player& target){  //this one has a weird crit chance so it won't use the Enemy class damage formula
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        cout << "The Sookenstein missed the Thrash! Lucky you..." << endl;
        return;
    }
    else{ //attack hit

    //T
        bossStats.addStat("lck", bossStats.getSpd()); //crit chance is now modified for this attack
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(bossStats.getAtk() * 6/target.getStats().getDef());
        }
        else if(target.isGuarding){ //guarding halves damage
             target.getStats().reduceHp(bossStats.getAtk() * 2/target.getStats().getDef());
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(bossStats.getAtk() * 4/target.getStats().getDef());
        }

        bossStats.addStat("lck", (-1*bossStats.getSpd())); //crit chance is now returned to normal
    }
}

void EliteBoss1::Enrage(){
    bossStats.addStat("atk", 3);
    cout << "Sookenstein is enraged! Attack was boosted 3!" << endl;
}