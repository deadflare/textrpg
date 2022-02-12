#pragma once	//Fixes some error, no idea what it does.
#include <iostream>
#include "inventory.h"
#include "itemsinclude.h"
using namespace std;

/*Player will have an inventory, weight-based. Items can be taken from the inventory and put on the body, which frees space to carry stuff, but still contributes
 * weight. Player will also have a house with a chest inventory, which is not by weight, but by item count. Because there's more than one inventory system (player,
 * player's house, enemies, stores) the inventory will be a class, and each thing that has an inventory will have its own invetory object.*/

class player{	//The class used for the player.
	public:
		string name;
		string charclass;	//So far just Mage and Warrior. When the player is asked to set a class, he'll input 1 or 2, which corresponds to the class, which is changed from the number to a string, Mage or Warrior. After the class is set, hp and mp are set based on the class.
		int hp, mp, gold, level;
		int createplayer(){	//Input player name and class, which sets hp and mp, and gold is the same for all classes. Will add a rogue class and ranger class.
			cout << "\nEnter name:\n>";
			//cin >> name; //commented out to save time, automatically set to Blespi in line below. The lack of input messes with the blankspaces of the output, but when this is uncommented and the player gets to input, it's normal.
			name="Blespi";
			cout << "\nEnter class:\n1\tWarrior\n2\tMage\n>";
			//cin >> charclass;	//Player will enter a number, 1 or 2, to set the class. The number entered is changed to the string in the following two if statements, which also sets hp and mp based on the class. This is commented out for same reason that name is commented out, set to Mage in line below
			charclass="2";
			if(charclass=="1"){charclass="Warrior"; hp=100; mp=0;}
			if(charclass=="2"){charclass="Mage"; hp=75, mp=50;}
			gold=500;
			inventory Inventory;
			return 0;
		};
		int printstats(){
			cout << "\nPlayer name:\t" << name << "\nClass:\t" << charclass << "\nHP:\t" << hp << "\nMP:\t" << mp << "\nGold:\t" << gold << "\n";
			return 0;
		}
};
