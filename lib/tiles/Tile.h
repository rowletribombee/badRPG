#pragma once
#include <string>
using namespace std;

class Tile{
    protected:
        bool visited = false;
    public:
        Tile();
        void setVisited(){ visited = true; }
        bool isVisited() const {return visited;}
};