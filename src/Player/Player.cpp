#include "../../lib/Player/Player.h"

void Player::Heal(){
    hp += matk*3;
    if(hp > hpMax){
        hp = hpMax;
    }
}

void Player::Attack(Stats& target) const{
    target.reduceHp(this->atk * 4/target.getDef());
}

void Player::Guard(){
    isGuarding = true;
}


