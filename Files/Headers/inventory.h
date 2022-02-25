int getitem(int action) { /*Gets user input to select an item to either inspect,
  drop, or use, one of the three actions is set in the parameter. Used in the
  inspect, drop, and use functions. Returns int inventoryi, which is used like
  Player.inventory[inventoryi]->type The reason a whole function is needed for
  this is because it's used in several places, as stated above, I don't want to
  have to repeat code.
  This function gets user input, tests if it is an int, if it is, then it tests
  if it is within the range of the amount of items in the player's inventory (if
  there is an item it IDs). Uses try and catch to prevent errors.*/
  string itemid;     // item id's are displayed when the inventory is printed.
  string straction;  // Will be either inspect, drop, or use, depending on the
                     // parameter of this function.
  switch (action) {  // Sets straction according to action parameter
    case 1:  // If the parameter action is 1, straction is set to "Inspect"
      straction = "Inspect";
      break;
    case 2:  // Drop
      straction = "Drop";
      break;
    case 3:  // Use
      straction = "Use";
      break;
  }
  cout << "\n"
       << straction << " which item? (enter item ID) (enter x to cancel)\n>";
  cin >> itemid;
  bool exceptioncaught = true;  // Used to test if input is in range of the
                                // inventory size (see below)
  int itemidint;
  if (itemid == "x") {
    return -1;
  }  // if player cancels. Can't return 1 because there may be inventory[1] to
     // select.
  else {   // will test if itemid is an int, if it's not a n int, invalid input.
           // If it is an int, test if an item correlates to that number or if
           // it's out of range of the inventory size.
    try {  // I feel like this is sloppy code, should be a simpler way to do
           // this. Figure it out later, it works for now.
      itemidint = stoi(itemid);  // tries to get an int from input, if input
                                 // isn't an int, the error will be caught.
      if (itemidint >= inventory.size()) {
        cout << "\nYou only have " << inventory.size()
             << " items in your inventory. Enter a number between 0 and "
             << inventory.size() - 1 << ".\n";
        return -1;  // If the user enters a number that exceeds the number of
                    // items in the inventory.
      }
      exceptioncaught = false;  // if it reaches this point, everything was
                                // successful and there is no error, continues.
    } catch (std::invalid_argument& error) {
      cout << "\ninvalid input\n";
      return -1;
    }
    if (!exceptioncaught) {
      return itemidint;
    }
  }
  return 0;
}

int printinv() {
  if (inventory.size() == 0) {
    cout << "\nNo items in inventory.\n";
  }  // Prevents an error, segmentation fault (core dumped)
  else {
    cout << "\nNumber:\tID:\tType:\tLevel:\tWeight:\tMemory address (for "
            "debugging):\n";
    for (int i = 0; i <= inventory.size() - 1;
         i++) {  // iterates through elements in inventory vector, prints number
                 // ID (can be used to select an item to do stuff with), name,
                 // weight, and level.
      cout << i << "\t" << inventory[i]->uniqueid << "\t" << inventory[i]->type
           << "\t" << inventory[i]->level << "\t" << inventory[i]->weight
           << " lbs\t" << &inventory[i] << "\n";
    }
  }
  return 0;
}

int inventoryloop() {  // Inventory loop
  string action;
  while (true) {
    cout << "\nEnter action:\n1\tExit\n2\tPrint inventory\n3\tInspect "
            "item\n4\tUse item\n5\tDrop item\n>";
    cin >> action;
    if (action == "1" || action == "q") {
      return 0;
    } else if (action == "2") {
      printinv();
    }                          // Print inventory
    else if (action == "3") {  // Inspect an item
      int validitemid =
          getitem(1);  // The 1 parameter means the action is to inspect the
                       // item, not to drop or use. Also, if getitem() returns
                       // -1, it means something went wrong and the if statement
                       // below will not execute.
      if (validitemid != -1) {
        cout << "\nDescription of " << inventory[validitemid]->type << ":\n"
             << inventory[validitemid]->description << &inventory[validitemid]
             << "\n";
      }  // print item type and description if the input is valid.
      else {
        inventoryloop();
      }  // If getitem() returns -1, the if statement above will be skipped,
         // bringing it here, and nothing will happen with the inventory.
    } else if (action == "4") {
    } else if (action == "5") {
      drop();
    } else {
      cout << "\ninvalid input\n";
      inventoryloop();
    }
  }
  return 0;
};

int getcarrying() {  // returns the sum of the weight of all items in inventory,
                     // except for gold.
  int carrying = 0;
  if (inventory.size() == 0) {
    carrying = 0;
    return carrying;
  }  // Prevents an error, segmentation fault (core dumped)
  else {
    for (int i = 0; i <= inventory.size() - 1;
         i++) {  // iterates through each item in the inventory, and adds the
                 // weights together to get the total weight the player is
                 // carrying.
      carrying += inventory[i]->weight;
    }
  }
  return carrying;
}
int i = 1;
int get(string itemtype) {  // Add an item to inventory
  if (itemtype == "sword" &&
      getcarrying() + 5 <=
          strength) {  // An if statement to determine the object type. Also
                       // tests if the player has enough strength to carry the
                       // weight, in this case, 5 lbs.
    inventory.push_back(new sword(
        level, i));  // Adds a new element, pointer to an object, to the
                     // inventory vector. The object doesn't have a name (?) and
                     // is identified by the object's address. The item's level
                     // is the same level as the player's and cannot change (may
                     // add a feature to change item levels later)
    cout << "\nSword added to inventory.\n";
    i++;
  }
  return 0;
}

int drop() {  // Drop an item
  int validitemid = getitem(
      2);  // The 2 parameter means the action is to drop the item, not to
           // inspect or use. Also, if getitem() returns -1, it means something
           // went wrong and the if statement below will not execute.
  if (validitemid !=
      -1) {  // If the player has entered a valid input, confirm that they
             // really want to drop the item. If validitemid = -1, there was a
             // problem with the user input. If it's not, it's an int that can
             // be used to access the element of the inventory vector that the
             // user selected.
    string dropconfirm;
    cout << "\nDo you really want to drop " << inventory[validitemid]->type
         << "? This action is irrevocable!\n1\tyes\n2\tno\n>";
    cin >> dropconfirm;
    if (dropconfirm == "1") {
      cout << "\nDropped " << inventory[validitemid]->type
           << &inventory[validitemid] << ".\n";
      delete inventory
          [validitemid];  // Allocates the memory taken by the dropped object by
                          // deleting it. The address that is deleted is reused
                          // for other items, which confused the shit out of me
                          // because I thought the address never changed and
                          // could be used to identify each item, hence uniqueid
                          // was created.
      inventory.erase(
          inventory.begin() +
          validitemid);  // Removes the dropped item from the inventory vector.

    } else if (dropconfirm == "2") {
      return 0;
    }  // If player cancels the drop
    else {
      cout << "\ninvalid input\n";
      return 0;
    }
  } else {
    inventoryloop();
  }  // If getitem() returns -1, the if statement above will be skipped,
     // bringing it here, and nothing will happen with the inventory.
  return 0;
}
