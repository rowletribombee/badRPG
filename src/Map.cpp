#include "../lib/Map.h"
#include "../lib/tiles/EmptyTile.h"
#include "../lib/tiles/FightTile.h"
#include "../lib/tiles/SpawnTile.h"
#include "../lib/tiles/PotionTile.h"
#include "../lib/tiles/WeaponTile.h"
Map::Map(){
    initialize();
}

void Map::initialize(){
    mapOfTiles.resize(8, vector<Tile>(8));
    FightTile fightTile00("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile01;
    PotionTile potionTile02(Potion("Legendary Potion", 10000));
    EmptyTile emptyTile03;
    EmptyTile emptyTile04;
    FightTile fightTile05("BasicBoss", {"Reward1","Reward2"});
    WeaponTile weaponTile06("Weapon");
    PotionTile potionTile07(Potion("Potion", 20));
    WeaponTile weaponTile10("Weapon");
    EmptyTile emptyTile11;
    EmptyTile emptyTile12;
    FightTile fightTile13("EliteBoss", {"Reward1","Reward2"});
    WeaponTile weaponTile14("Weapon");
    PotionTile potionTile15(Potion("Rare Potion", 30));
    FightTile fightTile16("EliteBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile17;
    FightTile fightTile20("EliteBoss", {"Reward1","Reward2"});
    FightTile fightTile21("BasicBoss", {"Reward1","Reward2"});
    PotionTile potionTile22(Potion("Rare Potion", 30));
    EmptyTile emptyTile23;
    EmptyTile emptyTile24;
    EmptyTile emptyTile25;
    EmptyTile emptyTile26;
    FightTile fightTile27("FinalBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile30;
    EmptyTile emptyTile31;
    WeaponTile weaponTile32("Weapon");
    EmptyTile emptyTile33;
    PotionTile potionTile34(Potion("Potion", 20));
    EmptyTile emptyTile35;
    FightTile fightTile36("EliteBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile37;
    EmptyTile emptyTile40;
    PotionTile potionTile41(Potion("Rare Potion", 30));
    FightTile fightTile42("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile43;
    FightTile fightTile44("BasicBoss", {"Reward","Reward"});
    FightTile fightTile45("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile46;
    EmptyTile emptyTile47;
    EmptyTile emptyTile50;
    EmptyTile emptyTile51;
    FightTile fightTile52("EliteBoss", {"Reward1","Reward2"});
    PotionTile potionTile53(Potion("Epic Potion", 40));
    EmptyTile emptyTile54;
    WeaponTile weaponTile55("Weapon");
    EmptyTile emptyTile56;
    PotionTile potionTile57(Potion("Epic Potion", 40));
    WeaponTile weaponTile60("Weapon");
    FightTile fightTile61("BasicBoss", {"Reward","Reward"});
    EmptyTile emptyTile62;
    PotionTile potionTile63(Potion("Potion", 20));
    FightTile fightTile64("BasicBoss", {"Reward","Reward"});
    WeaponTile weaponTile65("Weapon");
    EmptyTile emptyTile66;
    FightTile fightTile67("BasicBoss", {"Reward","Reward"});
    SpawnTile spawnTile70;
    PotionTile potionTile71(Potion("Potion", 20));
    EmptyTile emptyTile72;
    FightTile fightTile73("BasicBoss", {"Reward1","Reward2"});
    EmptyTile emptyTile74;
    EmptyTile emptyTile75;
    FightTile fightTile76("EliteBoss", {"Reward1","Reward2"});
    WeaponTile weaponTile77("Weapon");

    mapOfTiles[0][0] = fightTile00;
    mapOfTiles[0][1] = emptyTile01;
    mapOfTiles[0][2] = potionTile02;
    mapOfTiles[0][3] = emptyTile03;
    mapOfTiles[0][4] = emptyTile04;
    mapOfTiles[0][5] = fightTile05;
    mapOfTiles[0][6] = weaponTile06;
    mapOfTiles[0][7] = potionTile07;
    mapOfTiles[1][0] = weaponTile10;
    mapOfTiles[1][1] = emptyTile11;
    mapOfTiles[1][2] = emptyTile12;
    mapOfTiles[1][3] = fightTile13;
    mapOfTiles[1][4] = weaponTile14;
    mapOfTiles[1][5] = potionTile15;
    mapOfTiles[1][6] = fightTile16;
    mapOfTiles[1][7] = emptyTile17;
    mapOfTiles[2][0] = fightTile20;
    mapOfTiles[2][1] = fightTile21;
    mapOfTiles[2][2] = potionTile22;
    mapOfTiles[2][3] = emptyTile23;
    mapOfTiles[2][4] = emptyTile24;
    mapOfTiles[2][5] = emptyTile25;
    mapOfTiles[2][6] = emptyTile26;
    mapOfTiles[2][7] = fightTile27;
    mapOfTiles[3][0] = emptyTile30;
    mapOfTiles[3][1] = emptyTile31;
    mapOfTiles[3][2] = weaponTile32;
    mapOfTiles[3][3] = emptyTile33;
    mapOfTiles[3][4] = potionTile34;
    mapOfTiles[3][5] = emptyTile35;
    mapOfTiles[3][6] = fightTile36;
    mapOfTiles[3][7] = emptyTile37;
    mapOfTiles[4][0] = emptyTile40;
    mapOfTiles[4][1] = potionTile41;
    mapOfTiles[4][2] = fightTile42;
    mapOfTiles[4][3] = emptyTile43;
    mapOfTiles[4][4] = fightTile44;
    mapOfTiles[4][5] = fightTile45;
    mapOfTiles[4][6] = emptyTile46;
    mapOfTiles[4][7] = emptyTile47;
    mapOfTiles[5][0] = emptyTile50;
    mapOfTiles[5][1] = emptyTile51;
    mapOfTiles[5][2] = fightTile52;
    mapOfTiles[5][3] = potionTile53;
    mapOfTiles[5][4] = emptyTile54;
    mapOfTiles[5][5] = weaponTile55;
    mapOfTiles[5][6] = emptyTile56;
    mapOfTiles[5][7] = potionTile57;
    mapOfTiles[6][0] = weaponTile60;
    mapOfTiles[6][1] = fightTile61;
    mapOfTiles[6][2] = emptyTile62;
    mapOfTiles[6][3] = potionTile63;
    mapOfTiles[6][4] = fightTile64;
    mapOfTiles[6][5] = weaponTile65;
    mapOfTiles[6][6] = emptyTile66;
    mapOfTiles[6][7] = fightTile67;
    mapOfTiles[7][0] = spawnTile70;
    mapOfTiles[7][1] = potionTile71;
    mapOfTiles[7][2] = emptyTile72;
    mapOfTiles[7][3] = fightTile73;
    mapOfTiles[7][4] = emptyTile74;
    mapOfTiles[7][5] = emptyTile75;
    mapOfTiles[7][6] = fightTile76;
    mapOfTiles[7][7] = weaponTile77;
}

const vector<vector<Tile>>& Map::getMapOfTiles() const{
    return mapOfTiles;
}