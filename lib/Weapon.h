#pragma once
#include "Item.h"
#include <string>
using namespace std;
class Weapon : public Item {
public:
    Weapon(const string& weaponName, int atkBoost = 0, int defBoost = 0, 
           int magicAttackBoost = 0, int magicDefenseBoost = 0, int spdBoost = 0, int lckBoost = 0)
        : name(weaponName), attackBoost(atkBoost), defenseBoost(defBoost), magicAttackBoost(magicAttackBoost), 
          magicDefenseBoost(magicDefenseBoost), speedBoost(spdBoost), luckBoost(lckBoost) {}

    void use(Player& target) override;
    void unequip(Player& target);
    string getName() {return name;}
    int getAtkBoost() {return attackBoost;}
    int getDefBoost() {return defenseBoost;}
    int getM_AtkBoost() {return magicAttackBoost;}
    int getM_DefBoost() {return magicDefenseBoost;}
    int getSpdBoost() {return speedBoost;}
    int getLuckBoost() {return luckBoost;}
private:
    string name;
    int attackBoost;
    int defenseBoost;
    int magicAttackBoost;
    int magicDefenseBoost;
    int speedBoost;
    int luckBoost;
};