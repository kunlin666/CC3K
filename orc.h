
#ifndef orc_h
#define orc_h

#include "player.h"

class Orc: public Player{
    Orc(int HP,int Atk,int Def,char sym,int row,int col);
    ~Orc();
};

#endif
