#include "Screen.hpp"
// #include "Game.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void Screen::sleep_for(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds)); //pause for x amount of seconds
}
void Screen::displayInventory()
{
    cout << "========Inventory========" << endl;
}

void Screen::displayIntroScreen()
{
    Screen screen;

    //intro scene 
    cout << "\"Where...where am I?\" you mutter to yourself. The question hangs in the air unanswered. "
    "You scan the dark, cold cavern as your eyes slowly adjust to the dim light."
     "No signs of life, no clear way out. You pat your pant pockets reflexively--empty. A sense of unease and worry settles." << endl << endl;
    
    screen.sleep_for(4000); //pause for 4 seconds

    cout << "No phone. No signal. No Internet." << endl << endl;

    screen.sleep_for(2000); //pause for 2 seconds

    cout << "\"Okay...think\" you mumble, trying to clear your racing thoughts. \"I'm in a cave, it's dark, it's cold. I have no memory. This is fine. This is totally fine.\" you lie to yourself." << endl << endl;

    screen.sleep_for(2000); //pause for 2 seconds

    cout << "\"Hm I could really go for a hot dog\" You think to yourself as your confused state becomes more stable. You scan the room until you notice a faint glimmer in the corner of your eye. " << endl;
    cout << "It almost feels...familiar. Maybe it's hope. Maybe it's a trap. Maybe it's my imagination. \"Guess I've got no choice\" you sigh, realizing it's your only lead." << endl;
    cout << "You rise to your feet and set off into the unknown." << endl << endl;

    screen.sleep_for(4000); //puase for 4 seconds

    cout << "\"Let's find out what's waiting for me down there.\"" << endl << endl;


    screen.sleep_for(2000); //puase for 2 seconds

    cout << "..." << endl << endl;


    //character selection


}