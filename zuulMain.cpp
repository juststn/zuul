#include <iostream>
#include <string>
#include <vector>
#include "room.h"
#include "item.h"

//This program is a text adventure game that lets the player move through 15 total rooms, pickup items, and drop items (5 total items.
//The winning condition is gathering all 5 items in the rooms (all located across the aisleway) and bringing them into the pilots room
//The losing condition is taking over 100 moves which will cause the plane to crash.

using namespace std;

void setMap(vector<room*>* roomList, room* &currentRoom, item &playerBucket);

void setItem(vector<item*>* itemList);

int main(){
  vector<room*>* roomList = new vector<room*>;
  room* currentRoom;
  string input;
  string in;
  item playerBucket; 
  int  moveCount =0;
  
  cout << "Welcome to Zuul. You are onboard a plane with 15 rooms. The captain announces through the speaker: \"Attention everyone, I'm afraid the plane is crashing in 15 minutes,\". The winning condition is to find all 5 tools and take them to the Pilot Room within 100 moves to fix the plane before the it crashes. The losing condition is moving over 100 times, which will exit the game." << endl;
  //set the rooms using a map
  
  setMap(roomList, currentRoom, playerBucket);

  // loop game until the winning point is reached or over 100 moves
  while (moveCount<=100) {
    // display your room description
    cout<<endl;
    cout << currentRoom->getDescription()<<endl;
    cout << "There are exits: " << endl;
    cout << currentRoom->getExits() << endl;
    cout<<endl;

    //prompt item information and ask to pickup or drop an item every move
    input = "PICKUP";
    while (input == "PICKUP" || input == "DROP") {
      cout << "Items in the room: " << currentRoom->showItems() << endl;
      cout << "Items in inventory: " << playerBucket.showItems() << endl; 
      cout << endl;

      cout << "do you want to pickup or drop an item? (PICKUP, DROP, NO)"<< endl;
      cin >>input;

      if (input == "PICKUP") {
        cout << "enter the item name to pickup: ";
        cin >> in;
        currentRoom->pickupItem(in, playerBucket);
       }

      if (input == "DROP") {
        cout << "enter the item name to drop: ";
        cin >> in;
        currentRoom->dropItem(in, playerBucket);
       }
    }

    // checking winning point: collect all items within 100 moves
    if (playerBucket.itemCount() == 5 && currentRoom->getName() == "Pilot Room" && moveCount <=100) {
      cout << "Congratulations, you gathered all the tools to repair the plane and saved everyone!" << endl;
      exit(0);
    }

    cout << endl; 
    cout << "What do you want to do? (NORTH, EAST, SOUTH, WEST, QUIT) " << endl;
    cin >> input;

    if (input == "QUIT") {
      exit(1); 
    }

    // take the exit and go to the next room
    currentRoom = currentRoom->goExit(input);
    moveCount ++;  
  }
  cout<<"Sorry, you could not repair the plane in time and it crashed. You lost."<<endl;
  return 0;
}

// setup 15 rooms: name, description, 4 exits
void setMap(vector<room*>* roomList, room* &currentRoom, item &playerBucket) {
  room* r1 = new room("Storage", "You are in the back of the plane. You can continue north down the aisleway.");
  roomList->push_back(r1);
  
  room* r2 = new room("Aisleway1", "You are going down the aisleway, there is a lavatory to your left");
  roomList->push_back(r2);

  room* r3 = new room("Lavatory","You are in the bathroom. There is a sink and toilet.");
  roomList->push_back(r3);

  room* r4 = new room("Aisleway3", "You are going down the aisleway");
  roomList->push_back(r4);

  room* r5 = new room("Aisleway4", "You are walking down the aisleway. Your seat is next to you.");
  roomList->push_back(r5);
  
  room* r6 = new room("Main Cabin", "You are sitting in your plane seat.");
  roomList->push_back(r6);
 
  room* r7 = new room("Aisleway6", "You are in the aisleway, your seat is closeby");
  roomList->push_back(r7);

  room* r8 = new room("Aisleway7", "You are walking down the aisleway. There are two emergency doorways to your left and right.");
  roomList->push_back(r8);

  room* r9 = new room("Aisleway8", "You are at the door of the staff room.");
  roomList->push_back(r9);
  
  room* r10 = new room("Staff room", "You are inside the staff room. There is a hatch to the cargo on your left, and a kitchen on the right");
  roomList->push_back(r10);

  room* r11 = new room("Cargo Hold", "You are inside the cargo hold. There is a lot of luggage here and its very cold.");
  roomList->push_back(r11);

  room* r12 = new room("Kitchen", "You are in the kitchen. There are 4 microwaves and a pile of dinner rolls");
  roomList->push_back(r12);

  room* r13 = new room("Pilot Room", "You are inside the pilot room.");
  roomList->push_back(r13);

  room* r14 = new room("West Wing", "You climb across the flying plane with your superhuman jumping, and land on the west plane wing.");
  roomList->push_back(r14);

  room* r15 = new room("East Wing", "You climb across the flying plane with your superhuman jumping, and land on the east plane wing.");
  roomList->push_back(r15);

  //setting the exits, (N,E,S,W)
  r1->setExits(r2, NULL, NULL, NULL);
  r2->setExits(r4, NULL, r1, r3);
  r3->setExits(NULL, r2, NULL, NULL);
  r4->setExits(r5, NULL, r2, NULL);
  r5->setExits(r7, NULL, r4, r6);
  r6->setExits(NULL, r5, NULL, NULL);
  r7->setExits(r8, NULL, r9, NULL);
  r8->setExits(r9, r15, r7, r14);
  r9->setExits(r10, NULL, r8, NULL);
  r10->setExits(r13, r12, r9, r11);
  r11->setExits(NULL, r10, NULL, NULL);
  r12->setExits(NULL, NULL, NULL, r10);
  r13->setExits(NULL, NULL, r10, NULL);
  r14->setExits(NULL, r8, NULL, NULL);
  r15->setExits(NULL, NULL, NULL, r8);

  // set 5 items
  r6->setItems(1,0,0,0,1);
  r7->setItems(0,1,0,0,0);
  r4->setItems(0,0,1,0,0);
  playerBucket.initItems(0,0,0,1,0);

  // set current room pointer
  currentRoom = r6;
}

