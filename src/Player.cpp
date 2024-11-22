#include "../lib/Player.h"
#include <iostream>
#include <cctype>

Player::Player(){
    
}

Player::Player(string race){
    
}

Player::Player(Stats& bStats){
    baseStats = bStats;
}

bool Player::checkForWall(char dir){
    if(positionX == 0 && dir == 'a'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }else if(positionX == 7 && dir == 'd'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }else if(positionY == 0 && dir == 'w'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }
    else if(positionY == 7 && dir == 's'){
        cout << "Whoops! There appears to be a wall here! Try again! w for up, a for left, s for down and d for right!" << endl;
        return true;
    }else{
        return false;
    }
}

bool Player::checkValidDir(char dir){
    if(!isalpha(dir) && dir != 'w' && dir != 'a' && dir != 's' && dir != 'd'){
        cout << "Invalid direction! Try again! w for up, a for left, s for down and d for right!" << endl << endl;
        return false;
    }else{
        return true;
    }
}

void Player::move(Map& map){
    char dir;
    cout << "Please enter in a direction! w for up, a for left, s for down and d for right: ";
    cin >> dir;
    if(isalpha(dir)) dir = tolower(dir);
    while(!checkValidDir(dir) || checkForWall(dir)){
        cin >> dir;
        if(isalpha(dir)) dir = tolower(dir);
    }
        if(dir == 'a') positionX--;
        if(dir == 'd') positionX++;
        if(dir == 'w') positionY--;
        if(dir == 's') positionY++;
        map.mapOfTiles[positionY][positionX].setVisited();
    
}


