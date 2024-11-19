#include "../lib/Game.h"
#include <iostream>

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

void Game::controls(){
    bool validChoice = false;
    int choice;
    // this line will be a screen print func that shows all available commands
    while(!validChoice){
        cin >> choice;
        if(choice >= 0 || choice <= 10){
            validChoice = true;
        }else{
            cout << "Invalid menu choice!" << endl;
            // this line will be a screen print func that shows all available commands
        }
    }
    if(choice == 0){
        player.move(map);
        screen.displayMapScreen(map, player);
    }
}
void Game::startGame(){
    while(!gameOver){
        while(firstStage){
            controls();
        }
        while(secondStage){

        }
        while(thirdStage){

        }
        screen.displayMapScreen(map, player);
    }
}
