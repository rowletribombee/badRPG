#include <vector>
#include <string>
#include "Tile.h"
using namespace std;

class FightTile : public Tile{
    public:
        FightTile(const string& boss, const vector<string>& rewards);
        void print();
    private:
        string boss;
        vector<string> rewards;
        vector<string> winDialogueFinalBoss = {
            "You have finally defeated the " + boss + " with a final blow to the head with your trusty (item/weapon used)! \n \n As the "
             + boss + " gasps for air it whispers, \"Fine... you’ve defeated me, but this is just the beginning of your torment.\" \n \n You are awarded: ",
        };
        vector<string> winDialogueEliteBoss = {
            "",
            "",
            "",
        };
        vector<string> winDialogueNormalBoss = {
            "",
            "",
            "",
        };
        vector<string> loseDialogue{
            "OOF… that one hurt… \n ... \n You can see the Wi-Fi slowly fade away from your grasp as you take your last breath…. \n You Died! \n \n",
            "",
            "",
        };
};

// we will need to pass in the prop name of the actual boss + weapon later when we have Player.h file
// more dialogue incoming 