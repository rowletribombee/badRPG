#include "../lib/Weapon.h"
#include "../lib/Player.h"
#include <iostream>

void Weapon::use(Player& target) {
    target.applyStatBoost("atk", attackBoost);
    target.applyStatBoost("def", defenseBoost);
    target.applyStatBoost("matk", magicAttackBoost);
    target.applyStatBoost("mdef", magicDefenseBoost);
    target.applyStatBoost("spd", speedBoost);
    target.applyStatBoost("lck", luckBoost);
    cout << name << " equipped!\n";
}

void Weapon::unequip(Player& target) {
    target.applyStatBoost("atk", -attackBoost);
    target.applyStatBoost("def", -defenseBoost);
    target.applyStatBoost("matk", -magicAttackBoost);
    target.applyStatBoost("mdef", -magicDefenseBoost);
    target.applyStatBoost("spd", -speedBoost);
    target.applyStatBoost("lck", -luckBoost);
    cout << name << " unequipped!\n";
}