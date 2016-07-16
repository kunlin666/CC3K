
#ifndef human_h
#define human_h

#include "player.h"

class Human: public Player{
    Human(int HP,int Atk,int Def,char sym,int row,int col);
    ~Human();
};

#endif 
