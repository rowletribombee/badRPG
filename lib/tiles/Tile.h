#pragma once
#include <string>
using namespace std;

enum TileType{ spawnTile, emptyTile, fightTile, potionTile, weaponTile };
class Tile{
    protected:
        bool visited = false;
        bool instantEquip;
        TileType type;
    public:
        Tile();
        ~Tile();
        void setVisited(){ visited = true; }
        bool isVisited() const { return visited; }
        TileType getType() const { return type; }
        virtual void print() = 0;
};