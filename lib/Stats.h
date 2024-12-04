#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <cassert>
using namespace std;

class Stats{
    protected:
        int hpMax, hp, atk, def, matk, mdef, spd, lck; 
        //bool buffCond1, buffCond2;
        //int charClass; //0 for wizard, 1 for knight, 2 for rogue, 3 for barbarian, 4 for 

    public:
        Stats();
        Stats(vector <int>&);
        void isHuman();
        void isElf();
        void isDwarf();
        void isOgre();
        void isFairy();
        int getHP() const;
        int getMaxHP() const;
        int getAtk() const;
        int getMAtk() const;
        int getDef() const;
        int getMDef() const;
        int getSpd() const;
        int getLck() const;
        void addHP (int); //for healing
        void addStat(const std::string&, int); // for weapons
        void reduceHp(int);
        int damageDealtPhys(Stats&, int); 
        int damageDealtMagic(Stats&, int);
        int rng(int, int) const; //gives random number between the two ints
        bool CritCheck(Stats& opponent) const;
        bool AccuracyCheck(Stats& opponent) const;
        /*
        Character classes
        void isWizard();
        void isKnight();
        void isRogue();
        void isBarbarian();
        void isArcher();
        */
       //enemy classes
};