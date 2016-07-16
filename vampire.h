
#ifndef vampire_h
#define vampire_h

#include "player.h"

class Vampire: public Enemy{
    Vampire(int HP,int Atk,int Def,char sym,int row,int col);
    ~Vampire();
};

#endif 
