#include "../lib/FinalBoss.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Slam, SlamPlayerUnguarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.Slam(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}

TEST(Slam, SlamPlayerGuarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);
    p.Guard();

    testBoss.Slam(p);
    EXPECT_TRUE(p.getStats().getHP()== 19 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}

TEST(Explosion, ExplodePlayerUnguarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.Explosion(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}

TEST(Explosion, ExplodePlayerGuarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);
    p.Guard();

    testBoss.Explosion(p);
    EXPECT_TRUE(p.getStats().getHP()== 19 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}

TEST(Charge, ChargeStandard){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.Charge();
    EXPECT_TRUE(testBoss.getStats().getMAtk() == 6 | testBoss.chargeCounter == 1);
}

TEST(BackToFull, FullHeal){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.BackToFull();
    EXPECT_TRUE(testBoss.getStats().getHP() == 50);
}


TEST(Cleave, CleavePlayerUnguarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.Cleave(p);
    EXPECT_TRUE(p.getStats().getHP()== 18 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}

TEST(Cleave, CleavePlayerGuarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);
    p.Guard();

    testBoss.Explosion(p);
    EXPECT_TRUE(p.getStats().getHP()== 19 || p.getStats().getHP()== 17 || p.getStats().getHP()== 20  );
}

TEST(Cleave, ChargedCleavePlayerUnguarded){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.Charge();
    testBoss.Charge();
    testBoss.Charge();
    testBoss.Cleave(p);
    EXPECT_TRUE(p.getStats().getHP()== 16 || p.getStats().getHP()== 14 || p.getStats().getHP()== 20  );
}

TEST(Brace, Bracing){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.Brace();
    EXPECT_TRUE(testBoss.getStats().getDef() == 9 && testBoss.getStats().getMDef() == 7);
}

TEST(SpeedUp, SpeedIncrease){
    vector<int> bStats = {50,20,4,8,3,6,4,4};
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);

    testBoss.SpeedUp();
    EXPECT_TRUE(testBoss.getStats().getSpd() == 6);
}

TEST(TheEnd, KillPlayer){
    vector<int> bStats = {5000,2000,4,8,3,6,4,4};
    Player p(bStats);
    Stats enemyStats(bStats);
    FinalBoss testBoss(enemyStats);
    p.Guard();

    testBoss.TheEnd(p);
    EXPECT_TRUE(p.getStats().getHP()== 0);
}