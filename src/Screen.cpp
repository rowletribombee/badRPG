#include "../lib/Screen.h"
#include "../lib/Game.h"
#include "../lib/Player.h"
#include <iostream>

Screen::Screen(){

}

// MAP LEGEND
// ??? for undiscovered
//  x  for spot they are on
//  o for spot they already visited

void Screen::displayMapScreen(Map& map, Player& player){
    // vector<vector<Tile>>& mapOfTiles
    for(int i = 0; i < map.getMapOfTiles().size(); i++){
        for(int j = 0; j < map.getMapOfTiles().at(i).size(); j++){
            cout << "-------------";
        }
        cout << endl;
        for(int j = 0; j < map.getMapOfTiles().at(i).size(); j++){
            cout << "|           |";
        }
        cout << endl;
        for(int j = 0; j < map.getMapOfTiles().at(i).size(); j++){
            cout << "|    ";
            if(!map.getMapOfTiles().at(i).at(j).isVisited()){
                cout << "???";
            }else if(map.getMapOfTiles().at(i).at(j).isVisited() && player.positionY == i && player.positionX == j){
                cout << " x ";
            }else{
                cout << " o ";
            }
            cout << "    |";
        }
        cout << endl;
        for(int j = 0; j < map.getMapOfTiles().at(i).size(); j++){
            cout << "|           |";
        }
        cout << endl;
    }
    for(int i = 0; i < map.getMapOfTiles().size(); i++){
        cout << "-------------";
    }
    cout << endl;
}