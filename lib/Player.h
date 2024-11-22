#pragma once
#include <string>
using namespace std;

class Player {
public:
    Player() = delete;
    Player(string race);
    void move(string dir);
    pair<int, int> getPosition();
    void applyStatBoost(const std::string& stat, int boost);
    void heal(int amount);
    void displayStats() const;
    int& getStatRef(const string& stat);

private:
    string race;
    int positionX = 0;
    int positionY = 7;
    int baseHp = 0;
    int baseAtk = 0;
    int baseDef = 0;
    int baseMatk = 0;
    int baseMdef = 0;
    int baseSpd = 0;
    int baseLuck = 0;  
};