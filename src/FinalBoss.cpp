#include "../lib/FinalBoss.h"

Stats& FinalBoss::getStats(){
    return bossStats;
}

void FinalBoss::Slam(Player& target){
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

void FinalBoss::Charge(){
    buffCounter = 2;
    bossStats.addStat("matk",bossStats.getMAtk()); //doubles magic attack
    chargeCounter += 1;
}

void FinalBoss::Explosion(Player& target){
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
}

void FinalBoss::BackToFull(){
    bossStats.addHP(bossStats.getMaxHP());
    revivedOnce = true;
}

void FinalBoss::Cleave(Player& target){
    if(!bossStats.AccuracyCheck(target.getStats())){ //accuracy check on the player, attack misses
        return;
    }
    else{ //attack hit
        int movePower = 5 + chargeCounter;
        if(bossStats.CritCheck(target.getStats())){ //crits deal 1.5x damage and ignore guarding
            target.getStats().reduceHp(bossStats.getAtk() * movePower*1.5/target.getStats().getDef());
        }
        else if(target.isGuarding){ //guarding halves damage
             target.getStats().reduceHp(bossStats.getAtk() * movePower* 0.5/target.getStats().getDef());
        }
        else{ //base attack, nothing special
            target.getStats().reduceHp(bossStats.getAtk() * movePower/target.getStats().getDef());
        }
    }
}

void FinalBoss::Brace(){
    bossStats.addStat("mdef", 1);
    bossStats.addStat("def", 1);
}

void FinalBoss::SpeedUp(){
    bossStats.addStat("spd", 2);
}

void FinalBoss::TheEnd(Player& target){
    target.getStats().reduceHp(9999);
}