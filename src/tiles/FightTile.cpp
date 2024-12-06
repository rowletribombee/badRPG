#include "../../lib/tiles/FightTile.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

FightTile::FightTile(const string& boss, shared_ptr<Item> reward)
    : boss(boss), reward(reward) {
        instantEquip = false;
        this->type = fightTile;
        visited = false;
}

FightTile::~FightTile(){}

void FightTile::print(){
    // this heavily depends on the fighting mechanics that haven't been added yet
    cout << "You have encountered a(n)" << boss << "!" << endl;
}