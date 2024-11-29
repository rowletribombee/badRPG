#include "../lib/Map.h"
#include "../lib/tiles/EmptyTile.h"
#include "../lib/tiles/FightTile.h"
#include "../lib/tiles/SpawnTile.h"
#include "../lib/tiles/PotionTile.h"
#include "../lib/tiles/WeaponTile.h"
Map::Map(){
    initialize();
}

Map::~Map() {
    for (auto& row : mapOfTiles) {
        for (auto& tile : row) {
            delete tile;
        }
    }
}

void Map::initialize(){
    mapOfTiles.resize(8, vector<Tile*>(8, nullptr));
    
    mapOfTiles[0][0] = new FightTile("BasicBoss", {"Reward", "Reward"});
    mapOfTiles[0][1] = new EmptyTile();
    mapOfTiles[0][2] = new PotionTile(Potion("Legendary Potion", 10000));
    mapOfTiles[0][3] = new EmptyTile();
    mapOfTiles[0][4] = new EmptyTile();
    mapOfTiles[0][5] = new FightTile("BasicBoss", {"Reward1", "Reward2"});
    mapOfTiles[0][6] = new WeaponTile("Weapon");
    mapOfTiles[0][7] = new PotionTile(Potion("Potion", 20));

    mapOfTiles[1][0] = new WeaponTile("Weapon");
    mapOfTiles[1][1] = new EmptyTile();
    mapOfTiles[1][2] = new EmptyTile();
    mapOfTiles[1][3] = new FightTile("EliteBoss", {"Reward1", "Reward2"});
    mapOfTiles[1][4] = new WeaponTile("Weapon");
    mapOfTiles[1][5] = new PotionTile(Potion("Rare Potion", 30));
    mapOfTiles[1][6] = new FightTile("EliteBoss", {"Reward1", "Reward2"});
    mapOfTiles[1][7] = new EmptyTile();

    // Continue dynamically allocating memory for all other tiles
    mapOfTiles[2][0] = new FightTile("EliteBoss", {"Reward1", "Reward2"});
    mapOfTiles[2][1] = new FightTile("BasicBoss", {"Reward1", "Reward2"});
    mapOfTiles[2][2] = new PotionTile(Potion("Rare Potion", 30));
    mapOfTiles[2][3] = new EmptyTile();
    mapOfTiles[2][4] = new EmptyTile();
    mapOfTiles[2][5] = new EmptyTile();
    mapOfTiles[2][6] = new EmptyTile();
    mapOfTiles[2][7] = new FightTile("FinalBoss", {"Reward1", "Reward2"});
    mapOfTiles[3][0] = new EmptyTile();
    mapOfTiles[3][1] = new EmptyTile();
    mapOfTiles[3][2] = new WeaponTile("Weapon");
    mapOfTiles[3][3] = new EmptyTile();
    mapOfTiles[3][4] = new PotionTile(Potion("Potion", 20));
    mapOfTiles[3][5] = new EmptyTile();
    mapOfTiles[3][6] = new FightTile("EliteBoss", {"Reward1", "Reward2"});
    mapOfTiles[3][7] = new EmptyTile();

    mapOfTiles[4][0] = new EmptyTile();
    mapOfTiles[4][1] = new PotionTile(Potion("Rare Potion", 30));
    mapOfTiles[4][2] = new FightTile("BasicBoss", {"Reward", "Reward"});
    mapOfTiles[4][3] = new EmptyTile();
    mapOfTiles[4][4] = new FightTile("BasicBoss", {"Reward", "Reward"});
    mapOfTiles[4][5] = new FightTile("BasicBoss", {"Reward", "Reward"});
    mapOfTiles[4][6] = new EmptyTile();
    mapOfTiles[4][7] = new EmptyTile();

    mapOfTiles[5][0] = new EmptyTile();
    mapOfTiles[5][1] = new EmptyTile();
    mapOfTiles[5][2] = new FightTile("EliteBoss", {"Reward1", "Reward2"});
    mapOfTiles[5][3] = new PotionTile(Potion("Epic Potion", 40));
    mapOfTiles[5][4] = new EmptyTile();
    mapOfTiles[5][5] = new WeaponTile("Weapon");
    mapOfTiles[5][6] = new EmptyTile();
    mapOfTiles[5][7] = new PotionTile(Potion("Epic Potion", 40));

    mapOfTiles[6][0] = new WeaponTile("Weapon");
    mapOfTiles[6][1] = new FightTile("BasicBoss", {"Reward", "Reward"});
    mapOfTiles[6][2] = new EmptyTile();
    mapOfTiles[6][3] = new PotionTile(Potion("Potion", 20));
    mapOfTiles[6][4] = new FightTile("BasicBoss", {"Reward", "Reward"});
    mapOfTiles[6][5] = new WeaponTile("Weapon");
    mapOfTiles[6][6] = new EmptyTile();
    mapOfTiles[6][7] = new FightTile("BasicBoss", {"Reward", "Reward"});

    mapOfTiles[7][0] = new SpawnTile();
    mapOfTiles[7][1] = new PotionTile(Potion("Potion", 20));
    mapOfTiles[7][2] = new EmptyTile();
    mapOfTiles[7][3] = new FightTile("BasicBoss", {"Reward1", "Reward2"});
    mapOfTiles[7][4] = new EmptyTile();
    mapOfTiles[7][5] = new EmptyTile();
    mapOfTiles[7][6] = new FightTile("EliteBoss", {"Reward1", "Reward2"});
    mapOfTiles[7][7] = new WeaponTile("Weapon");
}

const vector<vector<Tile*>>& Map::getMapOfTiles() const {
    return mapOfTiles;
}