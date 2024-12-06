#pragma once
#include <string>
#include "Map.h"
#include "Inventory.h"
#include "Stats.h"
#include "Screen.h"
using namespace std;
class Player{
    public:
        Player();
        Player(string race);
        Player(Stats&);
        Player(vector<int> bstats) : baseStats(bstats){};
        bool isGuarding = false;
        void move(Map& map, Inventory& inventory);
        bool checkForWall(char dir);
        bool checkValidDir(char dir);
        int getPositionX() { return positionX; }
        int getPositionY() { return positionY; }
        int getBuffCounter(){ return buffCounter; }
        int getBuffMagnitude(){return buffMagnitude;}
        int getBuffID(){return buffID;};
        void reduceBuffCounter();
        void resetBuffMagnitude(); //utility purposes
        void applyStatBoost(const std::string& stat, int boost); //utility purposes
        void heal(int amount); //utility heal
        Stats& getStats() {return baseStats; } //gets stats from the player class, will be used in battle
        void Attack(Stats&);
        void MagicAttack(Stats&);
        void HealPlayer();
        void BuffChosen(string&); //gives +3 to the stats
        void Guard();    

    private:
        Stats baseStats;
        int positionX;
        int positionY;
        int buffCounter = 0;
        int buffMagnitude = 0;
        int buffID = 0;

        
};