#include "../lib/Player.h"
#include "../lib/Potion.h"
#include "../lib/Screen.h"
#include "../lib/tiles/PotionTile.h"
#include <iostream>
#include <string>
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
                // add it into inventory
            }
            if(map.mapOfTiles.at(positionY).at(positionX)->getType() == 4){ // weapon tile
                // add weapon into the inventory, LATER PROBLEM -- WAITING ON PR TO BE MERGED
                // dialogue
            }

            map.mapOfTiles.at(positionY).at(positionX)->setVisited();
        }else{
            // screen class can print something like looks like you've already been here yada yada, there's nothing here
        }
        
}

void Player::HealPlayer(){
    baseStats.addStat("hp",baseStats.getMAtk()*3);
}

void Player::Attack(Stats& target){
    baseStats.damageDealtPhys(target, 4);
}

void Player::MagicAttack(Stats& target){
    baseStats.damageDealtMagic(target, 4);
}

void Player::Guard(){
    isGuarding = !isGuarding;
}

void Player::applyStatBoost(const std::string& stat, int boost) { //for utility
    baseStats.addStat(stat, boost);        
}

void Player::heal(int amount) { //utility
    baseStats.addStat("hp", amount);
}

void Player::reduceBuffCounter(){ 
    if(buffCounter > 1){
        buffCounter -= 1;
    }
    else if(buffCounter = 1){
        buffCounter--;
        resetBuffMagnitude();
    }
}

void Player::resetBuffMagnitude(){ 
    if(buffID = 1){
        baseStats.addStat("atk", -1*buffMagnitude);
    }
    else if(buffID = 2){
        baseStats.addStat("def", -1*buffMagnitude);
    }
    else if(buffID = 3){
        baseStats.addStat("matk", -1*buffMagnitude);
    }
    else if(buffID = 4){
        baseStats.addStat("mdef", -1*buffMagnitude);
    }
    else if(buffID = 5){
        baseStats.addStat("spd", -1*buffMagnitude);
    }
    else{
        baseStats.addStat("lck", -1*buffMagnitude);
    }
    buffMagnitude = 0;
    buffID = 0;
}

void Player::BuffChosen(string& stat){ //playermove
    if(buffID != 0 || buffCounter != 0){ //second case added just in case something slipped
        cout << "You already have a buff! No stacking allowed." << endl;
    }
    else if (stat == "atk") {
        buffID = 1;
        buffMagnitude = baseStats.getAtk()*0.5;
        applyStatBoost(stat, baseStats.getAtk()*0.5);
        buffCounter = 3;
    } 
    else if (stat == "def") {
        buffID = 2;
        buffMagnitude = baseStats.getDef()*0.5;
        applyStatBoost(stat, baseStats.getDef()*0.5);
        buffCounter = 3;
    } 
    else if (stat == "matk") {
        buffID = 3;
        buffMagnitude = baseStats.getMAtk()*0.5;
        applyStatBoost(stat, baseStats.getMAtk()*0.5);
        buffCounter = 3;
    } 
    else if (stat == "mdef") {
        buffID = 4;
        buffMagnitude = baseStats.getMDef()*0.5;
        applyStatBoost(stat, baseStats.getMDef()*0.5);
        buffCounter = 3;
    } 
    else if (stat == "spd") {
        buffID = 5;
        buffMagnitude = baseStats.getSpd()*0.5;
        applyStatBoost(stat, baseStats.getSpd()*0.5);
        buffCounter = 3;
    } 
    else if (stat == "lck") {
        buffID = 6;
        buffMagnitude = baseStats.getLck()*0.5;
        applyStatBoost(stat, baseStats.getLck()*0.5);
        buffCounter = 3;
    } 
    else {
        std::cout << "Invalid stat name!" << std::endl;
    }   
}