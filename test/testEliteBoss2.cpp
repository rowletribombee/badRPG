#include "../lib/EliteBoss2.h"
#include "gtest/gtest.h"
using namespace std;


TEST(Burn, BurnPlayerUnguarded){
    vector<int> bStats = {50,20,4,4,4,4,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss2 testBoss(enemyStats);

    testBoss.Burn(p);
    EXPECT_TRUE(p.getStats().getHP()== 16 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Burn, BurnPlayerGuarded){
    vector<int> bStats = {50,20,4,4,4,4,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss2 testBoss(enemyStats);
    p.Guard();

    testBoss.Burn(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Inferno, InfernoPlayerUnguarded){
    vector<int> bStats = {50,20,4,4,4,10,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss2 testBoss(enemyStats);

    testBoss.Inferno(p);
    EXPECT_TRUE(p.getStats().getHP()== 15 || p.getStats().getHP()== 14 || p.getStats().getHP()== 17  );
}

TEST(Inferno, InfernoPlayerGuarded){
    vector<int> bStats = {50,20,4,4,4,10,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    EliteBoss2 testBoss(enemyStats);
    p.Guard();

    testBoss.Inferno(p);
    EXPECT_TRUE(p.getStats().getHP()== 16 || p.getStats().getHP()== 14 || p.getStats().getHP()== 17);
}
