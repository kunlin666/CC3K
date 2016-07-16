
#ifndef dwarf_h
#define dwarf_h

#include "player.h"

class Dwarf: public Player{
    Dwarf(int HP,int Atk,int Def,char sym,int row,int col);
    ~Dwarf();
};

#endif 
