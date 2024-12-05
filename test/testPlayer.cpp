#include "gtest/gtest.h"
#include "../lib/Player.h"
using namespace std;

TEST(isGuarding, raiseGuard){
    vector<int> bStats = {50,50,4,8,4,8,4,4};
    Player p(bStats);
    p.Guard();
    EXPECT_TRUE(p.isGuarding);
}

