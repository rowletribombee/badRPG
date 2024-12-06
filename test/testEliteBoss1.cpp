#include "../lib/EliteBoss1.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Slash, SlashPlayerUnguarded){
    vector<int> bStats = {50,20,4,4,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss1 testBoss(enemyStats);

    testBoss.Slash(p);
    EXPECT_TRUE(p.getStats().getHP()== 16 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Slash, SlashPlayerGuarded){
    vector<int> bStats = {50,20,4,4,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss1 testBoss(enemyStats);
    p.Guard();

    testBoss.Slash(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Thrash, ThrashPlayerUnguarded){
    vector<int> bStats = {50,20,4,4,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss1 testBoss(enemyStats);

    testBoss.Thrash(p);
    EXPECT_TRUE(p.getStats().getHP()== 16 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Thrash, ThrashPlayerGuarded){
    vector<int> bStats = {50,20,4,4,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss1 testBoss(enemyStats);
    p.Guard();

    testBoss.Thrash(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20);
}
