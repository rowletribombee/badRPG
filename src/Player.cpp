#include "../lib/Player.h"
#include <iostream>
#include <cctype>

Player::Player(){
    
}

Player::Player(string race) : race(race), baseHp(100), baseAtk(10), baseDef(10),
                              baseMatk(10), baseMdef(10), baseSpd(10), baseLuck(10) {
    //  just for testing purposes
}

Player::Player(Stats& bStats){
    baseStats = bStats;
}

bool Player::checkForWall(char dir){
    if(positionX == 0 && dir == 'a'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }else if(positionX == 7 && dir == 'd'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }else if(positionY == 0 && dir == 'w'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }
    else if(positionY == 7 && dir == 's'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }else{
        return false;
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

bool Player::checkValidDir(char dir){
    if(!isalpha(dir) && dir != 'w' && dir != 'a' && dir != 's' && dir != 'd'){
        cout << "Invalid direction! Try again! w for up, a for left, s for down and d for right!" << endl << endl;
        return false;
    }else{
        return true;
    }
}

void Player::move(Map& map){
    char dir;
    cout << "Please enter in a direction! w for up, a for left, s for down and d for right: ";
    cin >> dir;
    if(isalpha(dir)) dir = tolower(dir);
    while(!checkValidDir(dir) || checkForWall(dir)){
        cin >> dir;
        if(isalpha(dir)) dir = tolower(dir);
    }
        if(dir == 'a') positionX--;
        if(dir == 'd') positionX++;
        if(dir == 'w') positionY--;
        if(dir == 's') positionY++;
        map.mapOfTiles[positionY][positionX].setVisited();
}

void Player::Heal(){
    baseStats.addHP(baseStats.getMAtk()*3);
}

void Player::Attack(Stats& target) const{
    if(!baseStats.AccuracyCheck(target)){
        return;
    }
    else{
        if(baseStats.CritCheck(target)){
            target.reduceHp(baseStats.getAtk() * 6/target.getDef());
        }
        else{
            target.reduceHp(baseStats.getAtk() * 4/target.getDef());
        }
    }
}

void Player::Guard(){
    isGuarding = true;
}
