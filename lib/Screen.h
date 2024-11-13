#pragma once
#include "tiles/Tile.h"
#include <vector>
using namespace std;
class Screen{
    public:
        Screen();
    private:
        void displayMapScreen(vector<vector<Tile>>& mapOfTiles);
};