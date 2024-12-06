#include "../lib/Screen.h"
#include "../lib/Map.h"
#include "../lib/Player.h"
#include "../lib/tiles/Tile.h"
#include "../lib/Inventory.h"
#include "../lib/Potion.h"
#include "../lib/Weapon.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    Player displayTest;
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

    //test Direction Options
    cout << "Direction screen:" << endl;
    screenTest.displayDirectionOptions();

    //test credit print
    cout << "Credits:" << endl;
    screenTest.displayCredits();

    
    //testing display race
    cout << "Race Display" << endl;
    screenTest.displayRaceStats();
    
    //testing user race input
    cout << "Race Selection " << endl;
    screenTest.displayRaceSelection(displayTest);
    

    //test map display
    cout << "Map Display:" << endl;
    //create objects
    Player player;
    Map map;

    istringstream input("w\nd\nd\n");
    cin.rdbuf(input.rdbuf());

    Inventory inventory;
    player.move(map, inventory); // Reads 'w'
    player.move(map, inventory); // Reads 'd'
    player.move(map, inventory); // Reads 'd'


    
    //output map with player currently on (x) [2,1] and [0,0][0,1][1,1] visited (x)
    screenTest.displayMapScreen(map,player);

    // Test inventory display
    cout << "Inventory Display:" << endl;
    Potion* potion = new Potion("Health Potion", 50);
    Weapon* sword = new Weapon("Sword", 5, 2, 0, 0, 0, 0);

    inventory.addItem(potion);
    inventory.addItem(sword);

    screenTest.displayInventory(inventory);

    return 0;
}