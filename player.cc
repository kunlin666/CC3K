
#include "player.h"
#include "postion.h"
#include "gold.h"
using namespace std;


// Player
class Character;
class Enemy;

int Player::goldamt = 0;

Player::Player(int HP,int Atk,int Def,std::string race,int row,int col,int chamberId):Character{HP,Atk,Def,'@',race,row,col},goldamt{0}, chamberId{chamberId}{
    action="Player character has spawned.";
}

Player::~Player(){};

int Player::getamt(){
    return goldamt;
}


int Player::getChamberId(){
    return ChamberId;
}

string Player::get action(){
    return action;
}

void Player::setChamberId(const int i){
    ChamberId = i;
}

void PLayer::setaction(const string a){
    action = a;
}

void Player::addgold(int amount){
    goldamt += amount;
}

void Player::addAtk(int amount){
    Atk += amount;
}

void Player::addDef(int amount){
    Def += amount;
}

void Player::attack(Character *e){ // Character *e is an Enemy ptr
    int Damage = ceiling((100/(100+e->getDef()))⇤Atk);
    istringstream ss{Damage};
    int newHP = HP-Damage;
    if(newHP>0){
        e->setHP(newHP);
        action = "PC deals " + ss.str() +" damage to" + e->race;
    }
    else{
        e->setHP(0);
        action = "Enemy " + e->race + " is slain."
        // add gold!!if(Enemy->==)
    }
}

void Player::changepos(string direction){
    if(direction == "no"){
        row--;
        action = "PC moves to the North."
    }
    else if(direction == "so"){
        row++;
        action = "PC moves to the South."
    }
    else if(direction == "ea"){
        col++;
        action = "PC moves to the East."
    }
    else if(direction == "we"){
        col--;
        action = "PC moves to the West."
    }
    else if(direction == "ne"){
        row--;
        col++;
        action = "PC moves to the NorthEast."
    }
    else if(direction == "se"){
        row++;
        col++;
        action = "PC moves to the SouthEast."
    }
    else if(direction == "sw"){
        row++;
        col--;
        action = "PC moves to the SouthWest."
    }
    else if(direction == "nw"){
        row--;
        col--;
        action = "PC moves to the NorthWest."
    }
}

void Player::moveChar(string direction){
    
}

void Player::usePotion(Potion* p){
    int quantity=p->getvalue();
    if(race=="elves"){
        if(quantity<0){
            quantity*=-1; // negative becomes positive
        }
    }
    
    if(p->getType()=="RH"){
        if(HP+quantity<maxHP){ // we check the max HP
            addHP(quantity);
            action = "PC uses RH."
        }
        else {
            action = "Ops! You exceed your max HP. Can't use RH."
        }
    }
    else if(p->getType()=="BA"){
        addAtk(quantity);
        action = "PC uses BA."
    }
    else if(p->getType()=="BD"){
        addDef(quantity);
        action = "PC uses BD."
    }
    else if(p->getType()=="PH"){
        if(HP+quantity>=0){
            addHP(quantity);
            action = "PC uses PH."
        }
        else{ // then we can't use "PH"
            action="Ops! You are below 0. Can't use PH."
        }
    }
    else if(p->getType()=="WA"){
        if(Atk+quantity>=0){  //we check the min Atk
            addAtk(quantity);
            action = "PC uses WA."
        }
        else{ // then we can't use "WA"
            action="Ops! You are below 0. Can't use WA."
        }
    }
    else if(p->getType()=="WD"){
        if(Def+quantity>=0){ // we check the min Def
            addDef(quantity);
            action = "PC uses WD."
        }
        else{ // then we can't use "WD"
            action="Ops! You are below 0. Can't use WD."
        }
    }
}

void Player::useGold(Gold *g){ // no merchant hoard
    if(g->pickable()){
        if(race== "dwarf"){
            int newQuantity=g->get
            g->setQuantity(g->getQuantity()*2);
        }
        else if(race == "orc"){
            g->setQuantity(g->getQuantity()/2);
        }
    }
    goldamt+=g->getQuantity;
    if(g->getType()=="normal"){
        action = "PC gets a normal gold(1)."
    }
    else if(g->getType()=="small"){
        action = "PC gets a small gold(2)."
    }
    else if(g->getType()=="dragon hoard"){
        action = "PC gets a dragon hoard(6)."
    }
    
}

void Player::renew(){
    
}
void Player::notifyEnemy(){
    
}
void Player::notify(){
    
}


