#ifndef ENTITY_H
#define ENTITY_H

#include "inventory.h"

class entity {	//both player and enemy will be of this class.
	public:
	
	int level, maxhp, hp, maxmp, mp;
	std::string name, description;
	entity (int level, std::string name) : level {level}, name {name} {};
	virtual ~entity () {};
	virtual void printstats () {};
};

class player : public entity {
	public:
	
	std::string charclass;
	int hp, maxhp, mp, maxmp, xp = 0, maxxp = 10, gold = 5, level = 1, strength;	//strength is how much weight the player can carry, determined by class. don't confuse with str
	int str, def, intl, agi, luk;	//stats that can be upgraded when player levels up. str is damage bonus, don't confuse with strength
	
	player () : entity (1, "player") {	//create player
		std::cout << "\nEnter player name:\n"
		">";
		//std::cin >> name;	//name is automatically set to save time
		name = "Blespi";
		
		int tmpclass;
		std::cout << "\nEnter class:\n"
		"0\tWarrior\n"
		"1\tMage\n>";
		//std::cin >> tmpclass;	//class is automatically set to save time
		tmpclass = 0;	//number corresponds to class type.
		
		switch (tmpclass) {
			
			case 0:
				charclass = "Warrior";
				maxhp = hp = 100;
				maxmp = mp = 25;
				strength = 100;
				break;
				
			case 1:
				charclass = "Mage";
				maxhp = hp = 75;
				maxmp = mp = 50;
				strength = 75;
				break;
		}
	}
	
	virtual ~player () {std::cout << "\ndeleted player";};
	
	int getinventoryweight (inventory playerinv) {	//the sum of the weight of all items in player's inventory.
		int weightofinventory = 0;
		
		for (int i = 0; i < playerinv.inv.size (); i++){	//iterate through each item and add weight
			weightofinventory += playerinv.inv [i] -> weight;
		}
		return weightofinventory;
	}
	
	void printstats () {
		int hppercent = round (float (hp) / maxhp * 100);	//HP%, MP%, XP%, strength. percent
		int mppercent = round (float (mp) / maxmp * 100);	//values are calculated and rounded
		int xppercent = round (float (xp) / maxxp * 100);	//to the nearest int
		
		std::cout << "\nPlayer name:\t" << name <<
		"\nLevel:\t" << level <<
		"\nClass:\t" << charclass <<
		"\nHP:\t" << hp << " / " << maxhp << " ( " << hppercent << " % )" <<
		"\nMP:\t" << mp << " / " << maxmp << " ( " << mppercent << " % )" <<
		"\nXP:\t" << xp << " / " << maxxp << " ( " << xppercent << " % )" <<
		"\nGold:\t" << gold;
		
	}
};

class kobold : public entity {
	public:
	int dmg;
	kobold (int level) : entity (level, "kobold") {
		description = "A short goblin thing.";
		maxhp = hp = level * 75;
		maxmp = mp = level * 50;
	}
	
	virtual ~kobold () {std::cout << "\ndeleted enemy";};
	virtual void printstats () {
		int hppercent = round (float (hp) / maxhp * 100);
		int mppercent = round (float (mp) / maxmp * 100);
		std::cout << "\nEnemy type:\t" << name <<
		"\nLevel:\t" << level <<
		"\nHP:\t" << hp << " / " << maxhp << " ( " << hppercent << " % )" <<
		"\nMP:\t" << mp << " / " << maxmp << " ( " << mppercent << " % )" <<
		"\nDmg:\t" << dmg;
	};
};

#endif
