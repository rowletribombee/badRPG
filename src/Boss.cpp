#include "../lib/Boss.h"

void Boss::Bonk(Player& target){
    damageEnemyPhys(target, 3);
}