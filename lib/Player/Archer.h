#pragma once
#include "Stats.h"

class Archer{
    
    private:
        
        bool Aiming;

    public:
        int BuffTimer;
        Archer(Stats&);
        void Load();
        void Shelter();
        void Shoot();
        void TakeAim();

};