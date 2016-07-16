#include <iostream>
#include <string>
#include "item.h"
using namespace std;

Potion::Potion(int row, int col, string type, char symbol, int index, int value):
  Item{row, col, type, symbol, index}, value{value} {}

Potion::~Potion() {};

int Potion::getvalue() {return value;}
