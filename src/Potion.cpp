#include "Potion.h"
#include <iostream>


Potion::Potion(const string& potionName, int healAmount)
   : healingAmount(healAmount) {
   name = potionName;
   weight = 1;
}

void Potion::use(Player& target) {
   target.applyStatBoost(healingAmount);
   cout << name << " used! Healed " << healingAmount << " HP";
}

string Potion::getEffect() const {
   string effect = "Heals " + to_string(healingAmount) + " HP";
   return effect;
}