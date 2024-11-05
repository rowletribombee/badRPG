#include "../../lib/tiles/SpawnTile.h"
#include <iostream>

void SpawnTile::print(){
    if(!visited){
        cout << dialogue.at(0);
    }else{
        cout << dialogue.at(1);
    }
}