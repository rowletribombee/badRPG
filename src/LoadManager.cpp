#include "../lib/LoadManager.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"
#include <fstream>
#include <sstream>
using namespace std;

LoadManager::LoadManager(){}

Game& LoadManager::loadGame(Game& game){
    screen.displayStartScreen();
    bool beginGame = false;
    while(!beginGame){
        char choice;
        bool validChoice = false;
        while(!validChoice){
            cin >> choice;
            if(isalpha(choice) && (choice == 'A' || choice == 'B' || choice == 'C')){
                validChoice = true;
            }else{
                cout << "Invalid option! Try again: ";
            }
        }
        cout << endl;
        if(choice == 'A'){
                
            return loading(game);
        }
        if(choice == 'B'){
            return game;
        }
        if(choice == 'C'){
            screen.displayCredits();
            screen.displayStartScreen();
        }
    }
    return game;
}

Game& LoadManager::loading(Game& game){
    ifstream inFile("saveFile.txt");
    if(!inFile.is_open()){
        cout << "Error: file could not be opened. File must be named 'saveFile.txt'" << endl << endl << "A new game will be loaded" << endl;
        return game;
    }

    // game class loading
    int firstStage, secondStage, thirdStage, gameOver;
    inFile >> firstStage >> secondStage >> thirdStage >> gameOver;
    if(thirdStage){
        game.setSecondStageFalse();
        game.setFirstStageFalse();
    }else if(secondStage){
        game.setFirstStageFalse();
    }
    if(gameOver) game.setGameOver();
    // map loading
    int tile;
    for(int i = 0; i < game.getMap().getMapOfTiles().size(); i++){
        for(int j = 0; j < game.getMap().getMapOfTiles().at(i).size(); j++){
            inFile >> tile;
            if(tile == 1) game.getMap().getMapOfTiles().at(i).at(j)->setVisited();
        }
    }
    
    // inventory backup and inventory keys
    // potion 0, rare potion 1, epic potion 2, legendary potion 3
    // iron sword 4, chain mail 5, lance 6, staff 7, plate armor 8, excalibur 9, 
    // bow of hou yi 10, labrys 11, thief's glove 12, cloak of invisibility 13
    string line;
    getline(inFile, line);
    getline(inFile, line); 
    istringstream lineStream(line); 
    cout << line;
    int item;
    while (lineStream >> item) { // Read each item in the line
        if (item == 0) {
            game.getInventory().addItem(new Potion("Potion", 20));
        } else if (item == 1) {
            game.getInventory().addItem(new Potion("Rare Potion", 30));
        } else if (item == 2) {
            game.getInventory().addItem(new Potion("Epic Potion", 40));
        } else if (item == 3) {
            game.getInventory().addItem(new Potion("Legendary Potion", 10000));
        } else if (item == 4) {
            game.getInventory().addItem(new Weapon("Iron Sword", 1, 1, 0, 0, 0, 0));
        } else if (item == 5) {
            game.getInventory().addItem(new Weapon("Chain Mail", 0, 2, 0, 0, 0, 0));
        } else if (item == 6) {
            game.getInventory().addItem(new Weapon("Lance", 1, 0, 0, 0, 1, 0));
        } else if (item == 7) {
            game.getInventory().addItem(new Weapon("Staff", 0, 0, 1, 1, 0, 0));
        } else if (item == 8) {
            game.getInventory().addItem(new Weapon("Plate Armour", 0, 1, 0, 2, 0, 0));
        } else if (item == 9) {
            game.getInventory().addItem(new Weapon("Excalibur", 0, 1, 0, 2, 0, 0));
        } else if (item == 10) {
            game.getInventory().addItem(new Weapon("Bow of Hou Yi", 0, 1, 0, 2, 0, 0));
        } else if (item == 11) {
            game.getInventory().addItem(new Weapon("Labrys", 0, 1, 0, 2, 0, 0));
        } else if (item == 12) {
            game.getInventory().addItem(new Weapon("Thief's Glove", 0, 1, 0, 2, 0, 0));
        } else if (item == 13) {
            game.getInventory().addItem(new Weapon("Cloak of Invisibility", 0, 1, 0, 2, 0, 0));
        } else if(item == -1){
            break;   
        }
    }
    int x, y, buff;
    inFile >> x >> y >> buff;
    game.getPlayer().setPositionX(x);
    game.getPlayer().setPositionY(y);
    game.getPlayer().setBuffCounter(buff);
    
    int maxhp, hp, atk, matk, def, mdef, spd, lck;
    inFile >> maxhp >> hp >> atk >> matk >> def >> mdef >> spd >> lck;
    game.getPlayer().getStats().setMaxHp(maxhp);
    game.getPlayer().getStats().setHp(hp);
    game.getPlayer().getStats().setAtk(atk);
    game.getPlayer().getStats().setMAtk(matk);
    game.getPlayer().getStats().setDef(def);
    game.getPlayer().getStats().setMDef(mdef);
    game.getPlayer().getStats().setLck(lck);
    game.getPlayer().getStats().setSpd(spd);
    return game;
}

    
