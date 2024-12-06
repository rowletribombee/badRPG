#pragma once
#include <string>
class Player;
using namespace std;

enum ItemType{ weapon, potion};
class Item {
public:
    virtual ~Item() = default;
    virtual void use(Player& target) = 0;
    virtual string getName() const = 0;
    virtual ItemType getType() const = 0;
};