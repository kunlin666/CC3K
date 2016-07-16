
#ifndef dragon_h
#define dragon_h

#include "enemy.h"
#include "gold.h"

class Dragon: public Enemy{
    Gold *dragon_hoard;
public:
    void getHoard();
    Dragon(int HP,int Atk,int Def,char sym,int row,int col);
    ~Dragon();
};

#endif /* dragon_h */
