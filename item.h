#ifndef _ITEMS_H_
#define _ITEMS_H_

class Item {
   int row;
   int col;
   std::string type;
   char symbol;
   int index;
  public:
   Item(int row, int col, std::string type, char symbol, int index);
   virtual ~Item() = 0;
   int getRow();
   int getCol();
   void setRow(int num);
   void setCol(int num);
   std::string getType();
   char getSymbol();
   int getIndex();
}

#endif
