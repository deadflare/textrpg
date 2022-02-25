class item{
	public:
	int level, value, weight, uniqueid;
	string type, description;
	item(string itemtype, int itemlevel, int uniqueidpassed) : type {itemtype}, level {itemlevel}, uniqueid {uniqueidpassed}	//for some reason I can't use = to set the variables, but it sets name equal to itemname and level equal to itemlevel.
	{};	//The value will be determined from the item type and level, the description and weight by the item type. All the constructor is used for is to set the item type and level.
		
};

class sword: public item{
	public:
	sword(int playerlevel, int uniqueidpassed) : item("sword", playerlevel, uniqueidpassed){	//item level is equal to player level when it's created.
		//will also have stats like crit chance, and maybe methods that add health/mana or whatever
		int uniqueid = uniqueidpassed;	//This is used to identify each item, not just its location in the inventory. When an item is dropped, it's spot in the vector is changed, so it doesn't actually ID it. This is a member in each item that increments and is different in each item, and is never reused.
		weight = 5;
		type = "sword";
		description = "A steel sword with a wire-wrapped hilt, about three feet in length. ";
		int dmg = playerlevel;	//The hard part of making an RPG is getting the balance right. I'll do that later, for now it's relative to the player. The actual damage done when hitting an enemy is a random number within 20% of the item's damage both positive and negative (see dungeon.h combat function).
	}
};
