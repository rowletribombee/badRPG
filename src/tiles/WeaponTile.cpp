#include "../../lib/tiles/WeaponTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

WeaponTile::WeaponTile(Weapon weapon) : weapon(weapon) {
    type = weaponTile;
    visited = false;
}

WeaponTile::~WeaponTile(){}

void WeaponTile::print(){
    srand(static_cast<unsigned int>(time(0)));
    int dialogueVal = rand() % 3;
    cout << dialogue.at(3) << dialogue.at(dialogueVal) << dialogue.at(4);
}