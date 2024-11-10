#include "../lib/Game.h"
#include "../lib/tiles/EmptyTile.h"
#include "../lib/tiles/FightTile.h"
#include "../lib/tiles/SpawnTile.h"
#include "../lib/tiles/ItemTile.h"
#include "../lib/tiles/WeaponTile.h"
#include <iostream>

using namespace std;
Game::Game(){
    initializeMap();
}

void Game::printMap(){
    for(int i = 0; i < mapOfTiles.size(); i++){
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "-------------";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "|           |";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "|    ";
            if(!mapOfTiles.at(i).at(j).isVisited()){
                cout << "???";
            }else{
                cout << " x ";
            }
            cout << "    |";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "|           |";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "-------------";
        }
        cout << endl;
    }
}

void Game::startGame(){
    printMap();
}

void Game::initializeMap(){
    mapOfTiles.resize(8, vector<Tile>(8));
    FightTile fightTile00("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile01;
    ItemTile itemTile02("Item");
    EmptyTile emptyTile03;
    EmptyTile emptyTile04;
    FightTile fightTile05("BasicBoss", {"Reward1","Reward2"});
    WeaponTile weaponTile06("Weapon");
    ItemTile itemTile07("Item");
    WeaponTile weaponTile10("Weapon");
    EmptyTile emptyTile11;
    EmptyTile emptyTile12;
    FightTile fightTile13("EliteBoss", {"Reward1","Reward2"});
    WeaponTile weaponTile14("Weapon");
    ItemTile itemTile15("Item");
    FightTile fightTile16("EliteBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile17;
    FightTile fightTile20("EliteBoss", {"Reward1","Reward2"});
    FightTile fightTile21("BasicBoss", {"Reward1","Reward2"});
    ItemTile itemTile22("Item");
    EmptyTile emptyTile23;
    EmptyTile emptyTile24;
    EmptyTile emptyTile25;
    EmptyTile emptyTile26;
    FightTile fightTile27("FinalBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile30;
    EmptyTile emptyTile31;
    WeaponTile weaponTile32("Weapon");
    EmptyTile emptyTile33;
    ItemTile itemTile34("Item");
    EmptyTile emptyTile35;
    FightTile fightTile36("EliteBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile37;
    EmptyTile emptyTile40;
    ItemTile itemTile41("Item");
    FightTile fightTile42("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile43;
    FightTile fightTile44("BasicBoss", {"Reward","Reward"});
    FightTile fightTile45("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile46;
    EmptyTile emptyTile47;
    EmptyTile emptyTile50;
    EmptyTile emptyTile51;
    FightTile fightTile52("EliteBoss", {"Reward1","Reward2"});
    ItemTile itemTile53("Item");
    EmptyTile emptyTile54;
    WeaponTile weaponTile55("Weapon");
    EmptyTile emptyTile56;
    ItemTile itemTile57("Item");
    WeaponTile weaponTile60("Weapon");
    FightTile fightTile61("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile62;
    ItemTile itemTile63("Item");
    FightTile fightTile64("BasicBoss", {"Reward","Reward"});
    WeaponTile weaponTile65("Weapon");
    EmptyTile emptyTile66;
    FightTile fightTile67("BasicBoss", {"Reward","Reward"});
    SpawnTile spawnTile70;
    ItemTile itemTile71("Item");
    EmptyTile emptyTile72;
    FightTile fightTile73("BasicBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile74;
    EmptyTile emptyTile75;
    FightTile fightTile76("EliteBoss", {"Reward1","Reward2"});
    WeaponTile weaponTile77("Weapon");

    mapOfTiles[0][0] = fightTile00;
    mapOfTiles[0][1] = emptyTile01;
    mapOfTiles[0][2] = itemTile02;
    mapOfTiles[0][3] = emptyTile03;
    mapOfTiles[0][4] = emptyTile04;
    mapOfTiles[0][5] = fightTile05;
    mapOfTiles[0][6] = weaponTile06;
    mapOfTiles[0][7] = itemTile07;
    mapOfTiles[1][0] = weaponTile10;
    mapOfTiles[1][1] = emptyTile11;
    mapOfTiles[1][2] = emptyTile12;
    mapOfTiles[1][3] = fightTile13;
    mapOfTiles[1][4] = weaponTile14;
    mapOfTiles[1][5] = itemTile15;
    mapOfTiles[1][6] = fightTile16;
    mapOfTiles[1][7] = emptyTile17;
    mapOfTiles[2][0] = fightTile20;
    mapOfTiles[2][1] = fightTile21;
    mapOfTiles[2][2] = itemTile22;
    mapOfTiles[2][3] = emptyTile23;
    mapOfTiles[2][4] = emptyTile24;
    mapOfTiles[2][5] = emptyTile25;
    mapOfTiles[2][6] = emptyTile26;
    mapOfTiles[2][7] = fightTile27;
    mapOfTiles[3][0] = emptyTile30;
    mapOfTiles[3][1] = emptyTile31;
    mapOfTiles[3][2] = weaponTile32;
    mapOfTiles[3][3] = emptyTile33;
    mapOfTiles[3][4] = itemTile34;
    mapOfTiles[3][5] = emptyTile35;
    mapOfTiles[3][6] = fightTile36;
    mapOfTiles[3][7] = emptyTile37;
    mapOfTiles[4][0] = emptyTile40;
    mapOfTiles[4][1] = itemTile41;
    mapOfTiles[4][2] = fightTile42;
    mapOfTiles[4][3] = emptyTile43;
    mapOfTiles[4][4] = fightTile44;
    mapOfTiles[4][5] = fightTile45;
    mapOfTiles[4][6] = emptyTile46;
    mapOfTiles[4][7] = emptyTile47;
    mapOfTiles[5][0] = emptyTile50;
    mapOfTiles[5][1] = emptyTile51;
    mapOfTiles[5][2] = fightTile52;
    mapOfTiles[5][3] = itemTile53;
    mapOfTiles[5][4] = emptyTile54;
    mapOfTiles[5][5] = weaponTile55;
    mapOfTiles[5][6] = emptyTile56;
    mapOfTiles[5][7] = itemTile57;
    mapOfTiles[6][0] = weaponTile60;
    mapOfTiles[6][1] = fightTile61;
    mapOfTiles[6][2] = emptyTile62;
    mapOfTiles[6][3] = itemTile63;
    mapOfTiles[6][4] = fightTile64;
    mapOfTiles[6][5] = weaponTile65;
    mapOfTiles[6][6] = emptyTile66;
    mapOfTiles[6][7] = fightTile67;
    mapOfTiles[7][0] = spawnTile70;
    mapOfTiles[7][1] = itemTile71;
    mapOfTiles[7][2] = emptyTile72;
    mapOfTiles[7][3] = fightTile73;
    mapOfTiles[7][4] = emptyTile74;
    mapOfTiles[7][5] = emptyTile75;
    mapOfTiles[7][6] = fightTile76;
    mapOfTiles[7][7] = weaponTile77;
}