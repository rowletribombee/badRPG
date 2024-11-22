#include "gtest/gtest.h"
#include "../lib/Player.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"
#include "../lib/Stats.h"

TEST(Potion, PotionTest1){
    Player player("Elf");
    EXPECT_EQ(player.getStats().getAtk(), 8);
    EXPECT_EQ(player.getStats().getHP(), 50);
    EXPECT_EQ(player.getStats().getMaxHP(), 50);
    EXPECT_EQ(player.getStats().getMAtk(), 7);
    EXPECT_EQ(player.getStats().getMDef(), 9);
    EXPECT_EQ(player.getStats().getSpd(), 8);
    EXPECT_EQ(player.getStats().getLck(), 6);
    

}
