#include "../lib/EliteBoss2.h"

Stats& EliteBoss2::getStats(){
    return bossStats;
}

void EliteBoss2::Burn(Player& target){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return;
    }
    else{ //attack hit
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(bossStats.getMAtk() * 6/target.getStats().getMDef());
        }
        else if(target.isGuarding){ //guarding halves damage
             target.getStats().reduceHp(bossStats.getMAtk() * 2/target.getStats().getMDef());
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(bossStats.getMAtk() * 4/target.getStats().getMDef());
        }
    }
}

void EliteBoss2::Inferno(Player& target){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return;
    }
    else{ //attack hit
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(bossStats.getMAtk() * 7.5/target.getStats().getMDef());
        }
        else if(target.isGuarding){ //guarding halves damage
             target.getStats().reduceHp(bossStats.getMAtk() * 2.5/target.getStats().getMDef());
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(bossStats.getMAtk() * 5/target.getStats().getMDef());
        }
    }
    target.getStats().reduceHp(3); //true damage, applied regardless of guarding
}
