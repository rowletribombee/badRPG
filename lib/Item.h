#pragma once
#include <string>
class Player;
using namespace std;

class Item {
public:
    virtual ~Item() = default;
    virtual void use(Player& target) = 0;
    virtual string getName() const = 0;
};