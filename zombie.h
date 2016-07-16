
#ifndef zombie_h
#define zombie_h

#include "enemy.h"

class lushman: public Enemy{
    lushman(int HP,int Atk,int Def,char sym,int row,int col);
    ~lushman();
};


#endif
