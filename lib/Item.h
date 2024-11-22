#pragma once
#include <string>
class Player;

class Item {
public:
    virtual ~Item() = default;
    virtual void use(Player& target) = 0;
    virtual std::string getEffect() const = 0;
};