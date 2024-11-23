#include "gtest/gtest.h"
#include "../lib/Player.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"

TEST(PlayerTests, InitializeStats) {
    Player player("Elf");
    EXPECT_EQ(player.getStats().getHP(), 50); 
    EXPECT_EQ(player.getStats().getAtk(), 8);
    EXPECT_EQ(player.getStats().getDef(), 6);
    EXPECT_EQ(player.getStats().getMAtk(), 7);
    EXPECT_EQ(player.getStats().getMDef(), 9);
    EXPECT_EQ(player.getStats().getSpd(), 8);
    EXPECT_EQ(player.getStats().getLck(), 6);
}

TEST(PotionTests, UsePotion) {
    Player player("Elf");
    Potion potion("Potion", 20);
    potion.use(player);

    EXPECT_EQ(player.getStats().getHP(), 50);
}

TEST(WeaponTests, EquipWeapon) {
    Player player("Elf");
    Weapon stick("Stick", 2, 2, 0, 0, 2, 0);
    stick.use(player);

    EXPECT_EQ(player.getStats().getAtk(), 10);
    EXPECT_EQ(player.getStats().getDef(), 8);
    EXPECT_EQ(player.getStats().getSpd(), 10);
}

TEST(WeaponTests, UnequipWeapon) {
    Player player("Elf");
    Weapon stick("Stick", 2, 2, 0, 0, 2, 0); 
    stick.use(player);
    stick.unequip(player);

    EXPECT_EQ(player.getStats().getAtk(), 8);
    EXPECT_EQ(player.getStats().getDef(), 6); 
    EXPECT_EQ(player.getStats().getSpd(), 8);
}