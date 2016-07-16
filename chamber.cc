#include "chamber.h"
#include "floor.h"
#include <vector>
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

Chamber::Chamber(int id, std::unique_ptr<Floor> floor): id{id}, floor{std::move(floor)} {
    //std::move is used for unique_ptr Floor here
    if (id == 1) { //top ledt
         topRow = 3;
         topCol = 3;
         rowLen = 26;
         colLen = 4;
    }
    if (id == 2) { //top right(special case)
        topRow = 3;
        topCol = 39;
        rowLen = 37;
        colLen = 10;
    }
    if (id == 3) { //middle
        topRow = 10;
        topCol = 38;
        rowLen = 12;
        colLen = 3;
    }
    if (id == 4) { //bottom left
        topRow = 15;
        topCol = 4;
        rowLen = 21;
        colLen = 7;
    }
    if (id == 5) { //bottom right(special case)
        topRow = 16;
        topCol = 37;
        rowLen = 39;
        colLen = 6;
    }
}

Chamber::~Chamber() {}

int Chamber::getid() {
    return id;
}

int Chamber::gettopRow() {
    return topRow;
}

int Chamber::gettopCol(){
    return topCol;
}

int Chamber::getrowLen() {
    return rowLen;
}

int Chamber::getcolLen(){
    return colLen;
}

bool Chamber::isValidTile(int row,int col) {
    char curr = floor->getCharAt(row,col);
    if (curr == '#' || curr == '.' || curr == '+') return true;
    else return false;
    
}
void Chamber::generatePos(const char symbol) {
    int currRow, currCol;
    while (true) {
    int currRow = rand() % rowLen;
    int currCol = rand() % colLen;
        if (isValidTile(currRow, currCol)) break;
    }
    floor->setCharAt(topRow+currRow, topCol+currCol, symbol);
}

bool Chamber::withinRange(const int row, const int col) {
    if (id != 2 && id != 5) {
        if ((row >= topRow && row <= topRow+rowLen) && (col >= topCol && row <= topCol+colLen)) return true;
        else return false;
    } else if (id == 2) {
        if (col <= topCol+1) {
            if (row < topRow+23) return true;
            else return false;
        } else if (col == topCol+2) {
            if (row < topRow+30) return true;
            else return false;
        } else if (col == topCol+3) {
            if (row < topRow+34) return true;
            else return false;
        }else{
            if (col <= topCol+10 && (row > topRow+23 && row < 37)) return true;
            else return false;
        }
    } else {
        if (col <= topCol+2) {
            if (row > topRow+28 && row < topRow+40) return true;
            else return false;
        } else  {
            if (col <= topCol+5 &&(row >= topRow && row < topRow+40)) return true;
            else return false;
        }
    }
}