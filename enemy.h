
#ifndef Enemy_h
#define Enemy_h

#include "character.h"
#include "player.h"
#include <iostream>

class Enemy: public Character{
    int goldamt;
    bool ishostile; 
public:
    int getamount();
    
    void attack(Player *p);
    bool gethostile();
    void notifyPlayer();
    void notify();
};

#endif /* Enemy_h */
