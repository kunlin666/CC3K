
#ifndef merchant_h
#define merchant_h

#include "enemy.h"

class Merchant: public Enemy{
    Merchant(int HP,int Atk,int Def,char sym,int row,int col);
    ~Merchant();
};


#endif 
