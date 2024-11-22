#include "../lib/Player.h"
#include <iostream>
#include <cctype>

Player::Player(){
    
}

Player::Player(string race){
    if (race == "Human") {
        baseStats.isHuman();
    } 
    else if (race == "Elf") {
        baseStats.isElf();
    } 
    else if (race == "Dwarf") {
        baseStats.isDwarf();
    } 
    else if (race == "Ogre") {
        baseStats.isOgre();
    } 
    else if (race == "Fairy") {
        baseStats.isFairy();
    } 
    else {
        baseStats.isHuman();  // default to Human
    }
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

void Player::applyStatBoost(const std::string& stat, int boost) {
    baseStats.addStat(stat, boost);        
}

void Player::heal(int amount) {
    baseStats.addStat("hp", amount);
}

void Player::displayStats() const {
    std::cout << "Player Stats:" << std::endl;
    std::cout << "HP: " << baseStats.getHP() << "/" << baseStats.getMaxHP() << std::endl;
    std::cout << "ATK: " << baseStats.getAtk() << std::endl;
    std::cout << "DEF: " << baseStats.getDef() << std::endl;
    std::cout << "MATK: " << baseStats.getMAtk() << std::endl;
    std::cout << "MDEF: " << baseStats.getMDef() << std::endl;
    std::cout << "SPD: " << baseStats.getSpd() << std::endl;
    std::cout << "LCK: " << baseStats.getLck() << std::endl;
}