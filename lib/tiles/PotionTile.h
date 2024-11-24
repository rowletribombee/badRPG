#include <vector>
#include <string>
#include "Tile.h"
#include "../Potion.h"
using namespace std;

class PotionTile : public Tile{
    public:
        PotionTile(Potion potion) : potion(potion) {}
        void print();
    private:
        Potion potion;
        vector<string> dialogue = {
            "Ah, an__! Just what I needed—a new addition to my collection of random things that will definitely be useful… eventually… hopefully! \n \n",
            "Look at that! A shiny new " + potion.getName() + "! I’ll take it—who knows when I’ll need to bribe a cave troll? \n \n",
            "Ah, a useful potion! Just what I need to convince myself I’m still making progress in this nightmare. \n \n",
            "You wandered into an potion! You reach down to pick up this shiny new object… \n \n",
            "You’ve received a " + potion.getName() + "! You wonder what you’ll do with it… \n \n"
        };
};