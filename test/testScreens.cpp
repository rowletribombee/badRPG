#include "../lib/Screen.h"
#include "../lib/Map.h"
#include "../lib/Player.h"
#include "../lib/tiles/Tile.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    Screen screenTest;

    //test start screen 
    cout << "Start screen:" << endl;
    screenTest.displayStartScreen();
 

    cout << endl << endl;
 

    //test instruciton screen 
    cout << "Instructions: " << endl;
    screenTest.displayInstructions();


    //test intro display
    cout << "Intro:" << endl;
    screenTest.displayIntroScreen();



    // test command menu 
    cout << "Command screen:" << endl;
    screenTest.displayCommandMenu();

    //test inventory print 
    //Needs items and weapons 
    cout << "Inventory screen:" << endl;
    screenTest.displayInventory();

    //test credit print
    cout << "Credits:" << endl;
    screenTest.displayCredits();

    //test map display
    cout << "Map Display:" << endl;
    
    //create objects
    Player player;
    Map map;

    istringstream input("w\nd\nd\n");
    cin.rdbuf(input.rdbuf());

    player.move(map); // Reads 'w'
    player.move(map); // Reads 'd'
    player.move(map); // Reads 'd'

    //output map with player currently on (x) [2,1] and [0,0][0,1][1,1] visited (x)
    screenTest.displayMapScreen(map,player);
    return 0;
}