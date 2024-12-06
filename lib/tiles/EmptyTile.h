#include <vector>
#include <string>
#include "Tile.h"
using namespace std;
class EmptyTile : public Tile{
    public:
        EmptyTile();
        bool isVisited() { return visited; }

        void print() override;
    private:
        vector<string> dialogue = {
            "Ah yes! Exactly what I needed! A whole lot of nothing. \n \n",
            "Great! An empty room. I always wanted a personal space for my existential dread. \n \n",
            "Well, it could be worse, I could be wandering in a cave with no memory and no way out… \n ... \n ... \n wait",
            "Time to move along! \n \n"
        };
};
