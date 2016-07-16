
#ifndef werewolf_h
#define werewolf_h

#include "player.h"

class Werewolf: public Enemy{
    Werewolf(int HP,int Atk,int Def,char sym,int row,int col);
    ~Werewolf();
};


#endif /* werewolf_h */
