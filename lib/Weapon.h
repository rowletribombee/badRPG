#pragma once
#include "Item.h"

class Weapon : public Item {
   public:
      Weapon(const string& weaponName, int weight, int atkBoost = 0, int defBoost = 0, int spdBoost = 0, int lckBoost = 0, bool uniqueEffect = false);
      virtual void equip(Player& target);
      virtual void use(Player& target) override;
      string getEffect() const override;

   protected:
      int attackBoost;
      int defenseBoost;
      int speedBoost;
      int luckBoost;
      bool hasUniqueEffect;
      string name;

   virtual void applyUniqueEffect(Player& target);
};