#include "Screen.hpp"
#include <iostream>
using namespace std;

//used g++ -I../lib/screens testScreens.cpp ../src/screens/Screen.cpp -o screenTest to compile 
int main()
{
    Screen screenTest;

    //test start screen syntax
    cout << "Start screen:" << endl;
    screenTest.displayStartScreen();


    //test command manu syntax
    cout << "Command screen:" << endl;
    screenTest.displayCommandMenu();

    //test inventory print syntax
    cout << "Inventory screen:" << endl;
    screenTest.displayInventory();

    //test intro display
    cout << "Intro:" << endl;
    screenTest.displayIntroScreen();


    return 0;
}