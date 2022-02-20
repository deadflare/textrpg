#include <string>
using namespace std;

//when item is dropped or otherwise lost, use the tilde key to destruct the class and free memory. to destruct item sword1, do ~sword1;

class item{
	public:
	int level, value, weight;
	string type, description;
	item(string itemtype, int itemlevel) : type {itemtype}, level {itemlevel}	//for some reason I can't use = to set the variables, but it sets name equal to itemname and level equal to itemlevel.
	{};	//The value will be determined from the item type and level, the description and weight by the item type. All the constructor is used for is to set the item type and level.
		
};

class sword: public item{
	public:
	sword(int playerlevel) : item("sword", playerlevel){	//item level is equal to player level when it's created.
		//will also have stats like crit chance, and maybe methods that add health/mana or whatever
		weight = 5;
		type = "sword";
		description = "A steel sword with a wire-wrapped hilt, about three feet in length. ";
		int dmg = playerlevel;	//The hard part of making an RPG is getting the balance right. I'll do that later, for now it's relative to the player. The actual damage done when hitting an enemy is a random number within 20% of the item's damage both positive and negative (see dungeon.h combat function).
	}
};
