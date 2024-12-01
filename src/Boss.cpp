#include "../lib/Boss.h"

Stats& Boss::getStats(){
    return bossStats;
}

void Boss::Bonk(Player& target){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return;
    }
    else{ //attack hit
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(bossStats.getAtk() * 4.5/target.getStats().getDef());
        }
        else if(target.isGuarding){ //guarding halves damage
             target.getStats().reduceHp(bossStats.getAtk() * 1.5/target.getStats().getDef());
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(bossStats.getAtk() * 3/target.getStats().getDef());
        }
    }
}