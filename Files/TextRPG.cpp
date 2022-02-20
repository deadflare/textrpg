#include <iostream>
#include <cstring>
#include <cmath>	//to round float to int when printing stats
#include <ctime> //srand()
#include <vector>	//for inventory
int randomrange(int min, int max){ //range : (min, max)
   return min+rand()%((max+1)-min);
}
#include "Headers/centralloop.h"	//some of the headers included in centralloop.h use randomrange(), so if centralloop() was #included before randomrange() was defined, they wouldn't be able to access randomrange().
using namespace std;



int main(){	//just starts the game. nothing more
	centralloop();
	return 0;
}
