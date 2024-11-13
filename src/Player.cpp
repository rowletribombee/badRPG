#include "../lib/Player.h"
#include <iostream>

Player::Player(string race){
    
}

void Player::move(string dir){
    if(positionX == 0 && dir == "left"){
        cout << "Whoops! There appears to be a wall here!";
    }else if(positionX == 7 && dir == "right"){
        cout << "Whoops! There appears to be a wall here!";
    }else if(positionY == 0 && dir == "up"){
        cout << "Whoops! There appears to be a wall here!";
    }
    else if(positionY == 7 && dir == "down"){
        cout << "Whoops! There appears to be a wall here!";
    }else{
        if(dir == "left") positionX--;
        if(dir == "right") positionX++;
        if(dir == "up") positionY--;
        if(dir == "down") positionY++;
    }
}
