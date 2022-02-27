#ifndef ITEMS_H
#define ITEMS_H

class item {
	public:
	int level, value;	//not const because I will add a feature to upgrade items, thus increasing the value of it. also item buffs, which increase value
	int weight, uniqueid;
	std::string type, description;
	item (std::string itemtype, int itemlevel, int uniqueidpassed) : type {itemtype}, level {itemlevel}, uniqueid {uniqueidpassed}
	{};	//The value will be determined from the item type and level, the description and weight by the item type.
	//All the constructor is used for is to set the item type and level.	
	virtual ~item () {std::cout << "\ndeleted " << type;};
	virtual void inspect () {std::cout << "here";};	//not all items have the same members, like shields don't have dmg, and swords don't have def.
						//I don't know how to inspect an item and print all its stats, without redefining the function
						//specific to each item, which repeats code, but it's how it works for now.
};

class sword: public item {
	public:
	int dmg;	//not all item types have certain stats like this, so it can't be declared in the base item class.
	sword (int level, int uniqueidpassed) : item ("sword", level, uniqueidpassed) {	//item level is equal to player level when it's created.
		//will also have stats like crit chance, and maybe methods that add health/mana or whatever
		int uniqueid = uniqueidpassed;	//used to ID each item, not just its spot in the inventory. IDs are never reused
		weight = 5;
		type = "sword";
		description = "A steel sword with a wire-wrapped hilt, about three feet in length.";
		int dmg = level;	//will figure this out later
	};
	virtual ~sword () {};
	void inspect () {
		std::cout << "\nID:\t" << uniqueid <<
		"\nDescription:\t" << description <<
		"\nLevel:\t" << level <<
		"\nWeight:\t" << weight << " lbs" <<
		"\nDamage:\t" << dmg << "\n";
	};
};

#endif
