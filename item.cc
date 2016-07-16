#include <iostream>
#include <string>
#include "item.h"
using namespace std;

Item::Item(int row, int col, string type, char symbol, int index):
  row{row}, col{col}, type{type}, symbol{symbol}, index{index} {}

int Item::getRow() {return row;}

int Item::getCol() {return col;}

void setRow(int num) {
  row = num;
}

void setCol(int col) {
  col = num;
}

string Item::getType() {return type;}

char Item::getSymbol() {return symbol;}

int getIndex() {return index;}
