#pragma once
#include <string>
using namespace std;

enum TileType{ spawnTile, emptyTile, fightTile, potionTile, weaponTile };
class Tile{
    protected:
        bool instantEquip;
        TileType type;
        bool visited = false;
    public:
        Tile();
        void setVisited(){ visited = true; }
        bool isVisited() const { return visited; }
        TileType getType() const { return type; }
        virtual void print() = 0;
};