#include "../lib/Screen.h"
#include <iostream>

Screen::Screen(){

}

void Screen::displayMapScreen(vector<vector<Tile>>& mapOfTiles){
    for(int i = 0; i < mapOfTiles.size(); i++){
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "-------------";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "|           |";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "|    ";
            if(!mapOfTiles.at(i).at(j).isVisited()){
                cout << "???";
            }else{
                cout << " x ";
            }
            cout << "    |";
        }
        cout << endl;
        for(int j = 0; j < mapOfTiles.at(i).size(); j++){
            cout << "|           |";
        }
        cout << endl;
    }
    for(int i = 0; i < mapOfTiles.size(); i++){
        cout << "-------------";
    }
    cout << endl;
}