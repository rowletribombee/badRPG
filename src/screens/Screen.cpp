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

void Screen::displayInstructions()
{
    cout << "Welcome to “I woke up in a Cave and All I Want is Wi-fi”!" << endl << endl;
    cout << "Your Mission: You’ve awoken in a mysterious cave with no memory of how you got there. As you explore the different rooms the cave has to offer, you must face off a series of bosses to uncover the truth and find a way out. Remember: the Wi-fi signal is weak, but your determination is strong!";
    cout << endl << endl;
    cout << "Game controls:" << endl;
    cout << "(These will be available as you play)" << endl;
    cout << endl;
    cout << "Move[M]: Choose your movement direction (Forward, Left, Right, Back)" << endl;
    cout << "Inventory[I]: Check your items and equip gear" << endl;
    cout << "Stats [S]: View your character’s current stats" << endl;
    cout << "Actions[A]: Choose your action during combat (Fight, flee, defend)" << endl;
    cout << "Command Menu[C]: Move, check Inventory, view Stats, or Quit and Save your game" << endl;
    cout << endl;
    cout << "As you explore more rooms you may encounter items or weapons. You may equip these and use them to advance to victory!" << endl;
    cout << endl;
    cout << "Final Note:" << endl;
    cout << "Your journey through the cave may be filled with uncertainty, but keep your sense of humor and discovery alive! Embrace the chaos and remember: sometimes, laughter is the best weapon against despair (or goblins). Good luck!" << endl;
}

void Screen::displayIntroScreen()
{
    Screen screen;

    //intro scene text
    string intro_A ="\"Where...where am I?\" you mutter to yourself. The question hangs in the air unanswered. You scan the dark, cold cavern as your eyes slowly adjust to the dim light. No signs of life, no clear way out. You pat your pant pockets reflexively--empty. A sense of unease and worry settles.";
    string intro_B = "No phone. No signal. No Internet.";
    string intro_C = "\"Okay...think\" you mumble, trying to clear your racing thoughts. \"I'm in a cave, it's dark, it's cold. I have no memory. This is fine. This is totally fine.\" you lie to yourself.";

    //print intro char by char
    for (char c: intro_A)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << endl << endl;
   
    screen.sleep_for(2000); //pause for 2 seconds
    
    for(char c : intro_B)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << endl << endl;
    
    screen.sleep_for(2000); //pause for 2 seconds
    
    for(char c : intro_C)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
    cout << endl << endl;

    screen.sleep_for(2000); //pause for 2 seconds

    string intro_D = "\"Hm I could really go for a hot dog\" You think to yourself as your confused state becomes more stable. You scan the room until you notice a faint glimmer in the corner of your eye. It almost feels...familiar. Maybe it's hope. Maybe it's a trap. Maybe it's my imagination. \"Guess I've got no choice\" you sigh, realizing it's your only lead. You rise to your feet and set off into the unknown.";

    for(char c : intro_D)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
    cout << endl << endl;

    string intro_E = "\"Let's find out what's waiting for me down there.\"";

    for(char c : intro_E)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << endl << endl;
    

    cout << "..." << endl << endl;


    //character selection
    

}

void Screen::displayInventory()
{
    cout << "========Inventory========" << endl;
}