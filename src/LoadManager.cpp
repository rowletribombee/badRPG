#include "../lib/LoadManager.h"

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
        cout << endl << endl;
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
    return game;
}