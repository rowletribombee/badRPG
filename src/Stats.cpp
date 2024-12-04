#include "../lib/Stats.h"

Stats::Stats(){
    hpMax = 0, hp = 0, atk = 0, def = 0, matk =0 , mdef = 0, spd = 0, lck = 0;
}

Stats::Stats(vector <int>& customStats){
    assert(customStats.size() == 8 && "Max HP value is not greater than hp");
    hpMax = customStats.at(0);
    hp = customStats.at(1);
    atk = customStats.at(2);
    def = customStats.at(3);
    matk = customStats.at(4);
    mdef = customStats.at(5);
    spd = customStats.at(6);
    lck = customStats.at(7);
}

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
    if(hp < 0){
        hp = 0;
    }
}

int Stats::getDef() const{
    return def;
}

int Stats::getHP() const{
    return hp;
}

int Stats::getMaxHP() const{
    return hpMax;
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

int Stats::getAtk() const{
    return atk;
}

int Stats::getMAtk() const{
    return matk;
}

void Stats::addHP(int hpVal){
    hp += hpVal;
    if(hpVal > hpMax){
        hp = hpMax;
    }
}

void Stats::addStat(const std::string& stat, int value) {
    if (stat == "hp") {
        hp += value;
        if (hp > hpMax) {
            hp = hpMax;
        }
    } 
    else if (stat == "atk") {
        atk += value;
    } 
    else if (stat == "def") {
        def += value;
    } 
    else if (stat == "matk") {
        matk += value; 
    } 
    else if (stat == "mdef") {
        mdef += value;
    } 
    else if (stat == "spd") {
        spd += value;
    } 
    else if (stat == "lck") {
        lck += value;
    } else {
        std::cout << "Invalid stat name!" << std::endl;
    }
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
    return (distribution(gen));
    
}
