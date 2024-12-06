#include "gtest/gtest.h"
#include "../lib/Player.h"
using namespace std;

TEST(isGuarding, raiseGuard){
    vector<int> bStats = {50,50,4,8,4,8,4,4};
    Player p(bStats);
    p.Guard();
    EXPECT_TRUE(p.isGuarding);
}

TEST(isGuarding, lowerGuard){
    vector<int> bStats = {50,50,4,8,4,8,4,4};
    Player p(bStats);
    p.Guard();
    p.Guard();
    EXPECT_TRUE(!p.isGuarding);
}

TEST(healPlayer, defaultHeal){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    p.HealPlayer();
    EXPECT_EQ(p.getStats().getHP(), 32);
}

TEST(healPlayer, healFull){
    vector<int> bStats = {50,49,4,8,4,8,4,4};
    Player p(bStats);
    p.HealPlayer();
    EXPECT_EQ(p.getStats().getHP(), 50);
}

TEST(heal, specifiedHeal){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    p.heal(20);
    EXPECT_EQ(p.getStats().getHP(), 40);
}

TEST(buffChosen, buffAtk){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    EXPECT_EQ(p.getStats().getAtk(), 6);
}

TEST(buffChosen, buffDef){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "def";
    p.BuffChosen(s);
    EXPECT_EQ(p.getStats().getDef(), 12);
}

TEST(buffChosen, buffMAtk){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "matk";
    p.BuffChosen(s);
    EXPECT_EQ(p.getStats().getMAtk(), 6);
}

TEST(buffChosen, buffMDef){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "mdef";
    p.BuffChosen(s);
    EXPECT_EQ(p.getStats().getMDef(), 12);
}

TEST(buffChosen, buffSpd){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "spd";
    p.BuffChosen(s);
    EXPECT_EQ(p.getStats().getSpd(), 6);
}

TEST(buffChosen, buffLck){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "lck";
    p.BuffChosen(s);
    EXPECT_EQ(p.getStats().getLck(), 6);
}

TEST(Attack, GenericAttack){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    Stats target(bStats);
    p.Attack(target);
    EXPECT_TRUE(target.getHP() == 18 || target.getHP() == 17 || target.getHP() == 20 );
}

TEST(Attack, AttackKill){
    vector<int> bStats = {50,1,4,8,4,8,4,4};
    Player p(bStats);
    Stats target(bStats);
    p.Attack(target);
    EXPECT_TRUE(target.getHP() == 0 || target.getHP() == 1);
}

TEST(MagicAttack, GenericMagicAttack){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    Stats target(bStats);
    p.MagicAttack(target);
    EXPECT_TRUE(target.getHP() == 18 || target.getHP() == 17 || target.getHP() == 20 );
}

TEST(MagicAttack, MagicAttackKill){
    vector<int> bStats = {50,1,4,8,4,8,4,4};
    Player p(bStats);
    Stats target(bStats);
    p.MagicAttack(target);
    EXPECT_TRUE(target.getHP() == 0 || target.getHP() == 1);
}

TEST(getBuffCounter, noBuffs){
    vector<int> bStats = {50,1,4,8,4,8,4,4};
    Player p(bStats);
    EXPECT_EQ(p.getBuffCounter(), 0);
}

TEST(getBuffCounter, justBuffed){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    EXPECT_EQ(p.getBuffCounter(), 3);
}

TEST(getBuffCounter, buffMinus1){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    EXPECT_EQ(p.getBuffCounter(), 2);
}

TEST(getBuffCounter, buffReducedTo0Atk){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getBuffCounter(), 0);
}

TEST(reduceBuffCounter, buffResetAtk){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getAtk(), 4);
}

TEST(reduceBuffCounter, buffResetDef){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "def";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getDef(), 8);
}

TEST(reduceBuffCounter, buffResetMatk){
    vector<int> bStats = {50,20,4,8,20,8,4,4};
    Player p(bStats);
    string a = "matk";
    p.BuffChosen(a);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getMAtk(), 20);
}

TEST(reduceBuffCounter, buffResetMDef){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "mdef";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getMDef(), 8);
}

TEST(reduceBuffCounter, buffResetSpd){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "spd";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getSpd(), 4);
}

TEST(reduceBuffCounter, buffResetLck){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "lck";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getLck(), 4);
}

TEST(reduceBuffCounter, buffNormal){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    p.reduceBuffCounter();
    EXPECT_EQ(p.getStats().getAtk(), 6);
}

TEST(resetBuffMagnitude, BuffedAttack){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    p.resetBuffMagnitude();
    EXPECT_EQ(p.getStats().getAtk(), 4);
}

TEST(getBuffMagnitude, AfterResetBuffMagnitude){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "atk";
    p.BuffChosen(s);
    p.resetBuffMagnitude();
    EXPECT_EQ(p.getBuffMagnitude(), 0);
}

TEST(getBuffID, buffIDMAtk){
    vector<int> bStats = {50,20,4,8,4,8,4,4};
    Player p(bStats);
    string s = "matk";
    p.BuffChosen(s);
    EXPECT_EQ(p.getBuffID(), 3);
}