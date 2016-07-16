
#ifndef troll_h
#define troll_h

#include "player.h"

class Troll: public Enemy{
    Troll(int HP,int Atk,int Def,char sym,int row,int col);
    ~Troll();
};

#endif /* troll_h */
