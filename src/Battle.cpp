#include "../lib/Battle.h"

int Battle::finalBoss(Player& plr, FinalBoss& fnlBss){

    bool nextPhase = false;

    while(fnlBss.getStats().getHP() > 70 && plr.getStats().getHP() != 0){ //phase 1
        if(moveCountEnemy(plr, fnlBss.getStats()) > moveCountPlayer(plr, fnlBss.getStats())){ //boss has priority
            for(int i = 0; i < moveCountEnemy(plr, fnlBss.getStats()); i++){ //moves per turn for the boss
                fnlBss.Slam(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, fnlBss.getStats()); //player turn
            endTurn(plr);
        }
        else{ //player has priority
            for(int i = 0; i < moveCountPlayer(plr, fnlBss.getStats()); i++){ //multiple moves per turn for the player depending on speed ratio
                takeTurn(plr, fnlBss.getStats()); 
                if(fnlBss.getStats().getHP() <= 70){
                    nextPhase = true; //move on to the next phase if it pushes over the break point, skips boss turn, will break out
                    break;
                }
            }
            if(nextPhase){  //if the boss got pushed past the break point, it'll move to the next phase
                nextPhase = false; //reset
                endTurn(plr); 
                break; //breaks out of phase 1, moves out of loop
            }
            fnlBss.Slam(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){ 
                return -1;
            }
            endTurn(plr);
        }
    }

    //call dialogue

    vector<int> bossRotation = {1,2,3}; //just to rotate through the moves
    int rotationPosition = 0;

    while(fnlBss.getStats().getHP() > 40){ //phase 2
        
        if(moveCountEnemy(plr, fnlBss.getStats()) > moveCountPlayer(plr, fnlBss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, fnlBss.getStats()); i++){ //moves per turn for the boss
                if(bossRotation.at(rotationPosition) = 1){
                    fnlBss.Charge(); 
                    rotationPosition++;
                    fnlBss.buffCounter--;
                }
                else if(bossRotation.at(rotationPosition) = 2){
                    fnlBss.Explosion(plr);
                    rotationPosition++;
                    fnlBss.buffCounter--;
                    fnlBss.getStats().addHP(fnlBss.getStats().getMAtk()*-0.5); //reset the buffs
                }
                else{
                    cout << "Boss is recharging." << endl;
                    rotationPosition = 0;
                }
            }
            //enemy has ended turn
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            takeTurn(plr, fnlBss.getStats());

        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, fnlBss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, fnlBss.getStats()); 
                if(fnlBss.getStats().getHP() <= 40){
                    nextPhase = true; //move on to the next phase if it pushes over the break point, skips boss turn, will break out
                    break;
                }
            }
            if(nextPhase){
                nextPhase = false;
                endTurn(plr); 
                break; //breaks out of phase 2, moves out of loop
            }
            if(bossRotation.at(rotationPosition) = 1){
                fnlBss.Charge(); 
                rotationPosition++;
                fnlBss.buffCounter--;
            }
            else if(bossRotation.at(rotationPosition) = 2){
                fnlBss.Explosion(plr);
                rotationPosition++;
                fnlBss.buffCounter--;
                fnlBss.getStats().addHP(fnlBss.getStats().getMAtk()*-0.5); //reset the buffs
            }
            else{
                cout << "Boss is recharging." << endl;
                rotationPosition = 0;
            }
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    } //end phase 2
    rotationPosition = 0; //reset the rotation for the repeat
    if(fnlBss.buffCounter != 0){ //in case the boss moved on to the next phase after using charge the previous turn
        fnlBss.getStats().addHP(fnlBss.getStats().getMAtk()*-0.5);
        fnlBss.buffCounter == 0;
    }

    fnlBss.BackToFull();
    //call dialogue

    while(fnlBss.getStats().getHP() > 70 && plr.getStats().getHP() != 0){ //phase 1 (revive)
        if(moveCountEnemy(plr, fnlBss.getStats()) > moveCountPlayer(plr, fnlBss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, fnlBss.getStats()); i++){ //moves per turn for the boss
                fnlBss.Slam(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, fnlBss.getStats()); //player turn
            endTurn(plr);
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, fnlBss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, fnlBss.getStats()); 
                if(fnlBss.getStats().getHP() <= 70){
                    nextPhase = true; //move on to the next phase if it pushes over the break point, skips boss turn, will break out
                    break;
                }
            }
            if(nextPhase){
                nextPhase = false;
                endTurn(plr); 
                break; //breaks out of phase 1, moves out of loop
            }
            fnlBss.Slam(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    }

    //call dialogue

    while(fnlBss.getStats().getHP() > 40){ //phase 2 revive
        
        if(moveCountEnemy(plr, fnlBss.getStats()) > moveCountPlayer(plr, fnlBss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, fnlBss.getStats()); i++){ //moves per turn for the boss
                if(bossRotation.at(rotationPosition) = 1){
                    fnlBss.Charge(); 
                    rotationPosition++;
                    fnlBss.buffCounter--;
                }
                else if(bossRotation.at(rotationPosition) = 2){
                    fnlBss.Explosion(plr);
                    rotationPosition++;
                    fnlBss.buffCounter--;
                    fnlBss.getStats().addHP(fnlBss.getStats().getMAtk()*-0.5); //reset the buffs
                }
                else{
                    cout << "Boss is recharging." << endl;
                    rotationPosition = 0;
                }
            }
            //enemy has ended turn
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            takeTurn(plr, fnlBss.getStats());

        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, fnlBss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, fnlBss.getStats()); 
                if(fnlBss.getStats().getHP() <= 40){
                    nextPhase = true; //move on to the next phase if it pushes over the break point, skips boss turn, will break out
                    break;
                }
            }
            if(nextPhase){
                nextPhase = false;
                endTurn(plr); 
                break; //breaks out of phase 2, moves out of loop
            }
            if(bossRotation.at(rotationPosition) = 1){
                fnlBss.Charge(); 
                rotationPosition++;
                fnlBss.buffCounter--;
            }
            else if(bossRotation.at(rotationPosition) = 2){
                fnlBss.Explosion(plr);
                rotationPosition++;
                fnlBss.buffCounter--;
                fnlBss.getStats().addHP(fnlBss.getStats().getMAtk()*-0.5); //reset the buffs
            }
            else{
                cout << "Boss is recharging." << endl;
                rotationPosition = 0;
            }
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    } 
    rotationPosition = 0;
    
    while(fnlBss.getStats().getHP() > 15){ //next phase (3), has similar rotation patterns to phase 2
        if(moveCountEnemy(plr, fnlBss.getStats()) > moveCountPlayer(plr, fnlBss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, fnlBss.getStats()); i++){ //moves per turn for the boss
                if(bossRotation.at(rotationPosition) = 1){
                    fnlBss.Cleave(plr); 
                    rotationPosition++;
                }
                else if(bossRotation.at(rotationPosition) = 2){
                    fnlBss.Brace();
                    rotationPosition++;
                }
                else{
                    fnlBss.SpeedUp();
                    rotationPosition = 0;
                }
            }
            //enemy has ended turn
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            takeTurn(plr, fnlBss.getStats());

        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, fnlBss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, fnlBss.getStats()); 
                if(fnlBss.getStats().getHP() <= 40){
                    nextPhase = true; //move on to the next phase if it pushes over the break point, skips boss turn, will break out
                    break;
                }
            }
            if(nextPhase){
                nextPhase = false;
                endTurn(plr); 
                break; //breaks out of phase 2, moves out of loop
            }
            if(bossRotation.at(rotationPosition) = 1){
                fnlBss.Cleave(plr); 
                rotationPosition++;
            }
            else if(bossRotation.at(rotationPosition) = 2){
                fnlBss.Brace();
                rotationPosition++;
            }
            else{
                fnlBss.SpeedUp();
                rotationPosition = 0;
            }
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    }
    cout << "The boss has begun charging its final attack!" << endl;
    while(fnlBss.getStats().getHP() > 0){
        for(int i = 0; i < 2*moveCountPlayer(plr, fnlBss.getStats()); i++){
            takeTurn(plr, fnlBss.getStats());
            if(fnlBss.getStats().getHP() == 0){
                return 1;
            }
        }
        if(moveCountEnemy(plr, fnlBss.getStats()) > moveCountPlayer(plr, fnlBss.getStats())){
            fnlBss.TheEnd(plr);
            return -1;
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, fnlBss.getStats()); i++){
                takeTurn(plr, fnlBss.getStats());
                if(fnlBss.getStats().getHP() == 0){
                    return 1;
                }
            }
            fnlBss.TheEnd(plr);
            return -1;
        }
    }
    return 1; //if the boss somehow gets bursted past final phase
}

int Battle::basicBoss(Player& plr, BasicBoss& bBoss){
    while(plr.getStats().getHP() > 0 || bBoss.getStats().getHP() != 0){
        if(moveCountEnemy(plr, bBoss.getStats()) > moveCountPlayer(plr, bBoss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, bBoss.getStats()); i++){ //moves per turn for the boss
                bBoss.Bonk(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, bBoss.getStats()); //player turn
            endTurn(plr);
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, bBoss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, bBoss.getStats()); 
                if(bBoss.getStats().getHP() == 0){
                    return 1;
                }
            }
            bBoss.Bonk(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    }
    return 1; //player killed boss
}

int Battle::eliteEnemy1(Player& plr, EliteBoss1& eBoss){
    bool nextPhase = false;
    while(plr.getStats().getHP() > 0 && eBoss.getStats().getHP() > 20){ //phase 1
        if(moveCountEnemy(plr, eBoss.getStats()) > moveCountPlayer(plr, eBoss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, eBoss.getStats()); i++){ //moves per turn for the boss
                eBoss.Slash(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, eBoss.getStats()); //player turn
            endTurn(plr);
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, eBoss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, eBoss.getStats()); 
                if(eBoss.getStats().getHP() <= 20){
                    nextPhase = true;
                    break;
                }
            }
            if(nextPhase){
                break; //no need to reset nextPhase, it only has 2 phases anyways
            }
            eBoss.Slash(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    }
    eBoss.Enrage();
    while(eBoss.getStats().getHP() > 0){ //phase 2
        if(moveCountEnemy(plr, eBoss.getStats()) > moveCountPlayer(plr, eBoss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, eBoss.getStats()); i++){ //moves per turn for the boss
                eBoss.Thrash(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, eBoss.getStats()); //player turn
            if(eBoss.getStats().getHP() == 0){
                return 1; //player wins
            }
            endTurn(plr);
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, eBoss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, eBoss.getStats()); 
                if(eBoss.getStats().getHP() == 0){
                    return 1; //boss defeated
                }
            }
            eBoss.Thrash(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){
                return -1; //player died
            }
            endTurn(plr);
        }
    }
    return 1; //player killed boss
    
}

int Battle::eliteEnemy2(Player& plr, EliteBoss2& eBoss){
    bool nextPhase = false;
    while(eBoss.getStats().getHP() > 25){ //phase 1
        if(moveCountEnemy(plr, eBoss.getStats()) > moveCountPlayer(plr, eBoss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, eBoss.getStats()); i++){ //moves per turn for the boss
                eBoss.Burn(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, eBoss.getStats()); //player turn
            endTurn(plr);
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, eBoss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, eBoss.getStats()); 
                if(eBoss.getStats().getHP() <= 25){
                    nextPhase = true;
                    break;
                }
            }
            if(nextPhase){
                break; //no need to reset nextPhase, it only has 2 phases anyways
            }
            eBoss.Burn(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){
                return -1;
            }
            endTurn(plr);
        }
    }
    while(eBoss.getStats().getHP() > 0){ //phase 2
        if(moveCountEnemy(plr, eBoss.getStats()) > moveCountPlayer(plr, eBoss.getStats())){ //priority
            for(int i = 0; i < moveCountEnemy(plr, eBoss.getStats()); i++){ //moves per turn for the boss
                eBoss.Inferno(plr); 
            }
            if(plr.getStats().getHP() == 0){ //check if player died after getting hit
                return -1;
            }
            takeTurn(plr, eBoss.getStats()); //player turn
            if(eBoss.getStats().getHP() == 0){
                return 1; //player wins
            }
            endTurn(plr);
        }
        else{
            for(int i = 0; i < moveCountPlayer(plr, eBoss.getStats()); i++){ //multiple moves per turn for the player
                takeTurn(plr, eBoss.getStats()); 
                if(eBoss.getStats().getHP() == 0){
                    return 1; //boss defeated
                }
            }
            eBoss.Inferno(plr); //one move for the boss
            if(plr.getStats().getHP() == 0){
                return -1; //player died
            }
            endTurn(plr);
        }
    }
    return 1; //player killed boss
    
}

void Battle::takeTurn(Player& user, Stats& target){
    bool moved = false;
    while(!moved){
        cout << "Pick your move! a - Attack, m - Magic Attack, b - Buff Yourself, h - Heal, g - Guard" << endl;
        char usermove;
        cin >> usermove;
        if(usermove = 'a'){
            user.Attack(target);
        }
        else if(usermove = 'm'){
            user.MagicAttack(target);
        }
        else if(usermove = 'b'){
            cout << "Choose a stat to buff: atk - Attack, def - Defense, matk - Magic Attack, mdef - Magic Defense, spd - Speed, lck - Luck" << endl;
            string buffChoice; 
            cin >> buffChoice;
            user.BuffChosen(buffChoice);
        }
        else if(usermove = 'h'){
            user.HealPlayer();
        }
        else if(usermove = 'g'){
            user.Guard();
        }
        else{
            cout << "Invalid input, try again!" << endl;
        }
    }
}


void Battle::endTurn(Player& user){
    turnCount++;
    if(user.isGuarding){
        user.Guard(); //resets back to false
    }
    user.reduceBuffCounter(); //reduces buff counter, resets if it hits 0;
}

int Battle::moveCountEnemy(Player& player, Stats& enemy){
    int spdRatio = enemy.getSpd()/player.getStats().getSpd();
    if(spdRatio == 0){
        spdRatio += 1;
    }
    return spdRatio;
}

int Battle::moveCountPlayer(Player& player, Stats& enemy){
    int spdRatio = player.getStats().getSpd()/enemy.getSpd();
    if(spdRatio == 0){
        spdRatio += 1;
    }
    return spdRatio;
}