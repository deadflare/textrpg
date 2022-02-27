#ifndef INVENTORY_H
#define INVENTORY_H

#include "items.h"

class inventory {	//used for player's inventory, body, and storage (trunk at his house or something), probably more later
	public:
	int cancarry;
	std::vector<item*> inv;
	inventory (int cancarry){	//cancarry is determined by charclass. it's used to see if the
		cancarry = cancarry;	//player has enough room to get an item, in get().
	};
	
	virtual ~inventory () {
		std::cout << "\ndeleted inventory";
		if (inv.size () == 0) {std::cout << "\nno items to delete"; return;}	//prevents segmentation fault
		for (int i = 0; i <= inv.size () - 1; i++) {
			delete inv [i];
		}
	};
	
	int i = 0;	//a unique ID number assigned to each object
	void get (std::string type, int level) {
		if (type == "sword"){
			inv.push_back (new sword (level, i));
			std::cout << "\nSword added to inventory.\n";
			i++;
		}
	}
	void print () {
		if (inv.size () == 0) {std::cout << "\nNo items in inventory.\n";}
		else{
			std::cout << "\nNumber:\t"
			"ID:\t"
			"Type:\t"
			"Level:\t"
			"Weight:\t"
			"Memory address (for debugging):\n";
			for (int i = 0; i <= inv.size () - 1; i++) {
				std::cout << i << "\t" <<
				inv [i] -> uniqueid << "\t" <<
				inv [i] -> type << "\t" <<
				inv [i] -> level << "\t" <<
				inv [i] -> weight << " lbs\t" <<
				&inv [i] << "\n";
			}
		}
	};
	
	void inspectitem () {
		while (true) {
			if (inv.size() == 0) {std::cout << "\nYou don't have any items to drop.\n"; return;}
			int itemtoinspect;	//an element in the inventory vector.
			std::cout << "\nInspect which item?\t(enter item number)\n"
			"(or enter -1 to cancel)\n>";
			std::cin >> itemtoinspect;
			if (std::cin.fail ()) {	//user didn't enter an int
				std::cin.clear ();
				std::cin.ignore ();
				std::cout << "\ninvalid input\n";
				continue;
			}
			if (itemtoinspect == -1) {return;}	//user cancelled the inspect
			if (itemtoinspect < 0 || itemtoinspect >= inv.size ()) {	//user entered a number out of range
				std::cout << "\nYou only have " << inv.size () << " items in your inventory.";
				continue;
			}
			std::cout << "\nInspect item " << inv [itemtoinspect] -> type << "\n";
			inv [itemtoinspect] -> inspect ();
			std::cout << "Memory location:\t" << &inv [itemtoinspect] << "\n";
			return;
		}
	};
	
	void dropitem () {
		while (true) {
			if (inv.size() == 0) {std::cout << "\nYou don't have any items to drop.\n"; return;}
			int itemtodrop;
			std::cout << "\nDrop which item?\t(enter item number)\n"
			"(or enter -1 to cancel\n>";
			std::cin >> itemtodrop;
			if (std::cin.fail ()) {	//user didn't enter an int
				std::cin.clear ();
				std::cin.ignore ();
				std::cout << "\ninvalid input\n";
				continue;
			}
			if (itemtodrop == -1) {return;}	//user cancelled the drop
			if (itemtodrop < 0 || itemtodrop >= inv.size ()) {	//user entered a number out of range
				std::cout << "\nYou only have " << inv.size () << " items in your inventory.";
				continue;
			}
			int dropconfirm;
			std::cout << "\nDrop item " << inv [itemtodrop] -> type << "? This is irrevocable!\n"
			"0\tyes\n"
			"1\tno, cancel\n>";
			std::cin >> dropconfirm;
			if (std::cin.fail ()) {	//user didn't enter an int
				std::cin.clear ();
				std::cin.ignore ();
				std::cout << "\ninvalid input\n";
				continue;
			}
			if (dropconfirm < 0 || dropconfirm > 1) {std::cout << "\nYou only have " << inv.size () << " items in your inventory."; continue;}
			if (dropconfirm == 0) {	//player confirmed the drop
				std::cout << "\nDropped " << inv [itemtodrop] -> type << "\n";
				delete inv [itemtodrop];	//destruct object
				inv.erase(inv.begin()+itemtodrop);	//remove from inventory vector
				return;
			}
			if (dropconfirm == 1) {return;}	//player cancelled the drop
		}
	};
};

#endif
