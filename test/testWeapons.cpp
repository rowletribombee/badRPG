#include "gtest/gtest.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"


TEST(WeaponBoostStats, ReportExcaliburBoost) {
    Weapon weapon("Excalibur", 2,2,2,2,2,0);
    EXPECT_EQ(weapon.getName(),"Excalibur");
    EXPECT_EQ(weapon.getAtkBoost(), 2);
    EXPECT_EQ(weapon.getDefBoost(), 2);
    EXPECT_EQ(weapon.getM_AtkBoost(), 2); 
    EXPECT_EQ(weapon.getM_DefBoost(), 2);
    EXPECT_EQ(weapon.getSpdBoost(), 2);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}

TEST(WeaponBoostStats, ReportIronSwordBoost) {
    Weapon weapon("Iron Sword", 1, 1, 0, 0, 0, 0);
    EXPECT_EQ(weapon.getName(),"Iron Sword");
    EXPECT_EQ(weapon.getAtkBoost(), 1);
    EXPECT_EQ(weapon.getDefBoost(), 1);
    EXPECT_EQ(weapon.getM_AtkBoost(), 0); 
    EXPECT_EQ(weapon.getM_DefBoost(), 0);
    EXPECT_EQ(weapon.getSpdBoost(), 0);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}


TEST(WeaponBoostStats, ReportChainMailBoost) {
    Weapon weapon("Chain Mail", 0, 2, 0, 0, 0, 0);
    EXPECT_EQ(weapon.getName(),"Chain Mail");
    EXPECT_EQ(weapon.getAtkBoost(), 0);
    EXPECT_EQ(weapon.getDefBoost(), 2);
    EXPECT_EQ(weapon.getM_AtkBoost(), 0); 
    EXPECT_EQ(weapon.getM_DefBoost(), 0);
    EXPECT_EQ(weapon.getSpdBoost(), 0);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}

TEST(WeaponBoostStats, ReportLanceBoost) {
    Weapon weapon("Lance", 1, 0, 0, 0, 1, 0);
    EXPECT_EQ(weapon.getName(),"Lance");
    EXPECT_EQ(weapon.getAtkBoost(), 1);
    EXPECT_EQ(weapon.getDefBoost(), 0);
    EXPECT_EQ(weapon.getM_AtkBoost(), 0); 
    EXPECT_EQ(weapon.getM_DefBoost(), 0);
    EXPECT_EQ(weapon.getSpdBoost(), 1);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}

TEST(WeaponBoostStats, ReportStaffBoost) {
    Weapon weapon("Staff", 0,0,1,1,0,0);
    EXPECT_EQ(weapon.getName(),"Staff");
    EXPECT_EQ(weapon.getAtkBoost(), 0);
    EXPECT_EQ(weapon.getDefBoost(), 0);
    EXPECT_EQ(weapon.getM_AtkBoost(), 1); 
    EXPECT_EQ(weapon.getM_DefBoost(), 1);
    EXPECT_EQ(weapon.getSpdBoost(), 0);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}

TEST(WeaponBoostStats, ReportPlateArmourBoost) {
    Weapon weapon("Plate Armour", 0,1,0,2,0,0);
    EXPECT_EQ(weapon.getName(),"Plate Armour");
    EXPECT_EQ(weapon.getAtkBoost(), 0);
    EXPECT_EQ(weapon.getDefBoost(), 1);
    EXPECT_EQ(weapon.getM_AtkBoost(), 0); 
    EXPECT_EQ(weapon.getM_DefBoost(), 2);
    EXPECT_EQ(weapon.getSpdBoost(), 0);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}

TEST(WeaponBoostStats, ReportCloakOfInvisibilityBoost) {
    Weapon weapon("Cloak of Invisibility", 0,1,0,2,0,0);
    EXPECT_EQ(weapon.getName(),"Plate Armour");
    EXPECT_EQ(weapon.getAtkBoost(), 0);
    EXPECT_EQ(weapon.getDefBoost(), 1);
    EXPECT_EQ(weapon.getM_AtkBoost(), 0); 
    EXPECT_EQ(weapon.getM_DefBoost(), 2);
    EXPECT_EQ(weapon.getSpdBoost(), 0);
    EXPECT_EQ(weapon.getLuckBoost(), 0);
}






