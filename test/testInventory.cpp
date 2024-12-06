#include "gtest/gtest.h"
#include "../lib/Item.h"
#include "../lib/Inventory.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"

TEST(InventoryTests, AddItem) {
    Inventory inventory;

    Potion* potion = new Potion("Health Potion", 50);
    Weapon* sword = new Weapon("Sword", 5, 2, 0, 0, 0, 0);
    
    inventory.addItem(potion);
    inventory.addItem(sword);

    string inventoryOutput = inventory.displayItems();

    EXPECT_TRUE(inventoryOutput.find("Health Potion") != string::npos);
    EXPECT_TRUE(inventoryOutput.find("Sword") != string::npos);
}

TEST(InventoryTests, RemoveItem) {
    Inventory inventory;

    Potion* potion = new Potion("Health Potion", 50);
    Weapon* sword = new Weapon("Sword", 5, 2, 0, 0, 0, 0);

    inventory.addItem(potion);
    inventory.addItem(sword);

    inventory.removeItem(potion);

    string inventoryOutput = inventory.displayItems();
    EXPECT_TRUE(inventoryOutput.find("Health Potion") == string::npos);
    EXPECT_TRUE(inventoryOutput.find("Sword") != string::npos);
}

TEST(InventoryTests, DisplayEmptyInventory) {
    Inventory inventory;

    string inventoryOutput = inventory.displayItems();

    EXPECT_TRUE(inventoryOutput == "No items in inventory.\n");
}

TEST(InventoryTests, RemoveItemFromEmptyInventory) {
    Inventory inventory;

    Potion* potion = new Potion("Health Potion", 50);
    
    inventory.removeItem(potion);

    string inventoryOutput = inventory.displayItems();
    EXPECT_TRUE(inventoryOutput == "No items in inventory.\n");
}