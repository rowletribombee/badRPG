#include "../lib/EliteBoss1.h"



void EliteBoss1::Slash(Player& target){
    damageEnemyPhys(target, 4);
}

void EliteBoss1::Thrash(Player& target){  //this one has a weird crit chance so it won't use the Enemy class damage formula
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return;
    }
    else{ //attack hit
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
    cout << "Enemy is enraged! Attack was boosted" << endl;
}