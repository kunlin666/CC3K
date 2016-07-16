
#ifndef goblin_h
#define goblin_h

#include "enemy.h"

class Goblin: public Enemy{
    Goblin(int HP,int Atk,int Def,char sym,int row,int col);
    ~Gonlin();
};

#endif 
