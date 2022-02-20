#include <iostream>
#include <string>
#include "player.h"
player Player;
#include "shop.h"
#include "beggardialogue.h"
using namespace std;

int centralloop(){
	Player.printstats();
	string action;	/*in theory, the player would only enter an int, and it would have a corresponding action. if the players enters a number that isn't an action,
	if(action != 1 && action != 2 ...){cout << "invalid input} would work. However, the user ay accidentally enter a letter, which breaks it, so changing it to a
	string allows it to handle letters and numbers. https://www.reddit.com/r/cpp_questions/comments/so2w21/basic_user_input_while_loop_cant_figure_out_how/*/
	while(true){
		if(randomrange(1, 100) ==1){beggardialogue();}	//1 in 100 chance of encountering a beggar. When it happens, beggardialogue() is called.
		cout << "\nEnter action:\n1\tQuit\n2\tPrint player stats\n3\tTake a look around\n4\tGo to shop\n5\tInventory actions\n6\tEnter dungeon\n>";
		cin >> action;
			if(action == "1" || action == "q"){		//Confirm player meant to quit and then quit/cancel.
				string quitconfirm;
				cout << "\nQuit?\n1\tyes\n2\tno\n>";
				cin >> quitconfirm;
				if(quitconfirm == "1" || quitconfirm == "y"){return 0;}
				else if(quitconfirm == "2" || quitconfirm == "n"){}
				else{cout << "\ninvalid input\n";}
			}
			else if(action == "2"){Player.printstats();}
			else if(action == "3"){cout << "\nYou stand on the side of a wide dirt road lined with buildings. The streets are mostly empty, a few people are walking, some men are playing cards on a table outside a tavern, and several beggars sit or lie in the road.";}
			else if(action == "4"){shop();}
			else if(action == "5"){Player.inventoryloop();}
			else if(action == "6"){
				bool died = Player.calldungeon(Player);	//had a hard time finding the right order to #include headers in, and where to include them, trying not to get namespace/no function call errors etc. Player.calldungeon() just calls dungeon() function, had to do it this way to prevent errors
				if(died){return 0;}	//If player died, quit.
			}
			else{cout << "\ninvalid input\n";}
	}
	return 0;
}
