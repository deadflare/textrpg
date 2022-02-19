#include <iostream>
#include <cstring>
#include <ctime> //srand()
#include <vector>
#include "Headers/player.h"
player Player;
int randomrange(int min, int max){ //range : (min, max)
   return min+rand()%((max+1)-min);
}
#include "Headers/centralloop.h"
using namespace std;



int main(){	//This isn't in charge of much, mostly just at the start of the game. Most of the stuff is taken care of by the looping functions, see the centralloop() comment.
	Player.printstats();
	centralloop();
	
	return 0;
}
