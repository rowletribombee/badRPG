#pragma once
#include <vector>
#include "tiles/Tile.h"
using namespace std;

class Map{
    public:
        Map();
        ~Map();
        void initialize();
        const vector<vector<Tile*>>& getMapOfTiles() const;
        friend class Player;
    private:
        vector<vector<Tile*>> mapOfTiles;
};