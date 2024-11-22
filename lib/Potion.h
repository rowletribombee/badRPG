#pragma once
#include "Item.h"
#include <string>

class Potion : public Item {
public:
    Potion(const std::string& potionName, int healAmount)
        : name(potionName), healingAmount(healAmount) {}

    void use(Player& target) override;

private:
    std::string name;
    int healingAmount;
};