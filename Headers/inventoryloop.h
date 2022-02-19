#include <iostream>
using namespace std;

//Doesn't have anything related to the inventory structure, just gives the user ability to view inventory, drop items, etc.

int inventoryloop(){
	string action;
	while(true){
		cout << "\nChoose an action:\n1\tExit\n2\tPrint inventory\n3\tInspect item\n4\tUse item\n5\tDrop item\n>";
		cin >> action;
		if(action == "1"){return 0;}
		else if(action == "2"){	//Print inventory
			if(Player.inventory.size() == 0){cout << "\nNo items in inventory.\n";}	//Prevents an error, segmentation fault (core dumped)
			else{
				cout << "\nID:\tName:\tLevel:\tWeight:\n";
				for(int i = 0; i <= Player.inventory.size()-1; i++){	//iterates through elements in inventory vector, prints number ID (can be used to select an item to do stuff with), name, weight, and level.
					cout << i << "\t" << Player.inventory[i]->name << "\t" << Player.inventory[i]->level << "\t" << Player.inventory[i]->weight << " lbs\n";
				}
			}
		}
		else{cout << "\ninvalid input\n"; inventoryloop();}
	}
};
