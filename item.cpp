#include <iostream>
#include <string.h>
#include "item.h"

using namespace std;


//constructor for item class
item::item() {
  itemName[0] = "Money";
  itemName[1] = "Laptop";
  itemName[2] = "Wrench";
  itemName[3] = "Magazine";
  itemName[4] = "Soap";

  itemInv[0] =0;
  itemInv[1] =0;
  itemInv[2] =0;
  itemInv[3] =0;
  itemInv[4] =0;
  
}

//deconstructor
item::~item(){

}

// initialize the item inventory: 0 for item not in, 1 for item exist
void item::initItems(int i1, int i2, int i3, int i4, int i5)
{
  itemInv[0] = i1;
  itemInv[1] = i2;
  itemInv[2] = i3;
  itemInv[3] = i4;
  itemInv[4] = i5;
}

// show the list of items in the room
string item::showItems() {
  string out = "";

  for(int i = 0; i<5; i++){
    if(itemInv[i] > 0){
      out = out + " " + itemName[i];
    }
  }
  
  return out; 
}

//add an item by the name
bool item::addItem(string newname) {

  for (int i=0; i<5; i++)
    {
      if (itemName[i] == newname) {
         itemInv[i] = 1;
         return true;
       }
    }

    return false; 
}

//remove an item by the name
bool item::deleteItem(string newname) {

  for (int i=0; i<5; i++)
    {
      if (itemName[i] == newname)
	{
	  itemInv[i]=0;
	  return true;
	}
    }

  return false; 
}

//count the items in inventory
int item::itemCount() {
  int count =0;
  for (int i=0; i<5; i++)
    {
      if (itemInv[i] >= 1) count++;
    }

  return count; 
}


