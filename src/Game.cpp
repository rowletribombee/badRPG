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
    outFile << firstStage << endl;
    outFile << secondStage << endl;
    outFile << thirdStage << endl;
    outFile << gameOver << endl;
    outFile.close();
    cout << "Game saved successfully!" << endl;
}

void Game::controls(){
    bool validChoice = false;
    char choice;
    while(!validChoice){
        cin >> choice;
        if(choice == 'M' || choice == 'I' || choice == 'S' || choice == 'A' || choice == 'C' || choice == 'T'){
            validChoice = true;
        }else{
            cout << "Invalid menu choice! Try again! Remember that you can always press C to see all available commands!" << endl;
        }
    }
    switch(choice){
        case 'M':
            player.move(map);
            screen.displayMapScreen(map, player); // automatically show map after every move?
            break;
        case 'I':
            break;
        case 'S':
            break;
        case 'A':
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
    screen.displayInstructions();
    while(!gameOver){
        while(firstStage){
            controls();
        }
        while(secondStage){
            controls();
        }
        while(thirdStage){
            controls();
        }
    }
}
