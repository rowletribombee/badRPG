#include "../lib/LoadManager.h"
#include <fstream>
using namespace std;

LoadManager::LoadManager(){}

Game LoadManager::loadGame(){
    screen.displayStartScreen();
    bool beginGame = false;
    Game game;
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
    int firstStage, secondStage, thirdStage;
    inFile >> firstStage >> secondStage >> thirdStage;
    if(thirdStage){
        game.setSecondStageFalse();
        game.setFirstStageFalse();
    }else if(secondStage){
        game.setFirstStageFalse();
    }
    // map loading
    

    return game;
}