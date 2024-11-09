#pragma once
#include <vector>
#include "tiles/Tile.h"

class Map{
    public:
        Map();
        void print();
    private:
        void initialize();
        vector<vector<Tile>> mapOfTiles; 
};