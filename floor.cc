#include "floor.h"
#include "player.h"
#include "enemy.h"
#include "chamber.h"

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <utility>
#include <cstdlib>

using namespace std;


Floor::Floor(int curFloor):curFloor{curFloor},Won{false},thePlayer{nullptr},numRow{25},numCol{79}, dragonGold{0} {}
//used std::move for Player here because unique_ptr cannnot be copyed

Floor::~Floor(){
    clearFloor();
}

bool Floor::isWon(){
    return Won;
}

void Floor::setWon() {
    Won = true;
}

int Floor::getCurFloor() {
    return curFloor;
}

int Floor::getnumRow() {
    return numRow;
}

int Floor::getnumCol() {
    return numCol;
}



void Floor::setFloor(string filename = "map.txt"){
    ifstream file {filename};
    string s;
    while (getline(file, s)) {
        vector <char> row;
        int len = (int)s.length();
        for (int i = 0; i < len; ++i) {
            row.emplace_back(s[i]);
        }
        theDisplay.emplace_back(row);
    }
    generateChamber();
    generatePlayer(); // all the generate function should also replace the corresponding char in vec
    showStair();
    generatePotion();
    generateGold();
    generateEnemy();
}

void Floor::clearFloor() {
    for (int k = 0; k < numRow; ++k) {
        theDisplay[k].clear();
    }
    theDisplay.clear();
    theEnemy.clear();
    theChamber.clear();
    thePotion.clear();
    theGold.clear();
}

/* int Floor::whichChamber(int prob) {
    int n = rand % prob;
    return n; 
} */  //not really need this but I will keep it just in case


void Floor::showStair() {
    int id = rand() % 5 + 1;
    while(id == thePlayer->getChamberId()) { 
        id = rand() % 5 + 1;
    }
    theChamber[id]->generatePos('\\');
}
                                
                                
void Floor::generateChamber() {
    for (int i = 1; i <= 5; ++i) {
        unique_ptr <Floor> currFloor {this}; //unique_ptr used here...NOT SURE
        unique_ptr<Chamber> newChamber {new Chamber{i,currFloor}};
        theChamber.emplace_back(newChamber);
    }
}

void Floor::generatePlayer() {
//    char sym = thePlayer->getSym();
    int id = rand() % 5 + 1;
    thePlayer->setChamberId(id);
    theChamber[id]->generatePos('@');
}

void Floor::generateEnemy() {
    int dragonamt = 0;
    for (int i = 0; i < 10; ++i) {
        if (theGold[i]->getQuantity() == 8) {
            ++dragonamt;
        }
    }
  int restamt = 20 - dragonamt;
    
  for (int i = 0; i < restamt; ++i) {
    unique_ptr<Enemy> newEnemy;
    int id = rand() % 5 + 1;
    int type = rand() % 18; // 0-3 reps Werewolf, 4-6 reps Vampire, 7-11 reps Goblin, 12-13 reps Troll, 14-15 reps Phoenix, 16-17 reps Merchant
    if (type == 0 || type == 1 || type == 2 || type == 3) {
      theChamber[id]->generatePos('W');
      unique_ptr<Enemy> newEnemy {}; // depends on enemy ctor
   } else if (type == 4 || type == 5 || type == 6) {
      theChamber[id]->generatePos('V');
      unique_ptr<Enemy> newEnemy {}; // depends on enemy ctor
    } else if (type == 7 || type == 8 || type == 9 || type == 10 || type == 11) {
      theChamber[id]->generatePos('N');
      unique_ptr<Enemy> newEnemy {}; // depends on enemy ctor
    } else if (type == 12 || type == 13) {
      theChamber[id]->generatePos('T');
      unique_ptr<Enemy> newEnemy {}; // depends on enemy ctor
    } else if (type == 14 || type == 15) {
      theChamber[id]->generatePos('X');
      unique_ptr<Enemy> newEnemy {}; // depends on enemy ctor
    } else {
      theChamber[id]->generatePos('M');
      unique_ptr<Enemy> newEnemy {}; // depends on enemy ctor
    }
    theEnemy.emplace_back(newEnemy);
  }
  // must add row and col in item class
  for (int j = 0; j < 20; ++j) {
    if (theGold[j]->type == "Dragon") {
      
    }
  }
}


void Floor::generateGold() {
    unique_ptr<Gold> newGold;
  for (int i = 0; i < 10; ++i) {
    int id = rand() % 5 + 1;
    theChamber[id]->generatePos('G');
    int type = rand % 8; // 0-4 reps normal, 5-6 reps small, 7 reps dragon gold
    if (type == 0 || type == 1 || type == 2 || type == 3 || type == 4) {
      unique_ptr<Gold> newGold {"Normal", 'G', i, 1, true};
    } else if (type == 5 || type == 6) {
      unique_ptr<Gold> newGold {"Small", 'G', i, 2, true};
    } else {
      unique_ptr<Gold> newGold {"Dragon", 'G', i, 6, false};
    }
    theGold.emplace_back(newGold);
  }
}


void Floor::generatePotion() {
  for (int i = 0; i < 10; ++i) {
    int id = rand() % 5 + 1;
    theChamber[id]->generatePos('P'); 
    int type = rand() % 6; // 0 reps RH, 1 reps BA, 2 reps BD, 3 reps PH, 4 reps WA, 5 reps WD
    if (type == 0) {
      unique_ptr<Potion> newPotion {"RH", 'P', i, 10};
    } else if (type == 1) {
      unique_ptr<Potion> newPotion {"BA", 'P', i, 5};
    } else if (type == 2) {
      unique_ptr<Potion> newPotion {"BD", 'P', i, 5};
    } else if (type == 3) {
      unique_ptr<Potion> newPotion {"PH", 'P', i, -10};
    } else if (type == 4) {
      unique_ptr<Potion> newPotion {"WA", 'P', i, -5};
    } else {
      unique_ptr<Potion> newPotion {"WD", 'P', i, -5};
    }
    thePotion.emplace_back(newPotion);
  }

}

ostream &operator<<(ostream &out, Floor &f){
    int rowsize = f.getnumRow();
    int colsize = f.getnumCol();
    for (int i = 0; i < rowsize; ++i) {
        for (int j = 0; j < colsize; ++j) {
            out << f.getCharAt(i,j); //print out the display here...need to implement method to get the display?
        }
        out << "\n";
    }
    return out;
}

void Floor::makeMerchantHostile(int numOfEnemy){
    theEnemy[numOfEnemy]->sethostile(); // add sethostile in Enemy class
}

bool Floor::isItem(const char c, const int row, const int col) {
  if (theDisplay[row][col] == c) return true;
  return false;
}

int Floor::findGold(const int row, const int col) {
  for (int i = 0; i < 10; ++i) {
    if (theGold[i]->getRow == row && theGod[i]->getCol == col) return i;
    return -1; // it should never return -1
  }
}

int Floor::findPotion(const int row, const int col) {
  for (int i = 0; i < 10; ++i) {
    if (thePotion[i]->getRow == row && thePotion[i]->getCol == col) return i;
    return -1; // it should never return -1
  }
}

void Floor::consumeGold(const int row, const int col) {
  if (isItem('G', row, col)) {
    int ind = findGold(row, col);
    thePlayer->useGold(theGold[i]);
    theGold[i]->setRow(-1);
    theGold[i]->setCol(-1);
  }
}

void Floor::consumePotion(const int row, const int col) {
  if (isItem('P', row, col)) {
    int ind = findPotion(row, col);
    thePlayer->usePotion(thePotion[i]);
    thePotion[i]->setRow(-1);
    thePotion[i]->setCol(-1);
  }
}

void Floor::movePlayer(string direction){
  int prow = thePlayer->getRow(); //current row of player
  int pcol = thePlayer->getCol(); //current col of player
  if (direction == "no") {
    --prow;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';                           
    theDisplay[prow + 1][pcol] = '.';
  } else if (direction == "so") {
    ++prow;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';          
    theDisplay[prow - 1][pcol] = '.';
  } else if (direction == "ea") {
    ++pcol;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';          
    theDisplay[prow][pcol - 1] = '.';
  } else if (direction == "we") {
    --pcol;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';
    theDisplay[prow][pcol + 1] = '.';
  } else if (direction == "ne") {
    --prow;
    ++pcol;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';          
    theDisplay[prow + 1][pcol - 1] = '.';
  } else if (direction == "se") {
    ++prow;
    ++pcol;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';                
    theDisplay[prow - 1][pcol - 1] = '.';
  } else if (direction == "sw") {
    ++prow;
    --pcol;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';                
    theDisplay[prow - 1][pcol + 1] = '.';
  } else {
    --prow;
    --pcol;
    consumeGold(prow, pcol);
    consumePotion(prow, pcol);
    theDisplay[prow][pcol] = '@';                
    theDisplay[prow + 1][pcol + 1] = '.';
  }
}

bool Floor::isValid(string direction){
  int prow = thePlayer->getRow();
  int pcol = thePlayer->getCol();
  if (direction == "no") {
    --prow;
  } else if (direction == "so") {
    ++prow;
  } else if (direction == "ea") {
    ++pcol;
  } else if (direction == "we") {
    --pcol;
  } else if (direction == "ne") {
    --prow;
    ++pcol;
  } else if (direction == "se") {
    ++prow;
    ++pcol;
  } else if (direction == "sw") {
    ++prow;
    --pcol;
  } else{
    --prow;
    --pcol;
  }
  char curr = theDisplay[prow][pcol];
  if (curr == '.' || curr == '+' || curr == '#' || curr == 'P' || curr == 'G') return true;
  return false;
}

bool checkPoint(string direction, char c) {
  int prow = thePlayer->getRow();
  int pcol = thePlauer->getCol();
  if (direction == "no") {
    --prow;
  } else if (direction == "so") {
    ++prow;
  } else if (direction == "ea") {
    ++pcol;
  } else if (direction == "we") {
    --pcol;
  } else if (direction == "ne") {
    --prow;
    ++pcol;
  } else if (direction == "se") {
    ++prow;
    ++pcol;
  } else if (direction == "sw") {
    ++prow;
    --pcol;
  } else{
    --prow;
    --pcol;
  }
  if (c == theDisplay[prow][pcol]) return true;
  return false;
}

void Floor::setCharAt(const int row, const int col, const char symbol){
    theDisplay[row-1][col-1]=symbol;
}

char Floor::getCharAt(const int row, const int col){
    return theDisplay[row-1][col-1];
}x