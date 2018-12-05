#include <iostream>
#include <string.h>
#include "room.h"
#include "item.h"

using namespace std;

//create the constructor for room
room::room(string newname, string newdesc) {

  name = newname;
  description = newdesc;
}

room::~room(){

}

string room::getName() {
  return name;
}

string room::getDescription() {
  return description;
}

//return valid exits
string room::getExits() {
  string e = "";

  if (exitMap.find("NORTH") != exitMap.end())
    e = e + " NORTH";

  if (exitMap.find("SOUTH") != exitMap.end())
    e = e + " SOUTH";

  if (exitMap.find("EAST") != exitMap.end())
    e = e + " EAST";

  if (exitMap.find("WEST") != exitMap.end())
    e = e + " WEST";

  return e;
}

string room::showItems() {

  return itemList.showItems();
  
}

void room::setItems(int i1, int i2, int i3, int i4, int i5) {
  itemList.initItems(i1,i2,i3,i4,i5);
}

void room::setName(string newname){
  name = newname;
}

void room::setDescription(string newdescription){
  description = newdescription;
}

//set exits for a room
void room::setExits(room* n, room* e, room* s, room* w) {

  if (n != NULL)
     exitMap["NORTH"] = n;

  if (e != NULL)
     exitMap["EAST"] = e;

  if (s != NULL)
     exitMap["SOUTH"]= s;

  if (w != NULL) 
     exitMap["WEST"] = w;
}


room* room::goExit(string newExit) {

  // if inpuy exit does not exist, then stay in the same room
  if (exitMap.find(newExit) == exitMap.end()) {
    cout << "invalid exit" << endl;
    return this;
  }
  else {
    // go to the selected exit
    return exitMap.find(newExit)->second; 
  }
  
}

// pick up item from the room and put into the player's bucket
void room::pickupItem(string itemname, item &playerbucket)
{
  bool find = false; 
  for (int i=0; i<5; i++)
    {
      if (itemList.itemName[i] == itemname)
	{
	  find = true; 
	  itemList.deleteItem(itemList.itemName[i]);
	  playerbucket.addItem(itemList.itemName[i]);
	}  
    }

  if (find == false)
    {
      cout << "Invalid item name for pickup" << endl;
    }
}

// drop item to the room
void room::dropItem(string itemname, item &playerbucket)
{
  bool find = false; 
  for (int i=0; i<5; i++)
    {
      if (playerbucket.itemName[i] == itemname)
	{
	  find = true; 
	  itemList.addItem(playerbucket.itemName[i]);
	  playerbucket.deleteItem(playerbucket.itemName[i]);
	}  
    }

  if (find == false)
    {
      cout << "Invalid item name for drop. " << endl;
    }

}
