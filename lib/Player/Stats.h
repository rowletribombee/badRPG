#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Stats{
    protected:
        int hp, atk, def, matk, mdef, spd, lck;
        string name;

    public:
        Stats(string&);
        void isHuman();
        void isElf();
        void isDwarf();
        void isOgre();
        void isFairy();

};