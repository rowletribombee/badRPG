#pragma once
#include <vector>
#include <iostream>
#include "Item.h"
using namespace std;

class Inventory {
public:
    Inventory();
    ~Inventory();
    void addItem(Item* item);
    void removeItem(Item* item);
    string displayItems() const;
    vector<Item*> getInventory(){ return items; }

private:
    vector<Item*> items;
};