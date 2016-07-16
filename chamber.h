#ifndef chamber_h
#define chamber_h

#include <vector>

class Floor;

class Chamber{
    int id;
    int topRow;
    int topCol;
    int rowLen;
    int colLen;
    std::unique_ptr<Floor> floor;
    
public:
    
    Chamber(int id, std::unique_ptr<Floor> floor);
    ~Chamber();
    
    int getid();
    int gettopRow();
    int gettopCol();
    int getrowLen();
    int getcolLen();
    
    bool isValidTile(const int row,const int col);
    void generatePos(const char symbol);
    bool withinRange(const int row, const int col);

};

#endif
