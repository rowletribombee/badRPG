#include <vector>
#include <memory>
#include <string>
#include "Tile.h"
#include "../Item.h"
using namespace std;

class FightTile : public Tile {
    public:
        FightTile(const string& boss, shared_ptr<Item> reward);
        ~FightTile() override;

        void print() override;
        string getBoss() const { return boss; }
        shared_ptr<Item> getReward() const { return reward; }
        const vector<string>& getEliteWinDialogue() const { return winDialogueEliteBoss; }
        const vector<string>& getNormalWinDialogue() const { return winDialogueNormalBoss; }
        const vector<string>& getPhaseDialogueFinalBoss() const { return PhaseDialogueFinalBoss; }
    private:
        string boss;
        shared_ptr<Item> reward;
        
        //each string is a part of a phase (out of 4 phases)
        vector<string> PhaseDialogueFinalBoss = {
            "You finally find a moment to step back and center your thoughts\n\n"
            "\"Come on dude lets just talk this out.\" you plead, hoping reason might pierce through the fight\n\n"
            "The " + boss + " looks at you with an unsettling calm, condescending stare.\n"
            "\"You're not getting out of here alive. End of story\"\n\n"
            "You blink in shock, which seemingly upsets the " + boss + "\n"
            "\"Uh, that was rude.\" you mutter under your breath.\n"
            "\"Listen, let's just talk this out. I mean, once I get out of here, I could...maybe free you too. How does that sound?\"\n\n"
            "But your words only seem to fuel the " + boss + "'s anger, his eyes narrowing as his face shifts from anger to rage. His stance shifts, clearly showing he's ready for more.\n\n"
            "The fight continues...\n\n",
            
            
            "Despite fatigue seeping into your body, you keep your stance. You look at your opponent, tired but still with the determination to keep fighting\n"
            "\"Ugh, just tell me what's going on. Why are we even fighting? I'm tired bro\" you say, with frustration bleeding into your words.\n\n"
            "The " + boss + " lets out a chuckle, amused by your ignorance.\n"
            "\"You know this world better than I. You should be telling me\"\n\n"
            "You roll your eyes, exasperated.\n"
            "\"Yeah yeah that's what the last guy said. C'mon just explain what's going on. You seem like the top dog here -I just want answers. What's really in it for you?\"\n\n"
            "His grin hardened into a scowl.\n"
            "\"Nice try, you wont get out of this that easily...\"\n\n"
            "You sigh, dropping your hands slightly.\n"
            "\"Bro I'm literally trying to AVOID the both of us getting hurt here. But okay, whatever, it's your funeral.\"\n\n"
            "The fight continues...\n\n",
            
            
            "Your arms ache, your legs feel like jelly, but you press on. Between swings, dodges, and narrowly avoiding certain death, you can't help but blurt out, "
            "\"Seriously, man, what's your deal? Why are you so mad? Did I step on your pet rock or something?!\"\n\n"
            "The " + boss + " pauses mid-strike, glaring at you with a mix of annoyance and disdain. \"You don't get it, do you? You really don't remember anything?\"\n"
            "\"No! That's what I've been saying this whole time! You think I'd voluntarily come hang out in a murder cave?!\"\n"
            "The " + boss + " exhales sharply, lowering his weapon slightly.\n"
            "\"This 'murder cave,' as you so eloquently put it, wasn't always like this. You changed everything.\"\n\n"
            "You stop in your tracks, blinking.\n"
            "\"Wait... me? What are you talking about? I literally just woke up here!\"\n"
            "\"You really don't remember, huh? Figures. Typical.\" He shakes his head and smirks darkly.\n"
            "\"Fine. Here's a hint: you've been here longer than you think. Much longer. And everyone here? They exist because of you.\"\n\n"
            "You feel a chill crawl up your spine. \"Okay, creepy and vague. Care to elaborate?\"\n"
            "\"Why should I?\" he snaps, his tone suddenly defensive. \"You've always been so good at figuring things out on your own. Isn't that why you built ... nevermind, I've said too much\"\n\n"
            "You freeze, his words rattling in your brain like loose change in a tin can. \"Wait, what? Built...what? I don't even own power tools. You've got the wrong guy.\"\n"
            "The " + boss + " chuckles darkly, his weapon rising again. \"Sure, just think about it for a bit. Maybe you'll remember before I finish you off.\"\n\n"
            "The fight resumes with renewed intensity, but his words stick in your mind. The pieces don't fit, but they're starting to look like part of a bigger puzzle.\n\n",



            "Your eyesight begins to get blurry as you start to lose your balance.\n"
            "\"Okay...I get it... you hate me.\" You gasp, barely able to catch your breath. \"But what I don't understand is WHY. This is getting so lame-I just want to go home\"\n\n"
            "For a moment the " + boss + " almost looks sympathetic, as if he understands... until their eyes shift back into focus\n"
            "\"Oh shut up, don't give me all that. Just because you lost your memory doesn't mean your actions don't have consequences.\"\n\n"
            "Your body almost goes limp\n"
            "\"LITERALLY WHAT ACTIONS! I'VE BEEN HERE FOR A MAX OF LIKE 30 MINUTES! I HAVEN'T DONE ANYTHING! JUST LET ME GO HOME SO I CAN PLAY ROBLOX AND FORGET THIS ALL HAPPENED\"\n\n"
            "\"It's too late to complain...I've already decided your fate, just as you've done mine. Prepare to die\"\n"
            "The " + boss + " grips his weapon harder and prepares to jump back into the fight. You know this is it, your last chance to get out of the cave and find freedom. Finally, internet connection is within your grasp. You take a deep breath and prepare for the battle of your life...\n\n"
            "The fight continues...\n\n"
        };
        vector<string> winDialogueEliteBoss = {
            
            "You have finally defeated the " + boss + " with a final blow to the head with your trusty weapon! \n \n"
            "As you stand over your enemy, you ask, \n\"I'll ask one more time...what this place is and how did I get here with no memory?\" \n \n"
            "The " + boss + " snaps back at you, \n\"I think you'd be better suited to answer that question than me...You know these caves better than anyone else.\" \n \n"
            "Your frustration builds. \n\"Omg can we stop with the games already? What is going on??? Tell me how to get out of here, dude, I'm so hungry and I miss my phone!\" \n \n"
            "As the " + boss + " takes its last breath, it mutters, \n\"With time, my friend...with time, you'll have all the answers.\" \n \n"
            "\"Ugh, I'd rather just have all the answers now, but yeah okay, let's keep exploring this TOTALLY NOT creepy cave. Sounds like a blast.\" \n \n"
            "You leave with more questions than you began with and a new passion to get out of this place as the " + boss + " leaves a(n) " + reward->getName() + " behind.\n\n",
            
            
            "With one final strike, the " + boss + " falls to the ground, defeated. \n \n"
            "Panting, you shout, \"Who keeps sending you guys? What do you want from me?!\" \n \n"
            "The " + boss + " chuckles weakly, \"Sending us? No one sends us. You... you're the one who keeps coming back.\" \n \n"
            "\"Coming back? What are you talking about? I don't even know where I am!\" \n \n"
            "The " + boss + " groans in pain, muttering faintly, \n\"Maybe it's better that way...for now.\" \n \n"
            "Annoyed, you grumble, \"Great. Another cryptic answer. Thanks for nothing.\" \n \n"
            "The " + boss + " collapses into ash, leaving a(n) " + reward->getName() + " behind. \n \n"
            "You grab it, feeling a mixture of triumph and confusion as you continue deeper into the unknown.\n\n",
            
            "You land the final blow on the " + boss + ", watching it collapse in defeat. \n \n"
            "\"Finally,\" you mutter, glaring down at the creature. \"Alright, start talking. What's the deal with this place?\" \n \n"
            "The " + boss + " smirks through its pain, \n\"What's the deal? You're the one who knows this place the best, aren't you?\" \n \n"
            "Shocked, you stumble back. \"What? No. That's impossible.\" \n \n"
            "The " + boss + " struggles to speak, its voice fading. \n\"It's all connected... and you'll see it soon enough.\" \n \n"
            "Exasperated, you groan, \"Why is everyone here so cryptic? Can someone give me a straight answer for once?!\" \n \n"
            "The " + boss + " vanishes, leaving a(n) " + reward->getName() + " behind. \n \n"
            "You sigh, pick up the reward, and press on, your determination growing as the mystery deepens.\n\n"
        };
        vector<string> winDialogueNormalBoss = { 
           
            "You have finally defeated the " + boss + " with a final blow to the head with your trusty weapon! \n \n"
            "As the " + boss + " gasps for air, it whispers, \n\"Fine... you've defeated me, but this is just the beginning of your torment.\" \n \n"
            "\"And what does that mean exactly? I really miss watching my daily YouTube videos on my lunch break,\" you reply. \n \n"
            "The " + boss + " smirks weakly, \"You'll find out soon enough...\" \n \n"
            "\"Bruh that still doesn't make any sense.\" \n \n"
            "You leave confused and frustrated, but a sense of accomplishment lingers as the " + boss + " leaves a(n) " + reward->getName() + " behind.\n\n",
           
            "You strike the " + boss + " with a perfectly timed attack using your trusty weapon! \n \n"
            "As the " + boss + " crumples to the ground, it lets out a chilling laugh, \"Heh... enjoy your little victory while it lasts... The real challenge awaits.\" \n \n"
            "\"Yeah, sure. And I'm guessing I'll need, like, a manual to understand it?\" you quip. \n \n"
            "The " + boss + " vanishes into smoke, leaving behind a(n) " + reward->getName() + " glowing faintly in the dim light. \n \n"
            "You take it, unsure of what lies ahead.",
            
            "With one final blow, you bring the " + boss + " to its knees. \n \n"
            "It struggles to speak, rasping out, \"Defeat me if you must, but your journey is far from over. They're watching... always watching.\" \n \n"
            "You sigh. \"Can they 'watch' me take a nap? That'd be great.\" \n \n"
            "Without another word, the " + boss + " collapses, leaving a(n) " + reward->getName() + " behind. \n \n"
            "Grateful for the reward, you pick it up and move on, bracing for what's next.\n\n"
        };
        vector<string> loseDialogue{
            
            "OOF... that one hurt... \n ... \n You can see the Wi-Fi slowly fade away from your grasp as you take your last breath... \n You Died! \n \n",
            
        };
};