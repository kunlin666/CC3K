#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "floor.h"
#include "chamber.h"
#include "item.h"
#include "item/potion.h"
#include "item/gold.h"
#include "character.h"
#include "enemy.h"
#include "enemy/dragon.h"
#include "enemy/merchant.h"
#include "enemy/phoenix.h"
#include "enemy/goblin.h"
#include "enemy/troll.h"
#include "enemy/vampire.h"
#include "enemy/werewolf.h"
#include "enemy/midterm.h"  ///
#include "enemy/zombie.h"   ///
#include "player.h"
#include "player/human.h"
#include "player/dwarf.h"
#include "player/elves.h"
#include "player/orc.h"

using namespace std;

void printInfo(unique_ptr<Floor> fp) {
  istringstream ss;
  ss << "Race: " << fp->getRace() << " Gold: " << fp->getamt();
  for (int i = 0; i < 50; ++i) {
    ss << " ";
  }
  ss << "Floor " << fp->getCurFloor();
  string line1 = ss.str();
  cout << line1 << endl;
  cout << "HP: " << fp->thePlayer->getHP() << endl;
  cout << "Atk: " << fp->thePlayer->getAtk() << endl;
  cout << "Def: " << fp->thePlayer->getDef() << endl;
  cout << "Action: " << fp->thePlayer->getAction() << endl; // add action field, setaction method, add action method,  getction method to class player
} 

int main() {

  cout << "Welcome to ChamberCrawler3000! " << endl;

  while (true) {
    string command;

    // generate PC
    cout << "Please choose your player character." << endl;
    cout << "h stands for human. 140HP, 20Atk, 20Def." << endl;
    cout << "d stands for dwarf. 100HP, 20Atk, 30Def. Gold is doubled in value." << endl;
    cout << "e stands for elves. 140HP, 30Atk, 10Def. Negative potions have positive effect." << endl;
    cout << "o stands for orc. 180HP, 30Atk, 25Def. Gold is worth half value." << endl;
      
    cin >> command;
    if (command == "h") {
      auto player = make_shared<Human> (); // add ctor args in () later
    } else if (command == "d") {
      auto player = make_shared<Dwarf> (); // add ctor args in () later
    } else if (command == "e") {
      auto player = make_shared<Elves> (); // add ctor args in () later
    } else if (command == "o") {
      auto player = make_shared<Orc> (); // add ctor args in () later
    } else {
      cout << "Please choose a valid player." << endl;
    }

    // generate floor
    auto floor = make_unique<Floor> (); // add ctor args in () later, player should initially be nullptr
    floor->thePlayer = player;
    floor->setFloor(); // in setFloor, put all elements in the vector of vector (means position is generated)

    while (true) {
      if (floor->getChar(player->row,player->col) == '\\') {
	if (floor->getcurFloor == 5) {
	  floor->setWon(); // add this funciton to floor class!!!!!!
	  cout << "Congratulations! You win the game!" << endl;
	  cout << "Your have earned: " << player->goldamt() <<" gold!"<< endl;
	  break;
	} else {
	  floor->clearFloor();
	  floor->setFloor;
	  floor->incFloor(); // add this function to floor class!!!!!!, ++curFloor
	}
      }

      cout << "Please enter a valid command:" << endl;
      cout << "Change directions: no, so, ea, we, ne, se, sw, nw" << endl;
      cout << "Use Potion: u <direction>" << endl;
      cout << "Attack enemy: a <direction>" << endl;
      cout << "Reset the game : r" << endl;
      cout << "Quit: q" << endl;

      if (cin >> command) {
        while (command == ("no" || "so" || "ea" || "we" || "ne" || "se" || "sw" || "nw")) { // read direction
	  if (floor->isValid()) {   // add this function to floor class!!!!!!!
	    player->moveChar(command); // in player class
	    floor->updateFloor(); // update field in floor
	    cout << floor; // pass by reference!!!!!
	    printInfo(floor);
	    break;
	  } else {
	    cout << "Please step to a valid tile. Enter the direction again." << endl;
	    cin >> command;
	  }
        } 
        while (command == "u") {  // use Potion
	  cin >> command;  // read direction
	  if (checkPoint(command, 'P')) { //checkPotion checks if there's a potion on the direction command
	    player->usePotion();  // usePotion is in Player class
	    floor->updateFloor();
	    cout << floor;
	    printInfo(floor);
	    break;
	  } else {
	    cout << "There's no potion in the direction you pointed." << endl;
	    cin >> command;
	  }
        } 
        while (command == "a") {  // attack enemy
	  cin >> command;  // read direction
	  if (checkPoint(command, 'V') || checkPoint(command, 'W') || checkPoint(command, 'N') ||
	      checkPoint(command, 'M') || checkPoint(command, 'D') || checkPoint(command, 'X') ||
	      checkPoint(command, 'T')) {  // checks if there's enemy on the direction command
	    player->attack();  // attack is in player class
	    cout << floor;
	    printInfo(floor);
	    break;
	  } else {
	    cout << "There's no enemy in the direction you pointed." << endl;
	    cin >> command;
	  }
        } 
        if (command == "r") {
	  floor->clearFloor(); // reset the game, means clearing and deleting the floor including unique ptrs, in floor class
	  break;
        } else if (command == "q") {
	  break;
        } else {
	  cout << "Please enter a valid command." << endl;
        }
      } else {
        cout << "Bad Input." << endl;
      }
    }
    if (command == "q") {
      break;
    }

    if (floor->isWon()) {
      cout << "Do you want to play the game again? y/n" << endl;
      string c;
      cin >> c;
      if (c == "n") {
	cout << "Thank you for playing CC3K. Have a good day!" << endl;
	break;
      } else if (c == "y") {
	continue;
      } else {
	cout << "Please enter a valid command." << endl;
      }
    }
  }
}
