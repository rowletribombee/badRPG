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
    vector<Item*> getInventory(){ return items; }

private:
    vector<Item*> items;
};