#include "../lib/Enemy.h"

Stats& Enemy::getStats(){
    return bossStats;
}

int Enemy::damageEnemyPhys(Player& target, int basePower){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return 0;
    }
    else{ //attack hit
        int totaldamage = bossStats.getAtk() *basePower/target.getStats().getDef();
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(totaldamage*1.5);
            return totaldamage*1.5;
        }
        else if(target.isGuarding){ //guarding halves damage
            target.getStats().reduceHp(totaldamage*0.5);
            return totaldamage*0.5;
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(totaldamage);
            return totaldamage;
        }
    }
}

int Enemy::damageEnemyMagic(Player& target, int basePower){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return 0;
    }
    else{ //attack hit
        int totaldamage = bossStats.getMAtk() *basePower/target.getStats().getMDef();
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(totaldamage*1.5);
            return totaldamage*1.5;
        }
        else if(target.isGuarding){ //guarding halves damage
            target.getStats().reduceHp(totaldamage*0.5);
            return totaldamage*0.5;
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(totaldamage);
            return totaldamage;
        }
    }
}