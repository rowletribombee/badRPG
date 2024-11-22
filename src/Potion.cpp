#include "../lib/Potion.h"
#include "../lib/Player.h"
#include <iostream>

void Potion::use(Player& target) {
    target.heal(healingAmount);
    std::cout << name << " used! Healed " << healingAmount << " HP.\n";
}

std::string Potion::getEffect() const {
    return "Heals " + std::to_string(healingAmount) + " HP";
}