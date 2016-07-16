#ifndef _GOLD_H_
#define _GOLD_H_
#include "Item.h"

class Gold: public Item {
   int quantity;
   bool pickable;
  public:
   Gold(int quantity);
   ~Gold() override;
   int getQuantity();
   bool isPickable();
   void setPickable(bool pick);
}

#endif
