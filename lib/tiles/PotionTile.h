#include <vector>
#include <string>
#include "Tile.h"
using namespace std;

class PotionTile : public Tile{
    public:
        PotionTile(const string& potion) : potion(potion) {}
        void print();
    private:
        string potion;
        vector<string> dialogue = {
            "Ah, an__! Just what I needed—a new addition to my collection of random things that will definitely be useful… eventually… hopefully! \n \n",
            "Look at that! A shiny new __! I’ll take it—who knows when I’ll need to bribe a cave troll? \n \n",
            "Ah, a useful Potion! Just what I need to convince myself I’m still making progress in this nightmare. \n \n",
            "You wandered into an Potion! You reach down to pick up this shiny new object… \n \n",
            "You’ve received a " + potion + "! You wonder what you’ll do with it… \n \n"
        };
};