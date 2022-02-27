#include "entity.h"

int randomrange (int min, int max);	//forward declaration

void printbasestats (entity enemy) {	//prints player's and enemy's HP% and MP%
	int hppercent = round (float (Player.hp) / Player.maxhp * 100);
	int mppercent = round (float (Player.mp) / Player.maxmp * 100);
	int enhppercent = round (float (enemy.hp) / enemy.maxhp * 100);
	int enmppercent = round( float (enemy.mp) / enemy.maxmp * 100);
	std::cout << "\n\tPlayer:\t\t" << enemy.name << ":\nHP:\t" << hppercent << " %\t\t" << enhppercent << " %\nMP:\t" << mppercent << " %\t\t" << enmppercent << " %\n";
}

int combatloop (entity enemy) {	//return 0 means player won, 1 means player died, 2 means player ran
	std::cout << "Fighting " << enemy.name << " level " << enemy.level << ".\n";
	printbasestats (enemy);
	while (true) {
		int action;
		std::cout << "\nEnter action:"
		"\n0\tRun away"
		"\n1\tHit"
		"\n2\tDo nothing"
		"\n3\tPrint stats (doesn't use a turn)"
		"\n4\tPrint enemy stats (doesn't use a turn)"
		"\n5\tInventory actions\n>";
		std::cin >> action;
		if (std::cin.fail ()) {	//user didn't enter an int. The only time this function isn't used
			std::cin.clear();	//is for the player's name. All other input is an int.
			std::cin.ignore();
			std::cout << "\ninvalid input\n";
			continue;
		}
		if (action < 0 || action > 5) {
			std::cout << "\ninvalid input\n";
			continue;
		}
		
		switch (action) {
			case 0: {	//run away
				return 2;
			}
			
			case 1: {	//hit enemy
				//Player.hitenemy
				enemy.hp -= 5000;
				std::cout << "\n" << Player.name << " hits the " << enemy.name << ".";
				if (enemy.hp < 1) {	//if player kills enemy
					std::cout << "\n" << Player.name << " kills the " << enemy.name << ".";
					return 0;
				}
				break;
			}
			
			case 2: {	//do nothing
				std::cout << "\n" << Player.name << " does nothing.";
				break;
			}
				
			case 3: {	//print player stats
				Player.printstats ();
				int invweightpercent = round (float (Player.getinventoryweight (playerinv)) / Player.strength * 100);
				std::cout << "\nItems in inventory:\t" << playerinv.inv.size () <<
				"\nWeight of inventory:\t" << Player.getinventoryweight (playerinv) << " / " << Player.strength << " lbs ( " << invweightpercent << " % )";
				continue;
			}
			
			case 4: {	//print enemy stats
				enemy.printstats ();
				continue;
			}
			
			case 5: {	//inventory actions
				invloop ();
				continue;
			}
		}
		
		//enemy hit player
		std::cout << "\nThe " << enemy.name << " hits " << Player.name << ".";
		if (Player.hp < 1) {	//if enemy kills player.
			std::cout << "\nThe " << enemy.name << " kills " << Player.name << ".";
			return 1;
		}
		if (enemy.hp < 1) {	//if player kills enemy. if enemy dies here, it's by passive DoT or something
			std::cout << "\n" << Player.name << " kills the " << enemy.name << ".";
			return 0;
		}
		
		printbasestats (enemy);	//print HP% and MP% of player and enemy at end of every turn
	}
}

bool dungeon(){	//if return 1, player died and exit game. if return 0, player exited dungeon, don't quit
	
	int floor;
	while (true) {
		
		std::cout << "\nEnter floor:\t(around your level is recommended)\n(or enter -1 to cancel)\n>";
		std::cin >> floor;
		
		if (std::cin.fail ()) {	//user didn't enter an int
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\ninvalid input\n";
			continue;
		}
		if (floor == -1) {return 0;}	//player cancelled entering dungeon
		if (floor <= 0) {		//floor is <= 0
			std::cout << "\ninvalid input\n";
			continue;
		}
		break;
	}
	while(true){
		
		int action;
		std::cout << "On dungeon floor " << floor << ".\n"
		"\nEnter action:"
		"\n0\tExit dungeon"
		"\n1\tFight something\n>";
		std::cin >> action;
		
		if (std::cin.fail ()) {	//user didn't enter an int. The only time this function isn't used
			std::cin.clear();	//is for the player's name. All other input is an int.
			std::cin.ignore();
			std::cout << "\ninvalid input\n";
			continue;
		}
		if (action < 0 || action > 1) {		//entered a number out of range
			std::cout << "\ninvalid input\n";
			continue;
		}
	
		switch (action) {
			case 0: {	//exit dungeon
				break;
			}
				
			case 1: {	//fight something
				int result;	//what combatloop() returns. 0 means won, 1 means dies, 2 means ran
				if (randomrange (1, 100) <= 100) {	//percent chance to fight types of enemies
					int enlvl = randomrange (floor - 5, floor + 5);	//enemy level is near floor of dungeon
					if (enlvl < 1) {enlvl = 1;}	//randomly generated level may be less than 1, and can't
					kobold Enemy (enlvl);		//have negative/0 level, so set back to 1.
					result = combatloop(Enemy);
				}
				
				switch (result) {	//do things based on how the fight ended
					case 0:
						std::cout << "\n" << Player.name << " won the fight!\n";
						//give XP and rewards
						continue;
						
					case 1:
						std::cout << "\n" << Player.name << " died an honorable death, fighting valiantly.\n";
						return 1;
					
					case 2:
						std::cout << "\n" << Player.name << " ran away like a coward.\n";
						continue;
				}
				break;
			}
				
		}
		break;
	}
	std::cout << "\nexiting dungeon\n";
	return 0;
}
