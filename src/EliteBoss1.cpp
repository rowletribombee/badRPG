#include "../lib/EliteBoss1.h"

Stats& EliteBoss1::getStats(){
    return bossStats;
}

void EliteBoss1::Slash(Player& target){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return;
    }
    else{ //attack hit
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(bossStats.getAtk() * 6/target.getStats().getDef());
        }
        else if(target.isGuarding){ //guarding halves damage
             target.getStats().reduceHp(bossStats.getAtk() * 2/target.getStats().getDef());
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(bossStats.getAtk() * 4/target.getStats().getDef());
        }
    }
}

void EliteBoss1::Thrash(Player& target){
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
}