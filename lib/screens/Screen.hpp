#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Screen 
{
    public:

    //inline 
    void displayStartScreen()
    {
        cout << "You wake up in a cave and you crave the internet…" << endl << endl <<
                "Load Save Game [1]" << endl <<
                    "New Game [2]" << endl <<
                    "Credits [3]" << endl;
    }

    void displayInstructions();
    void displayIntroScreen();

    //displays move options and promps user to chose
    void displayCommandMenu()
    { 
        cout << "What will you do?" << endl << endl <<
                "Move[M]" << endl <<
                "Inventory [I]" << endl << 
                "Stats [S]" << endl <<
                "Quit and Save [T]" << endl <<
                "Credits[X]" << endl;
    }

    void displayInventory();
    void displayMapScreen();
    void sleep_for(int milliseconds);
    void clearScreen();
};