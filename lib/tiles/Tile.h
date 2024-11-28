#pragma once
#include <string>
using namespace std;

class Tile{
    protected:
        bool visited = false;
        bool instantEquip;
    public:
        Tile();
        void setVisited(){ visited = true; }
        bool isVisited() const {return visited;}
};