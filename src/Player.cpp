#include "../lib/Player.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"
#include "../lib/Screen.h"
#include "../lib/tiles/PotionTile.h"
#include "../lib/tiles/WeaponTile.h"
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
    Screen displayScreen;
    if(positionX == 0 && dir == 'a'){
        cout << "Whoops! There appears to be a wall here!";
        displayScreen.displayDirectionOptions();
        return true;
    }else if(positionX == 7 && dir == 'd'){
        cout << "Whoops! There appears to be a wall here!";
        displayScreen.displayDirectionOptions();
        return true;
    }else if(positionY == 0 && dir == 'w'){
        cout << "Whoops! There appears to be a wall here!";
        displayScreen.displayDirectionOptions();
        return true;
    }
    else if(positionY == 7 && dir == 's'){
        cout << "Whoops! There appears to be a wall here!";
        displayScreen.displayDirectionOptions();
        return true;
    }else{
        return false;
    }
}

bool Player::checkValidDir(char dir){
    if(!isalpha(dir) && dir != 'w' && dir != 'a' && dir != 's' && dir != 'd'){
        Screen displayScreen;
        cout << "Invalid direction! Try again!!" << endl;
        displayScreen.displayDirectionOptions();
        return false;
    }else{
        return true;
    }
}

void Player::move(Map& map, Inventory& inventory){
    char dir;
    Screen displayScreen;
    displayScreen.displayDirectionOptions();
    cin >> dir;
    if(isalpha(dir)) dir = tolower(dir);
    while(!checkValidDir(dir) || checkForWall(dir)){ // some kinks with output need to be fixed, showing you are still required to input to move. still in move phase
        cin >> dir;
        if(isalpha(dir)) dir = tolower(dir);
    }
        if(dir == 'a') positionX--;
        if(dir == 'd') positionX++;
        if(dir == 'w') positionY--;
        if(dir == 's') positionY++;

        if(!map.mapOfTiles.at(positionY).at(positionX)->isVisited()){
            // grab pos x pos y of map
            // check if it was prev visited
            // if it wasn't, add in the items based on the type of tile
            // order of enums spawnTile, emptyTile, fightTile, potionTile, weaponTile
            if(map.mapOfTiles.at(positionY).at(positionX)->getType() == 0){ // spawn tile
                baseStats.addHP(20000); // arbitrarily large value, reset hp to max
                // print stuff "A mysterious energy washes over you and you feel rejuvenated blah blah"
            }
            if(map.mapOfTiles.at(positionY).at(positionX)->getType() == 1){ // empty tile
                // print stuff
            }
            if(map.mapOfTiles.at(positionY).at(positionX)->getType() == 2){ // fight tile
                // initiate fight sequence 
                // print stuff
            }
            if(map.mapOfTiles.at(positionY).at(positionX)->getType() == 3){ // potion tile
                if (PotionTile* potionTile = dynamic_cast<PotionTile*>(map.mapOfTiles.at(positionY).at(positionX))) {
                    Potion potion = potionTile->getPotion();
                    inventory.addItem(new Potion(potion));
                    cout << "You found a " << potion.getName() << " and added it to your inventory!\n";
                }
            }
            if(map.mapOfTiles.at(positionY).at(positionX)->getType() == 4){ // weapon tile
                if (WeaponTile* weaponTile = dynamic_cast<WeaponTile*>(map.mapOfTiles.at(positionY).at(positionX))) {
                    Weapon weapon = weaponTile->getWeapon();
                    inventory.addItem(new Weapon(weapon));
                    cout << "You found a " << weapon.getName() << " and added it to your inventory!\n";
                }
            }
            map.mapOfTiles.at(positionY).at(positionX)->setVisited();
        }else{
            // screen class can print something like looks like you've already been here yada yada, there's nothing here
        }
        
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