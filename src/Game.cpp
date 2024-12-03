#include "../lib/Game.h"
#include <iostream>
#include <fstream>
using namespace std;
Game::Game(){
    
}

void Game::setFirstStageFalse(){ 
    firstStage = false;
    secondStage = true;
}

void Game::setSecondStageFalse(){
    secondStage = false;
    thirdStage = true;
}

void Game::setThirdStageFalse(){
    thirdStage = false;
    gameOver = true;
}

void Game::save(){
    ofstream outFile("saveFile.txt");
    if(!outFile.is_open()){
        cout << "Error: could not save the game" << endl;
        return;
    }
    // game constructor member stats
    outFile << firstStage << ' ' << secondStage << ' ' << thirdStage << ' ' << gameOver << endl;
    // map backup
    for(int i = 0; i < map.getMapOfTiles().size(); i++){
        for(int j = 0; j < map.getMapOfTiles().at(j).size(); j++){
            if(i == map.getMapOfTiles().size() - 1 && j == map.getMapOfTiles().at(j).size() - 1){
                outFile << map.getMapOfTiles().at(i).at(j)->isVisited() << endl;
            }else{
                outFile << map.getMapOfTiles().at(i).at(j)->isVisited() << ' ';
            }
        }
    }
    // inventory backup and inventory keys
    // potion 0, rare potion 1, epic potion 2, legendary potion 3
    // iron sword 4, chain mail 5, lance 6, staff 7, plate armor 8, excalibur 9, 
    // bow of hou yi 10, labrys 11, thief's glove 12, cloak of invisibility 13
    for(int i = 0; i < inventory.getInventory().size(); i++){
        if(inventory.getInventory()[i]->getName() == "Potion"){
            outFile << 0;
        }else if(inventory.getInventory()[i]->getName() == "Rare Potion"){
            outFile << 1;
        }else if(inventory.getInventory()[i]->getName() == "Epic Potion"){
            outFile << 2;
        }else if(inventory.getInventory()[i]->getName() == "Legendary Potion"){
            outFile << 3;
        }else if(inventory.getInventory()[i]->getName() == "Iron Sword"){
            outFile << 4;
        }else if(inventory.getInventory()[i]->getName() == "Chain Mail"){
            outFile << 5;
        }else if(inventory.getInventory()[i]->getName() == "Lance"){
            outFile << 6;
        }else if(inventory.getInventory()[i]->getName() == "Staff"){
            outFile << 7;
        }else if(inventory.getInventory()[i]->getName() == "Plate Armor"){
            outFile << 8;
        }else if(inventory.getInventory()[i]->getName() == "Excalibur"){
            outFile << 9;
        }else if(inventory.getInventory()[i]->getName() == "Bow of Hou Yi"){
            outFile << 10;
        }else if(inventory.getInventory()[i]->getName() == "Labrys"){
            outFile << 11;
        }else if(inventory.getInventory()[i]->getName() == "Thief's Glove"){
            outFile << 12;
        }else if(inventory.getInventory()[i]->getName() == "Cloak of Invisibility"){
            outFile << 13;
        }
        if(i == inventory.getInventory().size() - 1){
            outFile << endl;
        }else{
            outFile << ' ';
        }
    }
    // player backup
    outFile << player.getPositionX() << ' ' << player.getPositionY() << ' ' << player.getBuffCounter() << endl;
    // stats backup
    outFile << player.getStats().getMaxHP() << ' ' << player.getStats().getAtk() << ' ' << player.getStats().getMAtk() << ' ' << player.getStats().getDef() << ' ' << player.getStats().getMDef() << ' ' << player.getStats().getSpd() << ' ' << player.getStats().getLck() << endl;
    
    outFile.close();
    cout << "Game saved successfully!" << endl;
}

void Game::controls(){
    bool validChoice = false;
    char choice;
    cout << "Enter in a command: ";
    while(!validChoice){
        cin >> choice;
        if(choice == 'M' || choice == 'I' || choice == 'S' || choice == 'X' || choice == 'C' || choice == 'T'){
            validChoice = true;
        }else{
            cout << "Invalid menu choice! Try again! Remember that you can always press C to see all available commands!" << endl;
        }
    }
    switch(choice){
        case 'M':
            player.move(map, inventory);
            screen.displayMapScreen(map, player); // automatically show map after every move?
        case 'I':
            screen.displayInventory(inventory);
            break;
        case 'S':
            // there needs to be a function that shows the current stats of the player
            // screen.displayStats(player);
            break;
        case 'X':
            screen.displayCredits();
            break;
        case 'T':
            save();
            break;
        case 'C':
            screen.displayCommandMenu();
            break;
    }
}
void Game::startGame(){
    screen.displayIntroScreen();
    screen.displayInstructions();
    while(!gameOver){
        while(firstStage){
            controls();
        }
        while(secondStage){
            controls();
        }
            break;
        while(thirdStage){
            controls();
        }
    }
}
