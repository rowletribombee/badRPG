#pragma once
#include <string>
#include "Map.h"
#include "Stats.h"
using namespace std;
class Player{
    public:
        Player();
        Player(string race);
        Player(Stats&);
        void move(Map& map);
        bool checkForWall(char dir);
        bool checkValidDir(char dir);
        int getPositionX() { return positionX; }
        int getPositionY() { return positionY; }
        friend class Screen;
        bool isGuarding = false;
        void applyStatBoost(const std::string& stat, int boost);
        void heal(int amount);

    private:
        Stats baseStats;
        int positionX = 0;
        int positionY = 7;
        int buffCounter = 0; // from prev player.h file

        void Attack(Stats&) const;
        void MagicAttack(Stats&) const;
        void Heal();
        void BuffChosen(string&);
        void Guard();
        void Throw(Stats&) const; //should also take an item       
        Stats& getStats() const; //gets stats from the player class, will be used in battle
};