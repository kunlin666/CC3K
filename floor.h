#ifndef floor_h
#define floor_h

#include <iostream>
#include <vector>
#include <memory> //!

class Player;
class Enemy;
class Chamber; //!
class Potion; //!
class Gold; //!

#endif 

class Floor {
    int curFloor;
    bool Won;
    std::unique_ptr<Player> thePlayer; //!
    std::vector<std::vector<char>> theDisplay; //!
    std::vector <std::unique_ptr<Enemy>> theEnemy; //!
    std::vector <std::unique_ptr<Chamber>> theChamber; //!
    std::vector <std::unique_ptr<Potion>> thePotion; //!
    std::vector<std::unique_ptr<Gold>> theGold; //!
    int numRow;
    int numCol;
    
    public:
    Floor(int curFloor); //!
    ~Floor();
    bool isWon();
    void setWon();
    
    int getCurFloor();
    int getnumRow(); //!
    int getnumCol(); //!
    
    void setFloor(std::string filename); //!
    
    void clearFloor();
    int whichChamber();
    
    void generateChamber();
    void generatePlayer();
    void generateEnemy();
    void generateGold();
    void generatePotion();
    void showStair();
    
    bool isMerchantHostile();
    void makeMerchantHostile();
    void movePlayer();
    void tileAvailble();
    void setCharAt(const int row, const int col, const char symbol);
    char getCharAt(const int row, const int col);
};
