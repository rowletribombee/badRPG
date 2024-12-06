#include "../lib/BasicBoss.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Bonk, BonkPlayerUnguarded){
    vector<int> bStats = {50,20,8,6,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    BasicBoss testBoss(enemyStats);

    testBoss.Bonk(p);
    EXPECT_TRUE(p.getStats().getHP()== 16 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Bonk, BonkPlayerGuarded){
    vector<int> bStats = {50,20,8,6,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    BasicBoss testBoss(enemyStats);
    p.Guard();

    testBoss.Bonk(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}
