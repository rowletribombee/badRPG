#include "../../lib/tiles/FightTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

FightTile::FightTile(const string& boss, const vector<Item*> rewards)
:boss(boss), rewards(rewards) {
    instantEquip = false;
    this->type = fightTile;
}

FightTile::~FightTile(){
    for(int i = 0; i < rewards.size(); i++){
        delete rewards[i];
    }
}

void FightTile::print(){
    // this heavily depends on the fighting mechanics that haven't been added yet
    cout << "Test" << endl;
}