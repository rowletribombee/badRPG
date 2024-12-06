#include "gtest/gtest.h"
#include "../lib/Battle.h"
using namespace std;

TEST(getTurnCount, noTurns){
    Battle a;
    EXPECT_EQ(a.getTurnCount(), 0);
}