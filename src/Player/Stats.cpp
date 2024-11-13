#include "../../lib/Player/Stats.h"

Stats::Stats(string& n){
    name = n;
}

void Stats::isHuman(){
    hp = 60;
    atk = 7;
    def = 7;
    matk = 7;
    mdef = 7;
    spd = 7;
    lck = 7;
}

void Stats::isElf(){
    hp = 50;
    atk = 8;
    def = 6;
    matk = 7;
    mdef = 9;
    spd = 8;
    lck = 6;
}

void Stats::isDwarf(){
    hp = 70;
    atk = 8;
    def = 10;
    matk = 5;
    mdef = 6;
    spd = 5;
    lck = 6;
}

void Stats::isOgre(){
    hp = 90;
    atk = 10;
    def = 8;
    matk = 4;
    mdef = 4;
    spd = 8;
    lck = 3;
}

void Stats::isFairy(){
    hp = 40;
    atk = 5;
    def = 3;
    matk = 12;
    mdef = 10;
    spd = 9;
    lck = 5;
}