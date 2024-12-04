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
        int getBuffCounter(){ return buffCounter; }
        int getBuffMagnitude(){return buffMagnitude;}
        int getBuffID(){return buffID;};
        void reduceBuffCounter();
        void resetBuffMagnitude();
        void resetBuffID();
        bool isGuarding = false;
        void applyStatBoost(const std::string& stat, int boost); //not for the user to use
        void heal(int amount); //utility heal
        Stats& getStats() {return baseStats; } //gets stats from the player class, will be used in battle
        void Attack(Stats&) const;
        void MagicAttack(Stats&) const;
        void HealPlayer();
        void BuffChosen(string&); //gives +3 to the stats
        void Guard();    

    private:
        Stats baseStats;
        int positionX = 0;
        int positionY = 7;
        int buffCounter = 0;
        int buffMagnitude = 0;
        int buffID = 0;

        
};