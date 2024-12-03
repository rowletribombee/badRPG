#include "../../lib/tiles/FightTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

FightTile::FightTile(const string& boss, const vector<string>& rewards){
    this->boss = boss;
    this->rewards = rewards;
    instantEquip = false;
    this->type = fightTile;
}

FightTile::~FightTile(){}

void FightTile::print(){
    // this heavily depends on the fighting mechanics that haven't been added yet
    cout << "Test" << endl;
}