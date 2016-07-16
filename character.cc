
#include "character.h"
using namespace std;
/*
 virtual ~Character() = 0;
 Character(int HP,int Atk,int Def,char sym,int row,int col);
 int getHP();
 int getAtk();
 int getDef();
 int getSym();
 int getRow();
 int getCol();
 int getSymbol();
 

 
 void moveChar();
 */
Character::Character(int HP,int Atk,int Def,char sym,std::string race,int row,int col):HP{HP},Atk{Atk},Def{Def},sym{sym},race{race},row{row},col{col}{}

Character::~Character(){}

int Character::getHP(){
    return HP;
}

int Character::getAtk(){
    return Atk;
}

int Character::getDef(){
    return Def;
}

char Character::getsym(){
    return Sym;
}

int Character::getCol(){
    return Col;
}

string Character::getrace(){
    return race;
}

void Character::setHP(int amt){
    HP=amt;
}

void Character::addHP(int amt){ 
    HP+=amt;
}









