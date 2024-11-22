#pragma once
#include <string>
using namespace std;
#include "Map.h"
#include "Stats.h"
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
    private:
        Stats baseStats;
        bool isGuarding = false;
        int positionX = 0;
        int positionY = 7;
        int buffCounter = 0; // from prev player.h file

        void Attack(Stats&) const;
        void MagicAttack(Stats&) const;
        void Heal();
        void BuffChosen(string&);
        void Guard();
        void Throw(Stats&) const; //should also take an item       
};