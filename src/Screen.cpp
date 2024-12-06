#include "../lib/Screen.h"
#include "../lib/Game.h"
#include "../lib/Player.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

Screen::Screen(){}

void Screen::sleep_for(int milliseconds){
    this_thread::sleep_for(chrono::milliseconds(milliseconds)); //pause for x amount of seconds
}

void Screen::displayStartScreen(){
    cout << "You wake up in a cave and you crave the internet…" << endl << endl <<
            "[A] Load Saved Game" << endl <<
            "[B] New Game" << endl <<
            "[C] Credits" << endl;
            "Choose an option: ";
}

void Screen::displayCommandMenu(){ 
    cout << "What will you do?" << endl << endl <<
            "[M] Move" << endl <<
            "[I] Inventory" << endl << 
            "[S] Stats" << endl <<
            "[G] Map" << endl <<
            "[Q] Quit and Save" << endl <<
            "[C] Command Menu" << endl <<
            "[X] Credits" << endl << endl;
}

void Screen::displayDirectionOptions(){
    cout << "What direction will you go?" << endl << endl <<
            "[w] Up" << endl << 
            "[a] Left" << endl <<
            "[s] Down" << endl <<
            "[d] Right" << endl << endl << "Enter in a direction: ";
}

void Screen::displayInstructions()
{
    cout << "Welcome to “I woke up in a Cave and All I Want is Wi-fi”!" << endl << endl;
    cout << "Your Mission: You've awoken in a mysterious cave with no memory of how you got there. As you explore the different rooms the cave has to offer, you must face off a series of bosses to uncover the truth and find a way out. Remember: the Wi-fi signal is weak, but your determination is strong!";
    cout << endl << endl;
    cout << "=========================================" << endl;
    cout << "Game controls:" << endl;
    cout << "(These will be available as you play)" << endl;
    cout << endl;
    cout << "[M] Move: Choose your movement direction (Forward, Left, Right, Back)" << endl;
    cout << "[I] Inventory: Check your items and equip gear" << endl;
    cout << "[S] Stats: View your characters current stats" << endl;
    cout << "[A] Actions: Choose your action during combat (Fight, flee, defend)" << endl;
    cout << "[G] Map: See your current position on the map and places you've visited before" << endl;
    cout << "[Q] Quit and Save: Quit and save your game locally" << endl;
    cout << "[C] Command Menu: Move, check Inventory, view Stats, or Quit and Save your game";
    cout << endl;
    cout << "=========================================" << endl << endl;
    cout << "As you explore more rooms you may encounter items or weapons. You may equip these and use them to advance to victory!" << endl;
    cout << endl;
    cout << "Final Note:" << endl;
    cout << "Your journey through the cave may be filled with uncertainty, but keep your sense of humor and discovery alive! Embrace the chaos and remember: sometimes, laughter is the best weapon against despair (or goblins). Good luck!" << endl << endl;

    sleep_for(3000); //pause for 3 seconds
}

void Screen::displayIntroScreen(){
    Screen screen;

    //intro scene text
    string intro_A ="\"Where...where am I?\" you mutter to yourself. The question hangs in the air unanswered. You scan the dark, cold cavern as your eyes slowly adjust to the dim light. No signs of life, no clear way out. You pat your pant pockets reflexively--empty. A sense of unease and worry settles.";
    string intro_B = "No phone. No signal. No Internet.";
    string intro_C = "\"Okay...think\" you mumble, trying to clear your racing thoughts. \"I'm in a cave, it's dark, it's cold. I have no memory. This is fine. This is totally fine.\" you lie to yourself.";

    //print intro char by char
    for (char c: intro_A){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << endl << endl;
   
    screen.sleep_for(2000); //pause for 2 seconds
    
    for(char c : intro_B){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << endl << endl;
    
    screen.sleep_for(2000); //pause for 2 seconds
    
    for(char c : intro_C){
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    
    cout << endl << endl;

    screen.sleep_for(2000); //pause for 2 seconds

    string intro_D = "\"Hm I could really go for a hot dog\" You think to yourself as your confused state becomes more stable. You scan the room until you notice a faint glimmer in the corner of your eye. It almost feels...familiar. Maybe it's hope. Maybe it's a trap. Maybe it's my imagination. \"Guess I've got no choice\" you sigh, realizing it's your only lead. You rise to your feet and set off into the unknown.";

    for(char c : intro_D){
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
}

void Screen::displayInventory(Inventory& inventory){
    cout << "========Inventory========" << endl;
    //TO-DO
    //Items still being figured out
}

void Screen::displayCredits(){
    cout << "Developed by:" << endl;
    cout << "Stanley Lew" << endl;
    cout << "Sookie Drabla" << endl;
    cout << "Gregory Wang" << endl;
    cout << "Kelly Ma" << endl;
    cout << "Anthony Emery" << endl << endl;
}

void Screen::displayRaceStats(){
    Stats displayStats;

    cout << "**************************************************\n";
    cout << "*                                                *\n";
    cout << "*                   STATS SCREEN                 *\n";
    cout << "*                                                *\n";
    cout << "**************************************************\n";
    cout << endl;

    cout << "Choose a race for your character! (Enter a number 1-5)\n";
    cout << "--------------------------------------------------\n";

    auto charInfo = [](const Stats& stats) {
        cout << "   HP: " << stats.getHP() << "/" << stats.getMaxHP() << endl;
        cout << "   ATK: " << stats.getAtk() << " | DEF: " << stats.getDef() << endl;
        cout << "   MATK: " << stats.getMAtk() << " | MDEF: " << stats.getMDef() << endl;
        cout << "   SPD: " << stats.getSpd() << " | LCK: " << stats.getLck() << endl;
        cout << "-----------------------------------------" << endl;
    };

    cout << "1 Human" << endl;
    displayStats.isHuman();
    charInfo(displayStats);

    cout << "2 Elf" << endl;
    displayStats.isElf();
    charInfo(displayStats);

    cout << "3 Dwarf" << endl;
    displayStats.isDwarf();
    charInfo(displayStats);

    cout << "4 Ogre" << endl;
    displayStats.isOgre();
    charInfo(displayStats);

    cout << "5 Fairy" << endl;
    displayStats.isFairy();
    charInfo(displayStats);
}

void Screen::displayRaceSelection(Player& player){
    Stats& stats = player.getStats();
    auto charInfo = [](const Stats& stats) {
        cout << "   HP: " << stats.getHP() << "/" << stats.getMaxHP() << endl;
        cout << "   ATK: " << stats.getAtk() << " | DEF: " << stats.getDef() << endl;
        cout << "   MATK: " << stats.getMAtk() << " | MDEF: " << stats.getMDef() << endl;
        cout << "   SPD: " << stats.getSpd() << " | LCK: " << stats.getLck() << endl;
        cout << "-----------------------------------------" << endl;
    };


    int choice;
    bool validChoice = false;

    while (!validChoice){
        cin >> choice;

        if (choice == 1) 
        {
            stats.isHuman();
            cout << "You have chosen Human!" << endl;
            charInfo(stats);
            validChoice = true; 
        } 
        else if (choice == 2) 
        {
            stats.isElf();
            cout << "You have chosen Elf!" << endl;
            charInfo(stats);
            validChoice = true; 
        } 
        else if (choice == 3) 
        {
            stats.isDwarf();
            cout << "You have chosen Dwarf!" << endl;
            charInfo(stats);
            validChoice = true; 
        } 
        else if (choice == 4) {
            stats.isOgre();
            cout << "You have chosen Ogre!" << endl;
            charInfo(stats);
            validChoice = true; 
        } 
        else if (choice == 5) 
        {
            stats.isFairy();
            cout << "You have chosen Fairy!" << endl;
            charInfo(stats);
            validChoice = true; 
        } 
        else 
        {
            cout << "Invalid choice! Please choose a number between 1 and 5." << endl;
        }
    }
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
            if(map.getMapOfTiles().at(i).at(j)->isVisited() && player.getPositionY() == i && player.getPositionX() == j){
                cout << " x ";
            }else if(map.getMapOfTiles().at(i).at(j)->isVisited()){
                cout << " o ";
            }else{
                cout << "???";
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

