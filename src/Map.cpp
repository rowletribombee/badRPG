#include <memory>
#include "../lib/Map.h"
#include "../lib/tiles/EmptyTile.h"
#include "../lib/tiles/FightTile.h"
#include "../lib/tiles/SpawnTile.h"
#include "../lib/tiles/PotionTile.h"
#include "../lib/tiles/WeaponTile.h"
#include "../lib/Item.h"
#include "../lib/Weapon.h"
#include "../lib/Potion.h"
Map::Map(){
    initialize();
}

Map::~Map() {
    for (int i = 0; i < mapOfTiles.size(); i++) {
        for (int j = 0; j < mapOfTiles.at(i).size(); j++) {
            delete mapOfTiles.at(i).at(j);
        }
    }
}

void Map::initialize(){
    mapOfTiles.resize(8, vector<Tile*>(8, nullptr));
    shared_ptr<Item> Excalibur = make_shared<Weapon>("Excalibur", 2, 2, 2, 2, 2, 0);
    shared_ptr<Item> BowOfHouYi = make_shared<Weapon>("Bow of Hou Yi", 0.5, 0, 0.5, 0, 0, 0);
    shared_ptr<Item> Labrys = make_shared<Weapon>("Labrys", 1, -0.3, 1, -0.3, 0, 0);
    shared_ptr<Item> Lance = make_shared<Weapon>("Lance", 1, 0,0,0,1,0);
    shared_ptr<Item> RegularPotion = make_shared<Potion>("Potion", 20);
    shared_ptr<Item> RarePotion = make_shared<Potion>("Rare Potion", 30);
    shared_ptr<Item> EpicPotion = make_shared<Potion>("Epic Potion", 40);
    shared_ptr<Item> LegendaryPotion = make_shared<Potion>("Legendary Potion", 10000); // Assuming -1 indicates full HP restore.

    mapOfTiles[0][0] = new FightTile("Kellossus", EpicPotion);
    mapOfTiles[0][1] = new EmptyTile();
    mapOfTiles[0][2] = new PotionTile(Potion("Legendary Potion", 10000));
    mapOfTiles[0][3] = new EmptyTile();
    mapOfTiles[0][4] = new EmptyTile();
    mapOfTiles[0][5] = new FightTile("Kellossus", Excalibur);
    mapOfTiles[0][6] = new WeaponTile(Weapon("Iron Sword", 1, 1, 0, 0, 0, 0));
    mapOfTiles[0][7] = new PotionTile(Potion("Potion", 20));

    mapOfTiles[1][0] = new WeaponTile(Weapon("Lance", 1, 0, 0, 0, 1, 0));
    mapOfTiles[1][1] = new EmptyTile();
    mapOfTiles[1][2] = new EmptyTile();
    mapOfTiles[1][3] = new FightTile("Sookenstein", BowOfHouYi);
    mapOfTiles[1][4] = new WeaponTile(Weapon("Staff", 0,0,1,1,0,0));
    mapOfTiles[1][5] = new PotionTile(Potion("Rare Potion", 30));
    mapOfTiles[1][6] = new FightTile("Sookenstein",Labrys);
    mapOfTiles[1][7] = new EmptyTile();

    mapOfTiles[2][0] = new FightTile("Sookenstein", LegendaryPotion);
    mapOfTiles[2][1] = new FightTile("Kellossus", RegularPotion);
    mapOfTiles[2][2] = new PotionTile(Potion("Rare Potion", 30));
    mapOfTiles[2][3] = new EmptyTile();
    mapOfTiles[2][4] = new EmptyTile();
    mapOfTiles[2][5] = new EmptyTile();
    mapOfTiles[2][6] = new EmptyTile();
    mapOfTiles[2][7] = new FightTile("Stanimal", Lance);

    mapOfTiles[3][0] = new EmptyTile();
    mapOfTiles[3][1] = new EmptyTile();
    mapOfTiles[3][2] = new WeaponTile(Weapon("Plate Armour", 0,1,0,2,0,0));
    mapOfTiles[3][3] = new EmptyTile();
    mapOfTiles[3][4] = new PotionTile(Potion("Potion", 20));
    mapOfTiles[3][5] = new EmptyTile();
    mapOfTiles[3][6] = new FightTile("Sookenstein", Labrys);
    mapOfTiles[3][7] = new EmptyTile();

    mapOfTiles[4][0] = new EmptyTile();
    mapOfTiles[4][1] = new PotionTile(Potion("Rare Potion", 30));
    mapOfTiles[4][2] = new FightTile("Kellossus", RarePotion);
    mapOfTiles[4][3] = new EmptyTile();
    mapOfTiles[4][4] = new FightTile("Kellossus", EpicPotion);
    mapOfTiles[4][5] = new FightTile("Kellossus", Excalibur);
    mapOfTiles[4][6] = new EmptyTile();
    mapOfTiles[4][7] = new EmptyTile();

    mapOfTiles[5][0] = new EmptyTile();
    mapOfTiles[5][1] = new EmptyTile();
    mapOfTiles[5][2] = new FightTile("Anthocalypse", LegendaryPotion);
    mapOfTiles[5][3] = new PotionTile(Potion("Epic Potion", 40));
    mapOfTiles[5][4] = new EmptyTile();
    mapOfTiles[5][5] = new WeaponTile(Weapon("Iron Sword", 1, 1, 0, 0, 0, 0));
    mapOfTiles[5][6] = new EmptyTile();
    mapOfTiles[5][7] = new PotionTile(Potion("Epic Potion", 40));

    mapOfTiles[6][0] = new WeaponTile(Weapon("Chain Mail", 0, 2, 0, 0, 0, 0));
    mapOfTiles[6][1] = new FightTile("Kellossus", RegularPotion);
    mapOfTiles[6][2] = new EmptyTile();
    mapOfTiles[6][3] = new PotionTile(Potion("Potion", 20));
    mapOfTiles[6][4] = new FightTile("Kellossus", EpicPotion);
    mapOfTiles[6][5] = new WeaponTile(Weapon("Lance", 1, 0, 0, 0, 1, 0));
    mapOfTiles[6][6] = new EmptyTile();
    mapOfTiles[6][7] = new FightTile("Kellossus", RegularPotion);

    mapOfTiles[7][0] = new SpawnTile();
    mapOfTiles[7][1] = new PotionTile(Potion("Potion", 20));
    mapOfTiles[7][2] = new EmptyTile();
    mapOfTiles[7][3] = new FightTile("Kellossus", RarePotion);
    mapOfTiles[7][4] = new EmptyTile();
    mapOfTiles[7][5] = new EmptyTile();
    mapOfTiles[7][6] = new FightTile("Anthocalypse", BowOfHouYi);
    mapOfTiles[7][7] = new WeaponTile(Weapon("Staff", 0,0,1,1,0,0));
}

const vector<vector<Tile*>>& Map::getMapOfTiles() const {
    return mapOfTiles;
}