/*The goal of this is to be more organized and intuitive than the old TextRPG. Most changes do not affect what the player will see, but will make the code less messy.
What does change for the interface is: printing < before any output line that does not expect input. printing > before any line that expects input. between things
like rounds in fights, print # three times, each on a new line, to make things clearer. making the output more uniform.*/
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
