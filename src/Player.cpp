#include "../lib/Player.h"
#include <iostream>

Player::Player(string race) : race(race), baseHp(100), baseAtk(10), baseDef(10),
                              baseMatk(10), baseMdef(10), baseSpd(10), baseLuck(10) {
    //  just for testing purposes
}

void Player::move(string dir){
    if(positionX == 0 && dir == "left"){
        cout << "Whoops! There appears to be a wall here!";
    }else if(positionX == 7 && dir == "right"){
        cout << "Whoops! There appears to be a wall here!";
    }else if(positionY == 0 && dir == "up"){
        cout << "Whoops! There appears to be a wall here!";
    }
    else if(positionY == 7 && dir == "down"){
        cout << "Whoops! There appears to be a wall here!";
    }else{
        if(dir == "left") positionX--;
        if(dir == "right") positionX++;
        if(dir == "up") positionY--;
        if(dir == "down") positionY++;
    }
}

void Player::applyStatBoost(const string& stat, int boost) {
    int* statPtr = nullptr;

    // map the stat string to the corresponding stat pointer
    if (stat == "HP") {
        statPtr = &baseHp;
    } else if (stat == "ATK") {
        statPtr = &baseAtk;
    } else if (stat == "DEF") {
        statPtr = &baseDef;
    } else if (stat == "MATK") {
        statPtr = &baseMatk;
    } else if (stat == "MDEF") {
        statPtr = &baseMdef;
    } else if (stat == "SPD") {
        statPtr = &baseSpd;
    } else if (stat == "LCK") {
        statPtr = &baseLuck;
    }

    // if the stat is valid, apply the boost
    if (statPtr) {
        *statPtr += boost;
        cout << stat << " changed by " << boost << ". New value: " << *statPtr << endl;
    } else {
        // handle invalid stat
        cerr << "Error: Unknown stat '" << stat << "'." << endl;
    }
}

void Player::heal(int amount) {
    baseHp += amount;
    cout << "Healed " << amount << " HP. Current HP: " << baseHp << endl;
}

void Player::displayStats() const {
    cout << "Stats for " << race << ":\n";
    cout << "HP: " << baseHp << "\n";
    cout << "ATK: " << baseAtk << "\n";
    cout << "DEF: " << baseDef << "\n";
    cout << "M.ATK: " << baseMatk << "\n";
    cout << "M.DEF: " << baseMdef << "\n";
    cout << "SPD: " << baseSpd << "\n";
    cout << "LCK: " << baseLuck << "\n";
}

int& Player::getStatRef(const string& stat) {
    if (stat == "HP") return baseHp;
    if (stat == "ATK") return baseAtk;
    if (stat == "DEF") return baseDef;
    if (stat == "M.ATK") return baseMatk;
    if (stat == "M.DEF") return baseMdef;
    if (stat == "SPD") return baseSpd;
    if (stat == "LCK") return baseLuck;
    throw invalid_argument("Invalid stat: " + stat);
}