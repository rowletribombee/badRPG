#pragma once
#include "Item.h"
#include <string>

class Weapon : public Item {
public:
    Weapon(const std::string& weaponName, int atkBoost = 0, int defBoost = 0, 
           int spdBoost = 0, int lckBoost = 0, bool uniqueEffect = false)
        : name(weaponName), attackBoost(atkBoost), defenseBoost(defBoost), 
          speedBoost(spdBoost), luckBoost(lckBoost) {}

    void use(Player& target) override;
    void unequip(Player& target);
    std::string getEffect() const override;

private:
    std::string name;
    int weight;
    int attackBoost;
    int defenseBoost;
    int speedBoost;
    int luckBoost;
};