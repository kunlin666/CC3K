
#include "enemy.h"
/*int getamount();

void attack(Player *p);
bool gethostile();
void notifyPlayer();
void notify();*/

// Enemy class:
int Enemy::getamount(){
    return goldamt;
}

void Enemy::attack(Player *p){
    
}

bool Enemy::gethostile(){
    return ishostile;
}

void Enemy::notifyPlayer(){
    
}

void Enemy::notify(){
    
}

const int normal_gold_value =1;
const int merchant_gold_value = 4;
const int dragon_gold_value = 0;
 
/* class Brad: public Enemy{
 Brad(int HP,int Atk,int Def,char sym,int row,int col,int goldamt,bool ishostile);
 ~Brad();
 };
 
 class Dave: public Enemy{
 Dave(int HP,int Atk,int Def,char sym,int row,int col,int goldamt,bool ishostile);
 ~Dave();
 };
*/

//Vampire class:
Vampire(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{normal_gold_value},ishostile{true}{}

//Werewolf class:
Werewolf(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{normal_gold_value},ishostile{true}{}

//Troll class:
Troll(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{normal_gold_value},ishostile{true}{}

//Goblin class:
Goblin(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{normal_gold_value},ishostile{true}{}

// Phoneix class:
Phoneix(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{normal_gold_value},ishostile{true}{}

// Merchant class:
Merchant(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{merchant_gold_value},ishostile{false}{}

// Drahon class:
Dragon(int HP,int Atk,int Def,char sym,int row,int col):Character{HP,Atk,Def,sym,row,col},goldamt{dragon_gold_value},ishostile{false}{}




























