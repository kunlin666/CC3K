
#ifndef phoenix_h
#define phoenix_h

#include "enemy.h"

class Phoenix: public Enemy{
    Phoenix(int HP,int Atk,int Def,char sym,int row,int col);
    ~Phoenix();
};

#endif 
