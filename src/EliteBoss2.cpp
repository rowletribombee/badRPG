#include "../lib/EliteBoss2.h"



void EliteBoss2::Burn(Player& target){
    damageEnemyMagic(target, 4);
}

void EliteBoss2::Inferno(Player& target){
    damageEnemyMagic(target, 5);
    target.getStats().reduceHp(3); //true damage, applied regardless of guarding
}
