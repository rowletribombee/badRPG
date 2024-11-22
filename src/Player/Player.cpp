#include "../../lib/Player.h"


void Player::Heal(){
    baseStats.addHP(baseStats.getMAtk()*3);
}

void Player::Attack(Stats& target) const{
    if(!baseStats.AccuracyCheck(target)){
        return;
    }
    else{
        if(baseStats.CritCheck(target)){
            target.reduceHp(baseStats.getAtk() * 6/target.getDef());
        }
        else{
            target.reduceHp(baseStats.getAtk() * 4/target.getDef());
        }
    }
}

void Player::Guard(){
    isGuarding = true;
}


