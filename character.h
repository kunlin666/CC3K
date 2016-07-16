
#ifndef character_h
#define character_h
#include <string>
#include <iostream>

class Character{
private:
    int HP;
    int Atk;
    int Def;
    char sym;
    std::string race;
    int row;
    int col;
    int maxHP;
public:
    Character(int HP,int Atk,int Def,char sym,std::string race,int row,int col);
    virtual ~Character() = 0;
    int getHP();
    int getAtk();
    int getDef();
    int getSym();
    int getRow();
    int getCol();
    int getrace();
    
    void setHP(int amt);
    void addHP(int amt);    
    virtual void moveChar(std:: string direction) = 0; // move the char to the direction
};

#endif /* character_h */
