#include "Screen.hpp"
#include <iostream>
using namespace std;

//used g++ -I../lib/screens testScreens.cpp ../src/screens/Screen.cpp -o screenTest to compile 
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

    //test command manu 
    cout << "Command screen:" << endl;
    screenTest.displayCommandMenu();

    //test inventory print 
    cout << "Inventory screen:" << endl;
    screenTest.displayInventory();

    //test intro display
    cout << "Intro:" << endl;
    screenTest.displayIntroScreen();


    return 0;
}