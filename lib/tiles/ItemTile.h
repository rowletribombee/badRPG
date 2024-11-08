#include <vector>
#include <string>
#include "Tile.h"
using namespace std;

class ItemTile : public Tile{
    public:
        ItemTile(string& item) : item(item) {}
        void print() override;
    private:
        string item;
        vector<string> dialogue = {
            "Ah, an__! Just what I needed—a new addition to my collection of random things that will definitely be useful… eventually… hopefully! \n \n",
            "Look at that! A shiny new __! I’ll take it—who knows when I’ll need to bribe a cave troll? \n \n",
            "Ah, a useful item! Just what I need to convince myself I’m still making progress in this nightmare. \n \n",
            "You wandered into an item! You reach down to pick up this shiny new object… \n \n",
            "You’ve received a " + item + "! You wonder what you’ll do with it… \n \n"
        };
};