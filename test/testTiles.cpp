#include "gtest/gtest.h"
#include "../lib/tiles/EmptyTile.h"
#include "../lib/tiles/SpawnTile.h"
#include "../lib/tiles/WeaponTile.h"
#include "../lib/tiles/FightTile.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

using namespace std;

// All TESTS WITHIN EMPTYTILE SUITE ARE BASED ON RNG SO THE TEST CHECKS IF OUTPUT IS 1 OF 3 RANDOM VALUES
TEST(EmptyTile, EmptyTileTest1) {
    EmptyTile emptyTile;

    stringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());
    
    emptyTile.print();

    cout.rdbuf(oldCoutBuffer);
    string result = buffer.str();

    vector<string> firstPartOptions = {
        "Ah yes! Exactly what I needed! A whole lot of nothing. \n \n",
        "Great! An empty room. I always wanted a personal space for my existential dread. \n \n",
        "Well, it could be worse, I could be wandering in a cave with no memory and no way out… \n ... \n ... \n wait"
    };

    string secondPart = "Time to move along! \n \n";

    bool matches = false;
    for (const auto& firstPart : firstPartOptions) {
        if (result == firstPart + secondPart) {
            matches = true;
            break;
        }
    }
    EXPECT_TRUE(matches) << "Output was: " << result;
}
TEST(EmptyTile, EmptyTileTest2) {
    EmptyTile emptyTile;

    stringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());
    
    emptyTile.print();

    cout.rdbuf(oldCoutBuffer);
    string result = buffer.str();

    vector<string> firstPartOptions = {
        "Ah yes! Exactly what I needed! A whole lot of nothing. \n \n",
        "Great! An empty room. I always wanted a personal space for my existential dread. \n \n",
        "Well, it could be worse, I could be wandering in a cave with no memory and no way out… \n ... \n ... \n wait"
    };

    string secondPart = "Time to move along! \n \n";

    bool matches = false;
    for (const auto& firstPart : firstPartOptions) {
        if (result == firstPart + secondPart) {
            matches = true;
            break;
        }
    }
    EXPECT_TRUE(matches) << "Output was: " << result;
}

TEST(SpawnTile, SpawnTileFirstVisit){
    SpawnTile spawnTile;
    stringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());
    
    spawnTile.print();

    cout.rdbuf(oldCoutBuffer);
    string result = buffer.str();

    vector<string> dialogue = {
        "You wake up in a cave and you crave the internet…",
        ""
    };

    bool matches = false;
    if (result == dialogue[0]) matches = true;
    
    EXPECT_TRUE(matches);
}
TEST(SpawnTile, SpawnTileNotFirstVisit){
    SpawnTile spawnTile;
    stringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());
    
    spawnTile.setVisitStateFalse();
    spawnTile.print();

    cout.rdbuf(oldCoutBuffer);
    string result = buffer.str();

    vector<string> dialogue = {
        "You wake up in a cave and you crave the internet…",
        ""
    };

    bool matches = false;
    if (result == dialogue[1]) matches = true;
    
    EXPECT_TRUE(matches);
}

TEST(Tiles, isVisitedTest1){
    SpawnTile spawnTile;
    spawnTile.setVisited();
    EXPECT_TRUE(spawnTile.isVisited());
}

TEST(Tiles, isVisitedTest2){
    SpawnTile spawnTile;
    EXPECT_TRUE(spawnTile.isVisited());
}

TEST(WeaponTile, WeaponTile){
    Weapon testWeapon("Chain Mail", 0, 2, 0, 0, 0, 0);
    WeaponTile tile(testWeapon);

    const vector<string>& dialogue = tile.getDialogue();

    ASSERT_EQ(dialogue.size(), 5); // Check there are 5 dialogue options
    EXPECT_EQ(tile.getDialogue()[1], "Wow, something useful for once. Maybe once I get out of here I'll open a(n) Chain Mail shop! \n\n");
    EXPECT_EQ(tile.getDialogue()[4], "It is a(n) Chain Mail! You pick up this heavy tool and think to yourself that it will be useful in the near future... \n\n");
}

TEST(FightTile, Initialization) {
    shared_ptr<Item> testReward = make_shared<Weapon>("Excalibur", 2, 2, 2, 2, 2, 0);
    FightTile fightTile("BasicBoss", testReward);

    EXPECT_EQ(fightTile.getBoss(), "BasicBoss");
    EXPECT_EQ(fightTile.getReward(), testReward);
}

TEST(FightTile, RewardIsNotNull) {
    shared_ptr<Item> testReward = make_shared<Potion>("Epic Potion", 40);
    FightTile fightTile("EliteBoss", testReward);

    EXPECT_NE(fightTile.getReward(), nullptr);
}

TEST(FightTile, DifferentBosses) {
    shared_ptr<Item> testReward = make_shared<Weapon>("Excalibur", 2, 2, 2, 2, 2, 0);
    FightTile fightTile1("Dragon", testReward);
    FightTile fightTile2("Goblin", testReward);

    EXPECT_EQ(fightTile1.getBoss(), "Dragon");
    EXPECT_EQ(fightTile2.getBoss(), "Goblin");
    EXPECT_NE(fightTile1.getBoss(), fightTile2.getBoss());
}


TEST(FightTileTest, EliteWinDialogueTest) {
    shared_ptr<Item> testReward = make_shared<Weapon>("Excalibur", 2, 2, 2, 2, 2, 0);
    FightTile fightTile("Dragon", testReward);

    const auto& dialogue = fightTile.getEliteWinDialogue();

    EXPECT_EQ(dialogue.size(), 3); 
    EXPECT_EQ(dialogue[0], "You have finally defeated the Dragon with a final blow to the head with your trusty weapon! \n \n"
                            "As you stand over your enemy, you ask, \n\"I'll ask one more time…what this place is and how did I get here with no memory?\" \n \n"
                            "The monster snaps back at you, \n\"I think you'd be better suited to answer that question than me…You know these caves better than anyone else.\" \n \n"
                            "Your frustration builds. \n\"Omg can we stop with the games already? What is going on??? Tell me how to get out of here, dude, I'm so hungry and I miss my phone!\" \n \n"
                            "As the monster takes its last breath, it mutters, \n\"With time, my friend…with time, you'll have all the answers.\" \n \n"
                            "\"Ugh, I'd rather just have all the answers now, but yeah okay, let's keep exploring this TOTALLY NOT creepy cave. Sounds like a blast.\" \n \n"
                            "You leave with more questions than you began with and a new passion to get out of this place as the Dragon leaves a(n) Excalibur behind.");
}

TEST(FightTileTest, NormalWinDialogueTest) {
    shared_ptr<Item> testReward = make_shared<Weapon>("Excalibur", 2, 2, 2, 2, 2, 0);
    FightTile fightTile("Goblin", testReward);

    const auto& dialogue = fightTile.getNormalWinDialogue();

    EXPECT_EQ(dialogue.size(), 3); // Check that there are 3 dialogue options

    EXPECT_EQ(dialogue[0], "You have finally defeated the Goblin with a final blow to the head with your trusty weapon! \n \n"
                            "As the Goblin gasps for air, it whispers, \n\"Fine... you've defeated me, but this is just the beginning of your torment.\" \n \n"
                            "\"And what does that mean exactly? I really miss watching my daily YouTube videos on my lunch break,\" you reply. \n \n"
                            "The Goblin smirks weakly, \"You'll find out soon enough...\" \n \n"
                            "\"Bruh that still doesn't make any sense.\" \n \n"
                            "You leave confused and frustrated, but a sense of accomplishment lingers as the Goblin leaves a(n) Excalibur behind.\n");

    EXPECT_EQ(dialogue[1], "You strike the Goblin with a perfectly timed attack using your trusty weapon! \n \n"
                            "As the Goblin crumples to the ground, it lets out a chilling laugh, \"Heh... enjoy your little victory while it lasts... The real challenge awaits.\" \n \n"
                            "\"Yeah, sure. And I'm guessing I'll need, like, a manual to understand it?\" you quip. \n \n"
                            "The Goblin vanishes into smoke, leaving behind a(n) Excalibur glowing faintly in the dim light. \n \n"
                            "You take it, unsure of what lies ahead.");

    EXPECT_EQ(dialogue[2], "With one final blow, you bring the Goblin to its knees. \n \n"
                            "It struggles to speak, rasping out, \"Defeat me if you must, but your journey is far from over. They're watching... always watching.\" \n \n"
                            "You sigh. \"Can they 'watch' me take a nap? That'd be great.\" \n \n"
                            "Without another word, the Goblin collapses, leaving a(n) Excalibur behind. \n \n"
                            "Grateful for the reward, you pick it up and move on, bracing for what's next.");
}