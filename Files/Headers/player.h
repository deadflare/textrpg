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

	vector<item*> inventory;	//because all types of items are childs of the main item class, don't need a separate vector for each type of item, and can put addresses of all items in same vector. objects don't have a name, rather are id'd by address.
	player(){	//Constructor, automatically called when player is created. Cosntructors cannot have return statements
		cout << "\nEnter name:\n>";
		//cin >> name; //commented out to save time, automatically set to Blespi in line below. The lack of input messes with the blankspaces of the output, but when this is uncommented and the player gets to input, it's normal.
		name="Blespi";
		cout << "\nEnter class:\n1\tWarrior\n2\tMage\n>";
		//cin >> charclass;	//Player will enter a number, 1 or 2, to set the class. The number entered is changed to the string in the following two if statements, which also sets hp and mp based on the class. This is commented out for same reason that name is commented out, set to Mage in line below
		charclass="1";
		if(charclass=="1"){charclass="Warrior"; maxhp = hp = 10; maxmp = mp = 25; strength = 100; get("sword"); get("sword");}	//HP and MP start out at full.
		if(charclass=="2"){charclass="Mage"; maxhp = hp = 75, maxmp = mp = 50;}
	};
	int printstats(){	//print player stats.
		int hppercent = round(float(hp) / maxhp * 100), mppercent = round(float(mp) / maxmp * 100), xppercent = round(float(xp) / maxxp * 100);	//HP%, MP%, XP%. percent values are calculated and rounded to nearest int
		cout << "\nPlayer name:\t" << name << "\nLevel:\t" << level << "\nClass:\t" << charclass << "\nHP:\t" << hp << " / " << maxhp << " ( " << hppercent << " % )" << "\nMP:\t" << mp << " / " << maxmp << " ( " << mppercent << " % )" << "\nXP:\t" << xp << " / " << maxxp << " ( " << xppercent << " % )"  << "\nItems in inventory:\t" << inventory.size() << "\nCarrying:\t" << getcarrying() << " lbs\n";
		return 0;
	}
	#include "inventory.h"
	#include "dungeon.h"
	bool calldungeon(player playerobj){bool died = dungeon(playerobj); return died;}	//tldr; #including headers is complicated. dungeon.h is included here, not in centralloop, thus Player isn't declared in the dungeon function. So I pass the existing Player as a parameter, playerobj just points to the Player object. It works, but should find a better way to do this
};
