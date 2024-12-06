#include "../lib/Item.h"
#include "../lib/Inventory.h"
#include <iostream>

Inventory::Inventory(){

}

void Inventory::addItem(Item* item) {
    items.push_back(item);
    cout << "Item added to inventory.\n";
}

void Inventory::removeItem(Item* item) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            delete items[i];
            items.erase(items.begin() + i);
            cout << "Item removed from inventory.\n";
            return;
        }
    }
    cout << "Item not found in inventory.\n";
}

string Inventory::displayItems() const {
    string output;
    if (items.empty()) {
        output += "No items in inventory.\n";
    } 
    else {
        for (int i = 0; i < items.size(); ++i) {
            Item* item = items[i];
            output += to_string(i + 1) + ") " + item->getName() + "\n"; 
        }
    }
    return output;
}

Inventory::~Inventory() {
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
    items.clear();
    // cout << "Inventory destructed and items cleaned up.\n";
    // In a hypothetical situation, whenever a new game is started, the inventory will be empty regardless so we don't need to worry
    // about copying over the data.
}