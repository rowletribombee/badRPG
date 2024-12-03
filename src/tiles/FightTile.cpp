#include "../../lib/tiles/FightTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

FightTile::FightTile(const string& boss, const vector<Item*>* rewards)
:boss(boss), rewards(rewards) {
    instantEquip = false;
    this->type = fightTile;
}

void FightTile::print(){
    // this heavily depends on the fighting mechanics that haven't been added yet
    cout << "Test" << endl;
}