#include <iostream>
using namespace std;

/*Does not offer magical supplies, that's what the Arcanist sells. Things like wands, enchantments, spell books, and magic potions like exploding potions. */

int shop(){
	cout << "\nWelcome, " << Player.name << ", to my shop. What can I do for you?";
	string action;
	while(true){
		cout << "\nChoose an action:\n1\tExit shop\n2\tBuy something\n3\tTake a look around\n>";
		cin >> action;
		if(action == "1"){
			string exitconfirm;
			cout << "\nExit?\n1\tyes\n2\tno\n>";
			cin >> exitconfirm;
			if(exitconfirm == "1"){return 0;}
			else if(exitconfirm == "2"){}
			else{cout << "\ninvalid input\n";}
		}
		else if(action == "2"){cout << "\nbuy\n";}
		else if(action == "3"){cout << "\nThe shop is a large, rectangular room, dimly lit. The pungent scent of bitter herbs is thick in the air. There are several aisles, each one offering a different category of items, none of which have magical supplies. An intimidatingly large woman sits at a dark wooden desk with a number of drawers and chests around it.\n";}
		else{cout << "\ninvalid input\n";}
	}
}
