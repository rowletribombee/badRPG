#include "../../lib/tiles/EmptyTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

EmptyTile::EmptyTile(){
    instantEquip = false;
    type = emptyTile;
    visited = false;
}

EmptyTile::~EmptyTile(){}

void EmptyTile::print(){
    srand(static_cast<unsigned int>(time(0)));
    int dialogueVal = rand() % 3;
    cout << dialogue.at(dialogueVal) << dialogue.at(3);
}