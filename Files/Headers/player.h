#include "items.h"
/*Player will have an inventory, weight-based. Items can be taken from the inventory and put on the body, which frees space to carry stuff, but still contributes
 * weight. Player will also have a house with a chest inventory, which is not by weight, but by item count. Because there's more than one inventory system (player,
 * player's house, enemies, stores) the inventory will be a class, and each thing that has an inventory will have its own invetory object.*/

class player{
	public:
	string name, charclass;	//So far just Mage and Warrior. When the player is asked to set a class, he'll input 1 or 2, which corresponds to the class, which is changed from the number to a string, Mage or Warrior. After the class is set, hp and mp are set based on the class.
	int hp, maxhp, mp, maxmp, xp = 0, maxxp = 10, gold = 500, level = 1;	//None of these items can be changed by the player, only by the player's level.
	int strength;	//stength determines how much weight you can carry in your inventory
	int str, def, intl, agi, luk;	// these can be increased by distributing points when player levels up. strength (damage output multiplier), defense (armor, decreases damage taken), intelligence (crit rate), agility (dodge rate), luck (rewards from dungeon).
	float strbonus, defbonus, intlbonus, agibonus, lukbonus;
	vector<item*> inventory;	//because all types of items are childs of the main item class, don't need a separate vector for each type of item, and can put addresses of all items in same vector. objects don't have a name, rather are id'd by address.
	player(){	//Constructor, automatically called when player is created. Cosntructors cannot have return statements
		cout << "\nEnter name:\n>";
		//cin >> name; //commented out to save time, automatically set to Blespi in line below. The lack of input messes with the blankspaces of the output, but when this is uncommented and the player gets to input, it's normal.
		name="Blespi";
		cout << "\nEnter class:\n1\tWarrior\n2\tMage\n>";
		//cin >> charclass;	//Player will enter a number, 1 or 2, to set the class. The number entered is changed to the string in the following two if statements, which also sets hp and mp based on the class. This is commented out for same reason that name is commented out, set to Mage in line below
		charclass="1";
		if(charclass=="1"){charclass="Warrior"; maxhp = hp = 100; maxmp = mp = 25; strength = 100; get("sword");}	//HP and MP start out at full. strength never changes and is set according to class.
		if(charclass=="2"){charclass="Mage"; maxhp = hp = 75, maxmp = mp = 50;}
	};
	int printstats(){	//print player stats.
		int hppercent = round(float(hp) / maxhp * 100), mppercent = round(float(mp) / maxmp * 100), xppercent = round(float(xp) / maxxp * 100);	//HP%, MP%, XP%. percent values are calculated and rounded to nearest int
		cout << "\nPlayer name:\t" << name << "\nLevel:\t" << level << "\nClass:\t" << charclass << "\nHP:\t" << hp << " / " << maxhp << " ( " << hppercent << " % )" << "\nMP:\t" << mp << " / " << maxmp << " ( " << mppercent << " % )" << "\nXP:\t" << xp << " / " << maxxp << " ( " << xppercent << " % )"  << "\nItems in inventory:\t" << inventory.size() << "\nCarrying:\t" << getcarrying() << " lbs\n";
		return 0;
	}
	int checklevelup(){	//check if player has enough XP to level up. if so, allow him to distribute points towards attributes.
		if(xp >= maxxp){
			cout << "\nLevel up! " << level << "->" << level++ << "\nYou have 4 points to distribute towards attributes.";
			level++;
			int carryxp = xp - maxxp;	//if player has, say, 12 / 10 XP, the 2 XP will carry into the next level.
			maxxp += level;
			xp = carryxp;
			for(int i = 4; i >= 0; i--){	//player gets 4 points to dsitribute, which is done here.
				if(str == 500 && def == 500 && intl == 500 && agi == 500 && luk == 500){cout << "\nYou've already maxed out all your stats (no stat can have more than 500 points).\n"; return 0;}	//checks if there's any more stats that can be increased, because no stat can have more than 500 points. 500 is arbitrary and may change later.
				else{	//if stats can be increased
					cout << "\nPoints left:\t" << i << "\nChoose where to put points.\n0\tStrength:\tincreases damage you deal\n1\tDefense:\tdecreases damage you take\n2\tIntelligence:\tcrit rate\n3\tAgility:\tdodge rate\n4\tLuck:\trewards from dungeon\n>";
					string place;
					cin >> place;
					if(place == "0"){if(str == 500){cout << "\nNo stat can have more than 500 points. Choose something else.\n";}else{cout << "\n1 point to str.\n"; str++;}}	//checks if this stat can be increased, if it can, increase it, else choose another stat to increase.
					if(place == "1"){if(str == 500){cout << "\nNo stat can have more than 500 points. Choose something else.\n";}else{cout << "\n1 point to def.\n"; def++;}}
					if(place == "2"){if(str == 500){cout << "\nNo stat can have more than 500 points. Choose something else.\n";}else{cout << "\n1 point to intl.\n"; intl++;}}
					if(place == "3"){if(str == 500){cout << "\nNo stat can have more than 500 points. Choose something else.\n";}else{cout << "\n1 point to agi.\n"; agi++;}}
					if(place == "4"){if(str == 500){cout << "\nNo stat can have more than 500 points. Choose something else.\n";}else{cout << "\n1 point to luk.\n"; luk++;}}
				}
			}
		}
		else{return 0;}
		
	}
	#include "inventory.h"
	#include "dungeon.h"
	bool calldungeon(player playerobj){bool died = dungeon(playerobj); return died;}	//tldr; #including headers is complicated. dungeon.h is included here, not in centralloop, thus Player isn't declared in the dungeon function. So I pass the existing Player as a parameter, playerobj just points to the Player object. It works, but should find a better way to do this
};
