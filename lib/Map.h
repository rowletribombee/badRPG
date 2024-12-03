#pragma once
#include <vector>
#include "../lib/Item.h"
#include "tiles/Tile.h"
using namespace std;

class Map{
    public:
        Map();
        ~Map();
        const vector<vector<Tile*>>& getMapOfTiles() const;
        friend class Player;
    private:
        vector<vector<Tile*>> mapOfTiles;
};