#pragma once
#include <string>
#include "Map.h"
#include "Inventory.h"
#include "Stats.h"
using namespace std;
class Player{
    public:
        Player();
        Player(string race);
        Player(Stats&);
        void move(Map& map, Inventory& inventory);
        bool checkForWall(char dir);
        bool checkValidDir(char dir);
        int getPositionX() { return positionX; }
        int getPositionY() { return positionY; }
        bool isGuarding = false;
        void applyStatBoost(const std::string& stat, int boost); //not for the user to use
        void heal(int amount); //utility heal
        Stats& getStats() {return baseStats; } //gets stats from the player class, will be used in battle
        int buffCounter = 0;
        int buffMagnitude = 0;
        int buffID = 0;

    private:
        Stats baseStats;
        int positionX = 0;
        int positionY = 7;

        void Attack(Stats&) const;
        void MagicAttack(Stats&) const;
        void HealPlayer();
        void BuffChosen(string&); //gives +3 to the stats
        void Guard();
        void Throw(Stats&) const; //should also take an item       
};