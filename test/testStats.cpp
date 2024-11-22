#include "gtest/gtest.h"
#include "../lib/Stats.h"
using namespace std;

TEST(getMDef, MdefCheck){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    EXPECT_EQ(testStats.getMDef(), 6);
}

TEST(getDef, defCheck){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    EXPECT_EQ(testStats.getDef(), 4);
}

TEST(getSpd, spdCheck){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    EXPECT_EQ(testStats.getSpd(), 7);
}

TEST(getLck, lckCheck){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    EXPECT_EQ(testStats.getLck(), 8);
}

TEST(getHP, hpCheck){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    EXPECT_EQ(testStats.getHP(), 2);
}

TEST(getMaxHP, hpCheck){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    EXPECT_EQ(testStats.getMaxHP(), 1);
}

TEST(reduceHP, normalReduction){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    testStats.reduceHp(1);
    EXPECT_EQ(testStats.getHP(), 1);
}

TEST(reduceHP, reduceToZero){
    vector <int> bstats = {1,2,3,4,5,6,7,8};
    Stats testStats(bstats);
    testStats.reduceHp(500);
    EXPECT_EQ(testStats.getHP(), 0);
}

TEST(addHP, healNormal){
    vector <int> bstats = {50,1,2,3,4,5,6,7};
    Stats testStats(bstats);
    testStats.addHP(39);
    EXPECT_EQ(testStats.getHP(), 40);
}

TEST(addHP, healFull){
    vector <int> bstats = {50,1,2,3,4,5,6,7};
    Stats testStats(bstats);
    testStats.addHP(500);
    EXPECT_EQ(testStats.getHP(), 50);
}

TEST(rng, rngRange){
    int min = 0;
    int max = 50;
    vector <int> bstats = {50,1,2,3,4,5,6,7};
    Stats testStats(bstats);
    int randomResult = testStats.rng(min, max);
    EXPECT_TRUE(min <= randomResult);
}
