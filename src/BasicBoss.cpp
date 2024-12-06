#include "../lib/BasicBoss.h"
#include <iostream>
using namespace std;

void BasicBoss::Bonk(Player& target){
    cout << "The Kellossus was Bonked you! Damage delt: " << damageEnemyPhys(target, 3) << endl;
    
}