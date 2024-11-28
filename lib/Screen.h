#pragma once
#include "Player.h"
#include "Map.h"
#include "Inventory.h"
class Screen{
    public:
        Screen();
        void displayMapScreen(Map& mapOfTiles, Player& player);
        void displayStartScreen();
        void displayCommandMenu();
        void displayInstructions();
        void displayIntroScreen();
        void displayInventory(Inventory& inventory);
        void displayMapScreen();
        void sleep_for(int milliseconds);
        void displayCredits();
        void displayRaceSelection(Player& player);
        void displayRaceStats();
    private:
};