#include <string>
using namespace std;

//when item is dropped or otherwise lost, use the tilde key to destruct the class and free memory. to destruct item sword1, do ~sword1;

class item{
	public:
	int level, value, weight;
	string name, description;
	item(string itemname, int itemlevel) : name {itemname}, level {itemlevel}	//for some reason I can't use = to set the variables, but it sets name equal to itemname and level equal to itemlevel.
	{};	//The value will be determined from the item type and level, the description and weight by the item type
		
};

class sword: public item{
	public:
	sword(int playerlevel) : item("sword", playerlevel){	//item level is equal to player level when it's created.
		//will also have stats like crit chance, and maybe methods that add health/mana or whatever
		weight = 5;
		name = "sword";
		description = "A steel sword with a wire-wrapped hilt, about three feet in length. ";
	}
};
