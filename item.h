#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string.h>

//class file for item
using namespace std;

class item{
 public:
  item();
  ~item();

  void initItems(int, int, int, int, int);
  string showItems();
  bool addItem(string newname);
  bool deleteItem(string newname); 
  int itemCount();
  
  int itemInv[5];
  string itemName[5];
  
};

#endif
