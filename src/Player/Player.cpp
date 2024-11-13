#include "../../lib/Player/Player.h"

void Player::Heal(){
    hp += matk*3;
    if(hp > hpMax){
        hp = hpMax;
    }
}


