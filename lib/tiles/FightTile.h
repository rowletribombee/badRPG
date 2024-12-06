#include <vector>
#include <memory>
#include <string>
#include "Tile.h"
#include "../Item.h"
using namespace std;

class FightTile : public Tile {
    public:
        FightTile(const string& boss, shared_ptr<Item> reward);

        void print() override;
        string getBoss() const { return boss; }
        shared_ptr<Item> getReward() const { return reward; }
        const vector<string>& getEliteWinDialogue() const { return winDialogueEliteBoss; }
        const vector<string>& getNormalWinDialogue() const { return winDialogueNormalBoss; }
    private:
        string boss;
        shared_ptr<Item> reward;
        vector<string> winDialogueFinalBoss = {
            //There will be three phases each with their own dialogue
            "",
            "",
            ""
        };
        vector<string> winDialogueEliteBoss = {
            
            "You have finally defeated the " + boss + " with a final blow to the head with your trusty weapon! \n \n"
            "As you stand over your enemy, you ask, \n\"I'll ask one more time…what this place is and how did I get here with no memory?\" \n \n"
            "The monster snaps back at you, \n\"I think you'd be better suited to answer that question than me…You know these caves better than anyone else.\" \n \n"
            "Your frustration builds. \n\"Omg can we stop with the games already? What is going on??? Tell me how to get out of here, dude, I'm so hungry and I miss my phone!\" \n \n"
            "As the monster takes its last breath, it mutters, \n\"With time, my friend…with time, you'll have all the answers.\" \n \n"
            "\"Ugh, I'd rather just have all the answers now, but yeah okay, let's keep exploring this TOTALLY NOT creepy cave. Sounds like a blast.\" \n \n"
            "You leave with more questions than you began with and a new passion to get out of this place as the " + boss + " leaves a(n) " + reward->getName() + " behind.",
            
            "With one final strike, the " + boss + " falls to the ground, defeated. \n \n"
            "Panting, you shout, \"Who keeps sending you guys? What do you want from me?!\" \n \n"
            "The " + boss + " chuckles weakly, \"Sending us? No one sends us. You… you're the one who keeps coming back.\" \n \n"
            "\"Coming back? What are you talking about? I don't even know where I am!\" \n \n"
            "The " + boss + " groans in pain, muttering faintly, \n\"Maybe it's better that way…for now.\" \n \n"
            "Annoyed, you grumble, \"Great. Another cryptic answer. Thanks for nothing.\" \n \n"
            "The " + boss + " collapses into ash, leaving a(n) " + reward->getName() + " behind. \n \n"
            "You grab it, feeling a mixture of triumph and confusion as you continue deeper into the unknown.",
            
            "You land the final blow on the " + boss + ", watching it collapse in defeat. \n \n"
            "\"Finally,\" you mutter, glaring down at the creature. \"Alright, start talking. What's the deal with this place?\" \n \n"
            "The " + boss + " smirks through its pain, \n\"What's the deal? You're the one who knows this place the best, aren't you?\" \n \n"
            "Shocked, you stumble back. \"What? No. That's impossible.\" \n \n"
            "The " + boss + " struggles to speak, its voice fading. \n\"It's all connected… and you'll see it soon enough.\" \n \n"
            "Exasperated, you groan, \"Why is everyone here so cryptic? Can someone give me a straight answer for once?!\" \n \n"
            "The " + boss + " vanishes, leaving a(n) " + reward->getName() + " behind. \n \n"
            "You sigh, pick up the reward, and press on, your determination growing as the mystery deepens."
        };
        vector<string> winDialogueNormalBoss = { 
           
            "You have finally defeated the " + boss + " with a final blow to the head with your trusty weapon! \n \n"
            "As the " + boss + " gasps for air, it whispers, \n\"Fine... you've defeated me, but this is just the beginning of your torment.\" \n \n"
            "\"And what does that mean exactly? I really miss watching my daily YouTube videos on my lunch break,\" you reply. \n \n"
            "The " + boss + " smirks weakly, \"You'll find out soon enough...\" \n \n"
            "\"Bruh that still doesn't make any sense.\" \n \n"
            "You leave confused and frustrated, but a sense of accomplishment lingers as the " + boss + " leaves a(n) " + reward->getName() + " behind.\n",
           
            "You strike the " + boss + " with a perfectly timed attack using your trusty weapon! \n \n"
            "As the " + boss + " crumples to the ground, it lets out a chilling laugh, \"Heh... enjoy your little victory while it lasts... The real challenge awaits.\" \n \n"
            "\"Yeah, sure. And I'm guessing I'll need, like, a manual to understand it?\" you quip. \n \n"
            "The " + boss + " vanishes into smoke, leaving behind a(n) " + reward->getName() + " glowing faintly in the dim light. \n \n"
            "You take it, unsure of what lies ahead.",
            
            "With one final blow, you bring the " + boss + " to its knees. \n \n"
            "It struggles to speak, rasping out, \"Defeat me if you must, but your journey is far from over. They're watching... always watching.\" \n \n"
            "You sigh. \"Can they 'watch' me take a nap? That'd be great.\" \n \n"
            "Without another word, the " + boss + " collapses, leaving a(n) " + reward->getName() + " behind. \n \n"
            "Grateful for the reward, you pick it up and move on, bracing for what's next."
        };
        vector<string> loseDialogue{
            
            "OOF… that one hurt… \n ... \n You can see the Wi-Fi slowly fade away from your grasp as you take your last breath…. \n You Died! \n \n",
            
        };
};

// more dialogue incoming 