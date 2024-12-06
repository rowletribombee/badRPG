#pragma once
#include "Item.h"
#include <string>
using namespace std;

class Potion : public Item {
public:
    Potion(const string& potionName, int healAmount) 
        : name(potionName), healingAmount(healAmount), type(potion) {}
    ~Potion();
    void use(Player& target) override;
    string getName() const override { return name; }
    int getHealAmount() const  { return healingAmount; }
    ItemType getType() const override { return type; }
private:
    string name;
    int healingAmount;
    ItemType type;
};