#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include "Headers/entity.h"
#include "Headers/inventory.h"
#include "Headers/items.h"
player Player;
inventory playerinv (Player.strength);	//create inventory with capacity of strength
void invloop ();
#include "Headers/dungeon.h"	//need to put invloop () in another header

int randomrange (int min, int max) { //range: (min, max)
   return min+rand()%((max+1)-min);
};

void invloop () {
	
	while (true) {
		
		int action;
		std::cout << "\nEnter action:\n"
		"0\tExit\n"
		"1\tPrint inventory\n"
		"2\tInspect item\n"
		"3\tUse item\n"
		"4\tDrop item\n>";
		std::cin >> action;
		
		if (std::cin.fail ()) {	//user didn't enter an int
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\ninvalid input\n";
			continue;
		}
		if (action < 0 || action > 4) {	//user entered a number out of range
			std::cout << "\ninvalid input\n";
			continue;
		}
		
		switch (action) {
			case 0: {	//exit
				break;
			}
			
			case 1: {	//print player inventory
				playerinv.print ();
				continue;
			}
			
			case 2: {	//inspect an item
				playerinv.inspectitem();
				continue;
			}
			
			case 4: {	//drop an item
				playerinv.dropitem ();
				continue;
			}
		}
		break;
	}
	std::cout << "\nExit inventory";
};

void beggardialogue () {
	int action;
	std::cout << "\nA wretched beggar stumbles over to you. You quickly locate his hands, "
	"which are visible and empty. He seems too poor to afford a knife or weapon, so you do "
	"not consider him a threat. The only danger is the miasma wafting from his dirty clothes."
	"\n\"Please, sir, give a poor man a meal today?\""
	"\nHe shakily extends his wrinkled hands, palms up.";
	
	while (true){
		
		std::cout << "\nEnter action:"
		"\n0\tToss him some coins"
		"\n1\tDecline\n>";
		std::cin >> action;
		
		if (std::cin.fail ()) {	//user didn't enter an int. The only time this function isn't used
			std::cin.clear();	//is for the player's name. All other input is an int.
			std::cin.ignore();
			std::cout << "\ninvalid input\n";
			continue;
		}
		if (action < 0 || action > 1) {	//user entered a number out of range
			std::cout << "\ninvalid input\n";
			continue;
		}
		
		switch (action) {
			
			case 0: {	//give the beggar coins
				int coinstogive;
				std::cout << "\nHow many coins to give him?"
				"\nYou currently have " << Player.gold << " coins.\n>";
				std::cin >> coinstogive;
				
				if (std::cin.fail ()) {	//user didn't enter an int. The only time this function isn't used
					std::cin.clear();	//is for the player's name. All other input is an int.
					std::cin.ignore();
					std::cout << "\ninvalid input\n";
					continue;
				}
				if (coinstogive < 1 || coinstogive > Player.gold) {
					std::cout << "\nEnter a number 0 - " << Player.gold << "\n";
					continue;
				}
				
				Player.gold -= coinstogive;
				std::cout << "\nThe man accepts them graciously and blesses " << Player.name << ".\n";
				//Player.give(goodluck)
				break;
			}
				
			case 1: {
				std::cout << "\n" << Player.name << " does not sympathize with the man and walks away from him.\n";
				if (Player.gold >= 20) {	//if player has enough coins to give but is just being stingy, give bad luck
					std::cout << "Remember, you selfish bastard, fate could've made you like him with but a whim.\n";
					//Player.give(badluck)
				}
				
				else {	//if player is as poor as the beggar and cannot give any coins
					std::cout << "\n\"I'm very sorry,\", " << Player.name <<" says, \"but I'm nearly out of coins myself.\""
					"\nThe man's head bobs on his thin neck. \"I understand. I wish you luck.\""
					"\n\"And I you,\" " << Player.name << " responds.\n";
					}
					
				break;
			}
		}
		return;
	}
};

int main () {
	
	srand (time (0));	//seed random number
	if (Player.charclass == "Warrior") {	//give player weapon based on class
		playerinv.get ("sword", Player.level);
	}
	//if (Player.charclass == "Mage") {
		//playerinv.get ("wand", Player.level);
	//}
	
	while (true){
		
		int action;
		if (randomrange (1, 100) == 1) {beggardialogue ();}	//1% chance to encounter a beggar
		std::cout << "\nEnter action:"
		"\n0\tQuit"
		"\n1\tPrint player stats"
		"\n2\tTake a look around"
		"\n3\tGo to shop"
		"\n4\tInventory actions"
		"\n5\tEnter dungeon\n>";
		std::cin >> action;
		
		if (std::cin.fail ()) {	//user didn't enter an int. The only time this function isn't used
			std::cin.clear();	//is for the player's name. All other input is an int.
			std::cin.ignore();
			std::cout << "\ninvalid input\n";
			continue;
		}
		
		if (action < 0 || action > 5) {	//user entered a number out of range
			std::cout << "\ninvalid input\n";
			continue;
		}
		switch (action) {	//if input is valid
			case 0: {	//quit
				break;
			}
			
			case 1: {	//print player stats
				Player.printstats ();
				continue;
			}
			
			case 4: {	//Inventory loop
				invloop ();
				continue;
			}
			case 5: {	//Enter dungeon
				bool died = dungeon();
				if (died) {	//if player died, quit. player and enemy have already been destructed at this point
					return 0;
				}
				continue;	//if player didn't die, just exited dungeon
			}
		}
		
		std::cout << "\nquitting\n";
		//all objects are automatically destructed, I left a cout in the destructors of each object to make sure.
		break;
	}
}
