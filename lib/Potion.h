#pragma once
#include <Item.h>
using namespace std;


class Potion : public Item {
    public:
        Potion(const string& potionName, int healAmount);
        void use(Player& target) override;
        string getEffect() const override;

    private:
        int healingAmount;
        string name;
};