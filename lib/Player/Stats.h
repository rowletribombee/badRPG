#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Stats{
    protected:
        int hpMax, hp, atk, def, matk, mdef, spd, lck; 
        //bool buffCond1, buffCond2;
        //int charClass; //0 for wizard, 1 for knight, 2 for rogue, 3 for barbarian, 4 for 

    public:
        void isHuman();
        void isElf();
        void isDwarf();
        void isOgre();
        void isFairy();
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