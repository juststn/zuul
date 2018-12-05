#include <iostream>
#include <string.h>
#include <map>
#include "item.h"

using namespace std;

//class file for room
class room{
 public:
  room(string newname, string newdesc);
  ~room();

  string getName();
  string getDescription();
  string getExits();
  
  void setName(string);
  void setDescription(string);
  string showItems();
  void pickupItem(string, item& playerbucket);
  void dropItem(string, item& playerbucket);
  void setItems(int,int,int,int,int);
  void setExits(room* n, room* e, room* s, room* w);  
  room* goExit(string newExit);

  item itemList; 
 private:
  string name;
  string description;

  // the exit map 
  map<string,room*> exitMap;
  
};
