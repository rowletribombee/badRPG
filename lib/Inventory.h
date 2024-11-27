#pragma once
#include <vector>
#include <iostream>
#include "Item.h"
using namespace std;

class Inventory {
public:
    void addItem(Item* item);
    void removeItem(Item* item);
    string displayItems() const;
    ~Inventory();

private:
    vector<Item*> items;
};