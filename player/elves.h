
#ifndef elves_h
#define elves_h

#include "player.h"

class Elves: public Player{
    Elves(int HP,int Atk,int Def,char sym,int row,int col);
    ~Elves();
};

#endif 
