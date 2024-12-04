#include "../lib/Battle.h"

int Battle::fBoss(Player& plr, FinalBoss& fnlBss){

    int turnCounter = 0;
    

    while(plr.getStats().getHP() != 0 || fnlBss.getStats().getHP() != 0 ){
        if(fnlBss.getStats().getHP() > 70){
             //determine speed order and thus priority
             fnlBss.Slam(plr); //boss move
        }
        else if(fnlBss.getStats().getHP() > 40){
            //spd priority
            fnlBss.Charge();
            fnlBss.Explosion(plr);
            //do nothing for a turn
        }
        else if(fnlBss.getStats().getHP() > 15 && !fnlBss.revivedOnce){
            fnlBss.BackToFull();
        }
        else if(fnlBss.getStats().getHP() > 15){
            //normal pattern
        }
        else{
            //do nothing
            //do nothing
            //end
        }
    }
}