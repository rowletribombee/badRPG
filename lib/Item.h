#pragma once
#include <string>
#include "Player.h"
using namespace std;

class Item {
   public:
       virtual void use(Player& target) = 0;
       virtual string getEffect() const = 0;
       int weight;
};