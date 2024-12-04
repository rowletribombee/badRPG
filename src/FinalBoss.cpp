#include "../lib/FinalBoss.h"


void FinalBoss::Slam(Player& target){
    damageEnemyPhys(target, 4);
}

void FinalBoss::Charge(){
    buffCounter = 2;
    bossStats.addStat("matk",bossStats.getMAtk()); //doubles magic attack
    chargeCounter += 1;
}

void FinalBoss::Explosion(Player& target){
    damageEnemyMagic(target, 5);
}

void FinalBoss::BackToFull(){
    bossStats.addHP(bossStats.getMaxHP());
    revivedOnce = true;
}

void FinalBoss::Cleave(Player& target){
    damageEnemyPhys(target, 5+chargeCounter);
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