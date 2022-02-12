#pragma once
#include <string>
using namespace std;
//Doesn't need <iostream> because it only holds values, doesn't print them.

class sword{
	public:
	int damage, price, level;
	float weight = 5;
	string name = "sword";
	string description = "A mid-sized steel sword with a wire hilt. Seems sturdy, and light for its size and strength.";
	
};

vector<sword> swordvector;	//Contains all instances of sword, each can be identified by its place in the vector.
