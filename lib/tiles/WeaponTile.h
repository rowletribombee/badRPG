#include <vector>
#include <string>
#include "Tile.h"
#include "../Weapon.h"
using namespace std;

class WeaponTile : public Tile{
    public:
        WeaponTile(Weapon weapon);
        void print();
        Weapon getWeapon() {return weapon;}
        const vector<string>& getDialogue() const { return dialogue; } //added for testing
    private:
        Weapon weapon;
        vector<string> dialogue = {
            "You think to yourself, \"Man, I really need to go outside more instead of playing Genshin Impact all day\". Anyways, you pick it up! \n\n",
            
            "Wow, something useful for once. Maybe once I get out of here I'll open a(n) " + weapon.getName() + " shop! \n\n",
            
            "Huh, I always thought you needed a license to use one of these...oh well\n\n",
           
            "You were enjoying your fabulous stroll in this depressing cave when suddenly you trip on a massive object... \n\n",
           
            "It is a(n) " + weapon.getName() + "! You pick up this heavy tool and think to yourself that it will be useful in the near future... \n\n"
        };
};