#pragma once
#include <string>
using namespace std;

class Tile{
    protected:
        bool visited = false;
    public:
        Tile();
        virtual void print() = 0;
        void setVisited(){ visited = true; }
        bool isVisited(){return visited;}
};