#include "../lib/Item.h"
#include "../lib/Inventory.h"
#include "../lib/Weapon.h"
#include "../lib/Potion.h"
#include <iostream>

Inventory::Inventory(){
    for (auto& item : items) {
        delete item;
    }
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
    string output = "";
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

string Inventory::displayItemDetails(Item& item) const {
    string output = "";
    output = "Item: " + item.getName() + "\n";
    
    if(item.getType() == weapon){
        Weapon* weaponItem = dynamic_cast<Weapon*>(&item);
        output += "Attack Boost: " + to_string(weaponItem->getAtkBoost()) + "\n";
        output += "Defend Boost: " + to_string(weaponItem->getDefBoost()) + "\n";
        output += "Magic Attack Boost: " + to_string(weaponItem->getM_AtkBoost()) + "\n";
        output += "Magic Defend Boost: " + to_string(weaponItem->getM_DefBoost()) + "\n";
        output += "Speed boost: " + to_string(weaponItem->getSpdBoost()) + "\n";
        output += "Luck Boost: " + to_string(weaponItem->getLuckBoost()) + "\n";
        if(weaponItem->isEquipped()){
            output += "Currently Equipped!\n";
        }
        else{
            output += "Not Equipped\n";
        }
    }
    else{
        Potion* potionItem = dynamic_cast<Potion*>(&item);
        output += "Heal Amount: " + to_string(potionItem->getHealAmount()) + "\n";
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