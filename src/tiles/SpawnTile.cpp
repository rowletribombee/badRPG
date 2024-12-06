#include "../../lib/tiles/SpawnTile.h"
#include <iostream>

SpawnTile::SpawnTile(){
    cout << "HELO WORLD" << endl;
    type = spawnTile;
    cout << "RIZZ WORLD" << endl;

    setVisited();
}

void SpawnTile::print(){
    if(firstVisit){
        cout << dialogue.at(0);
    }else{
        cout << dialogue.at(1);
    }
}