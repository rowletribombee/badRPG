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

void Stats::reduceHp(int minus){
    hp -= minus;
}

int Stats::getDef() const{
    return def;
}

int Stats::getMDef() const{
    return mdef;
}

int Stats::getSpd() const{
    return spd;
}

int Stats::getLck() const{
    return lck;
}

bool Stats::AccuracyCheck(Stats& opponent) const{
    int AccuracyDivisor = opponent.getLck()*0.5 + lck; //vary the multiplier for opponent luck in balancing
    return (rng(0,AccuracyDivisor) < lck); //gives a boolean with a lck/AccuracyDivisor chance of being true (I think)
}

bool Stats::CritCheck(Stats& opponent) const{
    int CritDivisor = opponent.getLck()*2;
    return (rng(0, CritDivisor) < lck);
}

int Stats::rng(int min, int max) const{
    random_device rd;
    static mt19937 gen(rd()); //generates pseudorandom using mersenne twister
    static uniform_int_distribution<> distribution(min, max); //random int values on interval
    return distribution(gen);
}