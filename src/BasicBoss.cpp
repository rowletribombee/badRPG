#include "../lib/BasicBoss.h"

void BasicBoss::Bonk(Player& target){
    damageEnemyPhys(target, 3);
}