#include <vector>
#include <string>
#include "Tile.h"
using namespace std;

class SpawnTile : public Tile{
    public:
        SpawnTile();
        void print() override;
        void setVisitStateFalse(){firstVisit = false;}
    private:
        bool firstVisit = true;
        vector<string> dialogue = {
            "You wake up in a cave and you crave the internet…",
            "" // placeholder text for dialogue where you get healed
        };
};