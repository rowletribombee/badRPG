#pragma once
#include <string>
using namespace std;

class Player{
    public:
        Player() = delete;
        Player(string race) : race(race){}
        void move(string dir);
        pair<int, int> getPosition();
        void applyStatBoost(int boost);
        
    private:
        string race;
        int positionX = 0;
        int positionY = 7;
        int baseHp;
        int baseAtk;
        int baseDef;
        int baseMatk;
        int baseMdef;
        int baseSpd;
        int baseLuck;       
};