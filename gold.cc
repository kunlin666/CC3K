#include <iostream>
#include <string>
#include "item.h"
using namespace std;

Gold::Gold(int row, int col, string type, char symbol, int index, int quantity, bool pickable):
  Item{row, col, type, symbol, index}, quantity{quantity}, pickable{pickable} {}

Gold::~Gold() {}

int Gold::getQuantity() {return quantity;}

bool Gold::isPickable() {return pickable;}

void Gold::setQuantity(int num) {quantity = num;}

void Gold::setPickable(bool pick) {pickable = pick;}
