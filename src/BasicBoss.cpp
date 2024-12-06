#include "../lib/BasicBoss.h"
#include <iostream>
using namespace std;

void BasicBoss::Bonk(Player& target){
    cout << "The Kellossus just Bonked you! Damage dealt: " << damageEnemyPhys(target, 3) << endl;
    
}