#include "../lib/EliteBoss2.h"
#include <iostream>
using namespace std;


void EliteBoss2::Burn(Player& target){
    cout << "The Anthocalypse Burned you! Damage delt: " << damageEnemyMagic(target, 4) << endl;
}

void EliteBoss2::Inferno(Player& target){
    target.getStats().reduceHp(3); //true damage, applied regardless of guarding
    cout << "The Anthocalypse used Inferno! Damage delt: " << damageEnemyMagic(target, 5) << endl;

}
