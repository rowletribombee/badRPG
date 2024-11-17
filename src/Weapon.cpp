#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const string& weaponName, int wt, int atkBoost, int defBoost, int spdBoost, int lckBoost, bool uniqueEffect)
   : attackBoost(atkBoost), defenseBoost(defBoost), speedBoost(spdBoost), luckBoost(lckBoost), hasUniqueEffect(uniqueEffect) {
   name = weaponName;
   weight = wt;
}

void Weapon::equip(Player& target) {
   target.applyStatBoost(attackBoost);
   target.applyStatBoost(defenseBoost);
   target.applyStatBoost(speedBoost);
   target.applyStatBoost(luckBoost);

   if (hasUniqueEffect) {
       applyUniqueEffect(target);
   }

   cout << name << " equipped!" << endl;
}


void Weapon::use(Player& target) {
   equip(target);
}

string Weapon::getEffect() const {
   string effect = "Weight: " + to_string(weight);
   if (attackBoost > 0) effect += ", ATK+" + to_string(attackBoost);
   if (defenseBoost > 0) effect += ", DEF+" + to_string(defenseBoost);
   if (speedBoost > 0) effect += ", SPD+" + to_string(speedBoost);
   if (luckBoost > 0) effect += ", LCK+" + to_string(luckBoost);
   return effect;
}

void Weapon::applyUniqueEffect(Player& target) {
   // override in derived classes for unique effects
}
