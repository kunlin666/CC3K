
#ifndef player_h
#define player_h

#include <iostream>
#include <memory>
#include "enemy.h"
#include "item/potion.h"
#include "item/gold.h"

class Enemy;

class Player: public Character{
    static int goldamt;
    int chamberId; //see which chamber is the player in(for initializing stairs)
    std::string action; // store in this field for each player's action
  public:
    Player(int HP,int Atk,int Def,std::string race,int row,int col,int chamberId);
    virtual ~Player() = 0;
    
    int getamt();
    int getChamberId();
    std::string getAction();
    
    void setChamberId(const int i);
    void setAction(const std::string a);
    
    void addGold(int amount);
    void addAtk(int amount);
    void addDef(int amount);
    
    void attack(std::unique_ptr<Enemy> e);
    void changepos(std::string direction);
    void moveChar(std::string direction) override; //?? 
    
    void notifyEnemy(); //??
    void usePotion(std::unique_ptr<Potion> p);
    void useGold();
    void renew(); //??
    void notify(); //??
};

#endif 
