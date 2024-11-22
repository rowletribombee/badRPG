#include "../lib/Weapon.h"
#include "../lib/Player.h"
#include <iostream>

void Weapon::use(Player& target) {
    target.applyStatBoost("ATK", attackBoost);
    target.applyStatBoost("DEF", defenseBoost);
    target.applyStatBoost("SPD", speedBoost);
    target.applyStatBoost("LCK", luckBoost);
    std::cout << name << " equipped!\n";
}

void Weapon::unequip(Player& target) {
    target.applyStatBoost("ATK", -attackBoost);
    target.applyStatBoost("DEF", -defenseBoost);
    target.applyStatBoost("SPD", -speedBoost);
    target.applyStatBoost("LCK", -luckBoost);
    std::cout << name << " unequipped!\n";
}

std::string Weapon::getEffect() const {
    std::string effect;
    if (attackBoost) effect += "ATK+" + std::to_string(attackBoost) + " ";
    if (defenseBoost) effect += "DEF+" + std::to_string(defenseBoost) + " ";
    if (speedBoost) effect += "SPD+" + std::to_string(speedBoost) + " ";
    if (luckBoost) effect += "LCK+" + std::to_string(luckBoost) + " ";
    return effect.empty() ? "No effect" : effect;
}