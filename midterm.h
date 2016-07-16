
#ifndef midterm_h
#define midterm_h

#include "enemy.h"

class Brad: public Enemy{
    Brad(int HP,int Atk,int Def,char sym,int row,int col);
    ~Brad();
};


#endif
