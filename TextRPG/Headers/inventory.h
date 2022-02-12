#include <iostream>
#include <string>
#include <vector>
#include "sword.h"
using namespace std;

//Will start with just an inventory, then will add the player's body to equip things on.

class inventory{
	public:
	int get(string item){
		if(item == "sword"){	//creates an object, and puts the object into the vector of the object's class.
			sword Sword;
			Sword.level = Player.level;
			swordvector.push_back(Sword);	//all instances of the class have the same name, but can be identified by its place in swordvector (like swordvector[1]).
			
		}
	}
	int printinv(){
		cout << "\nSwords:\n";
		for(int i = 0; i<=swordvector.size(); i++){
			cout << 
		}
	}
};
