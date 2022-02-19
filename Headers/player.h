#pragma once	//Fixes some error, no idea what it does.
#include <iostream>
#include "items.h"
using namespace std;

/*Player will have an inventory, weight-based. Items can be taken from the inventory and put on the body, which frees space to carry stuff, but still contributes
 * weight. Player will also have a house with a chest inventory, which is not by weight, but by item count. Because there's more than one inventory system (player,
 * player's house, enemies, stores) the inventory will be a class, and each thing that has an inventory will have its own invetory object.*/

class player{
	public:
	string name;
	string charclass;	//So far just Mage and Warrior. When the player is asked to set a class, he'll input 1 or 2, which corresponds to the class, which is changed from the number to a string, Mage or Warrior. After the class is set, hp and mp are set based on the class.
	int hp, maxhp, mp, maxmp, xp = 0, maxxp = 10, gold = 500, level = 1, strength;	//stength determines how much weight you can carry in your inventory
	float hppercent, mppercent, xppercent;	//HP%, MP%, XP%. percent values are calculated in player.printstats()
	vector<item*> inventory;	//because all types of items are childs of the main item class, don't need a separate vector for each type of item, and can put addresses of all items in same vector. objects don't have a name, rather are id'd by address.
	player(){	//Constructor, automatically called when player is created. Cosntructors cannot have return statements
		cout << "\nEnter name:\n>";
		//cin >> name; //commented out to save time, automatically set to Blespi in line below. The lack of input messes with the blankspaces of the output, but when this is uncommented and the player gets to input, it's normal.
		name="Blespi";
		cout << "\nEnter class:\n1\tWarrior\n2\tMage\n>";
		//cin >> charclass;	//Player will enter a number, 1 or 2, to set the class. The number entered is changed to the string in the following two if statements, which also sets hp and mp based on the class. This is commented out for same reason that name is commented out, set to Mage in line below
		charclass="1";
		if(charclass=="1"){charclass="Warrior"; maxhp = hp = 100; maxmp = mp = 25; strength = 100; get("sword");}	//HP and MP start out at full.
		if(charclass=="2"){charclass="Mage"; maxhp = hp = 75, maxmp = mp = 50;}
	};
		int getcarrying(){	//returns the sum of the weight of all items in inventory, except for gold.
			int carrying = 0;
			if(inventory.size() == 0){carrying = 0; return carrying;}	//Prevents an error, segmentation fault (core dumped)
			else{
				for(int i = 0; i <= inventory.size()-1; i++){
					carrying += inventory[i]->weight;
				}
			}
			return carrying;
		}
		int printstats(){
			hppercent = float(hp) / maxhp * 100;	//Calculate percents of HP, MP, XP
			mppercent = float(mp) / maxmp * 100;
			xppercent = float(xp) / maxxp * 100;
			cout << "\nPlayer name:\t" << name << "\nClass:\t" << charclass << "\nHP:\t" << hp << " / " << maxhp << " ( " << hppercent << " % )" << "\nMP:\t" << mp << " / " << maxmp << " ( " << mppercent << " % )" << "\nXP:\t" << xp << " / " << maxxp << " ( " << xppercent << " % )"  << "\nItems in inventory:\t" << inventory.size() << "\nCarrying:\t" << getcarrying() << " lbs\n";
			return 0;
		}
		int get(string itemtype){
			if(itemtype == "sword" && getcarrying() + 5 <= strength){	//An if statement to determine the object type. Also tests if the player has enough strength to carry the weight, in this case, 5 lbs.
				inventory.push_back(new sword(level));	//Adds a new element, pointer to an object, to the inventory vector. The object doesn't have a name (?) and is identified by the object's address. The item's level is the same level as the player's and cannot change (may add a feature to change item levels later)
				cout << "\nSword added to inventory.\n";
			}
			return 0;
		}
};
