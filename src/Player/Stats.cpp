#include "../../lib/Player/Stats.h"

void Stats::isHuman(){
    hpMax = 60;
    hp = 60;
    atk = 7;
    def = 7;
    matk = 7;
    mdef = 7;
    spd = 7;
    lck = 7;
}

void Stats::isElf(){
    hpMax = 50;
    hp = 50;
    atk = 8;
    def = 6;
    matk = 7;
    mdef = 9;
    spd = 8;
    lck = 6;
}

void Stats::isDwarf(){
    hpMax = 70;
    hp = 70;
    atk = 8;
    def = 10;
    matk = 5;
    mdef = 6;
    spd = 5;
    lck = 6;
}

void Stats::isOgre(){
    hpMax = 90;
    hp = 90;
    atk = 10;
    def = 8;
    matk = 4;
    mdef = 4;
    spd = 8;
    lck = 3;
}

void Stats::isFairy(){
    hpMax = 40;
    hp = 40;
    atk = 5;
    def = 3;
    matk = 12;
    mdef = 10;
    spd = 9;
    lck = 5;
}