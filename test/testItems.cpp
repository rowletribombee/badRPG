#include "../lib/Player.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"
#include <iostream>

int main() {
    // create a player
    Player player("Elf");
    player.displayStats();

    // create potions
    Potion smallPotion("Potion", 20);
    Potion highPotion("High Potion", 40);

    // use potions
    cout << "\nUsing potions...\n";
    smallPotion.use(player);
    player.displayStats();

    highPotion.use(player);
    player.displayStats();

    // create weapons
    Weapon stick("Stick", 2, 2, 2, 0);  // ATK+2, DEF+2, SPD+2, 
    Weapon rock("Rock", 3, 0, 0, 10); // ATK+3, LCK+10

    // equip and unequip weapons
    cout << "\nEquipping weapons...\n";
    stick.use(player);
    player.displayStats();

    rock.use(player);
    player.displayStats();

    cout << "\nUnequipping Stick...\n";
    stick.unequip(player);
    player.displayStats();

    return 0;
}