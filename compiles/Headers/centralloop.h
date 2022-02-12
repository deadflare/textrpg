#include <iostream>
#include <string>
#include "player.h"
#include "shop.h"
#include "beggardialogue.h"
using namespace std;

int centralloop(){
	string action;	/*in theory, the player would only enter an int, and it would have a corresponding action. if the players enters a number that isn't an action,
	if(action != 1 && action != 2 ...){cout << "invalid input} would work. However, the user ay accidentally enter a letter, which breaks it, so changing it to a
	string allows it to handle letters and numbers. https://www.reddit.com/r/cpp_questions/comments/so2w21/basic_user_input_while_loop_cant_figure_out_how/*/
	while(true){
		if(randomrange(1, 100) ==1){beggardialogue();}	//1 in 100 chance of encountering a beggar. When it happens, beggardialogue() is called.
		cout << "\nEnter action:\n1\tQuit\n2\tPrint player stats\n3\tTake a look around\n4\tGo to shop\n>";
		cin >> action;
		if(action == "1" || action == "q"){
				string quitconfirm;
				cout << "\nQuit?\n1\tyes\n2\tno\n>";
				cin >> quitconfirm;
				if(quitconfirm == "1" || quitconfirm == "y"){return 0;}
				else if(quitconfirm == "2" || quitconfirm == "n"){}
				else{cout << "\ninvalid input\n";}
		}
		else if(action == "2"){Player.printstats();}
		else if(action == "3"){cout << "\nYou stand on the side of a wide dirt road lined with wooden buildings. The streets are mostly empty, a few people are walking, some men are playing cards on a table outside a tavern, and some beggars sit or lie along the road.";}
		else if(action == "4"){shop();}
		else{cout << "\ninvalid input\n";}
	}
	return 0;
}
