#ifndef _POTION_H_
#define _POTION_H_
#include "Item.h"

class Potion: public Item {
   int value;
  public:
   Potion(int row, int col, string type, char symbol, int index, int value);
   ~Potion();
   int getvalue();
}

#endif
