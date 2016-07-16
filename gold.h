#ifndef _GOLD_H_
#define _GOLD_H_
#include "Item.h"

class Gold: public Item {
   int quantity;
   bool pickable;
  public:
   Gold(int row, int col, string type, char symbol, int index, int quantity, bool pickable);
   ~Gold() override;
   int getQuantity();
   bool isPickable();
   void setQuantity(int num);
   void setPickable(bool pick);
}

#endif
