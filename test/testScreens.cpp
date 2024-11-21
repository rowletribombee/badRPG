#include "../lib/Screen.h"
#include "../lib/Map.h"
#include "../lib/Player.h"
#include "../lib/tiles/Tile.h"
#include <iostream>
using namespace std;

//used g++ -I.testScreens.cpp ../src/Screen.cpp -o screenTest to compile 
int main()
{
    Screen screenTest;

    //test start screen 
    // cout << "Start screen:" << endl;
    // screenTest.displayStartScreen();

    // cout << endl << endl;

    // // //test instruciton screen 
    // cout << "Instructions: " << endl;
    // screenTest.displayInstructions();

    // //test intro display
    // cout << "Intro:" << endl;
    // screenTest.displayIntroScreen();

    // test command manu 
    // cout << "Command screen:" << endl;
    // screenTest.displayCommandMenu();

    // //test inventory print 
    // //Needs items and weapons 
    // cout << "Inventory screen:" << endl;
    // screenTest.displayInventory();

    // //test credit print
    // cout << "Credits:" << endl;
    // screenTest.displayCredits();

    //test map display
    cout << "Map Display:" << endl;
    
    //create objects
    Map map;
    map.initialize();

    Player player;


    //mark first tile as visited
    Tile tile;
    // tile = map.getMapOfTiles()[0][0];
    // tile.setVisited();
    // tile.setVisited();
    // tile = map.getMapOfTiles()[0][1];
  


    screenTest.displayMapScreen(map,player);
    return 0;
}