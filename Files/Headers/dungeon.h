#include "enemies.h"

int printbasestats(player playerobj, enemy enemyobj){	//every round, prints the player's and enemy's HP% and MP%. also a 1% chance for the player to recover 10% HP.
	int playerhppercent = round(float(playerobj.hp) / playerobj.maxhp * 100), playermppercent = round(float(playerobj.mp) / playerobj.maxmp * 100);	//player's HP%, MP% percent values are calculated and rounded to nearest int
	float enemyhppercent = round(float(enemyobj.enhp) / enemyobj.enmaxhp * 100), enemymppercent = round(float(enemyobj.enmp) / enemyobj.enmaxmp * 100);	//enemy's HP% and MP% rounded to nearest int
	cout << "\nYour stats:\t|Enemy stats:\nHP:\t" << playerhppercent << " %\t|" << enemyhppercent << " %\nMP:\t" << playermppercent << " %\t|" << enemymppercent << " %\n";
	if(randomrange(1, 100) == 1){	//1% chance to recover a small amount of HP. This is the only way HP can be greater than 100%. Only happens every round, that's why it's here, and not when player does something that doesn't increment round.
			int recoverhp = playerobj.maxhp / 10;
			playerobj.hp += recoverhp;
			cout << "\nFate smiles upon you. You recover " << recoverhp << " HP ( + 10 % )\n";
		}
	return 0;
}

int calcdamage(){};	//calculate damage the player and enemy give. will account for item damage, stats, and whatever else. currently the damage is calculated in combatloop().

int combatloop(player playerobj, enemy enemyobj){
	int round = 0;	//how long the fight has been going for.
	printbasestats(playerobj, enemyobj);
	while(true){	//Each time the while loop starts again, it's a new round. Each round, you get a turn to hit, and then the enemy gets a turn to hit. Actions that don't use a turn are printing player/enemy stats and inventory actions.
		bool gethit = true, newround = true;	//newround is set to false if player does an action that doesn't use a turn (see above comment). if gethit is true, the enemy will hit the player.
		string action;	//newround is used to tell if a round passed or not. rounds may pass even if the player does nothing or if the enemy is asleep/stunned (because magic) and doesn't attack. I can't just use gethit to increment the round because he enemy may be asleep.
		cout << "\nEnter action:\tRound:\t" << round << "\n1\tRun away\n2\tHit\n3\tDo nothing\n4\tPrint stats (doesn't use a turn)\n5\tInventory actions (doesn't use a turn)\n6\tPrint enemy stats (doesn't use a turn)\n>";
		cin >> action;
		if(action == "1"){return 3;}	//run away, delete enemy object and deallocate memory used by object. enemy is deleted at return, when it goes out of scope (I think).
		else if(action == "2"){	//Decrease enemy's HP by a random number around the damage of the player's equipped weapon.
			int dealdamage = randomrange(playerobj.level - (playerobj.level / 5), playerobj.level + (playerobj.level / 5)) * 10; //deals damage within 20% of the player's equipped weapon, both positive and negative (if weapon does 10 dmg, random range is 8-12).
			cout << "\nYou hit the enemy for " << dealdamage << " HP ( - " << dealdamage / enemyobj.enmaxhp * 100 << " % of enemy's HP )\n";
			if(enemyobj.enhp - dealdamage <=0){playerobj.xp += enemyobj.rarity * 5; return 1;}	//If player deals enough damage to kill the enemy. enemy is deleted at return, when it goes out of scope (I think). also increases player XP.
			else{enemyobj.enhp -= dealdamage;}	//If player doesn't kill the enemy, just reduce enemy's HP.
		}
		else if(action == "3"){}	//Do nothing. may be useful for damage-triggered buffs or something later idk
		else if(action == "4"){playerobj.printstats(); gethit = newround = false;}	//Print player stats
		else if(action == "5"){inventoryloop(); gethit = newround = false;}	//Inventory actions
		else if(action == "6"){enemyobj.printstats(); gethit = newround = false;}	//Print enemy's stats
		else{cout << "\ninvalid input\n";}
		if(gethit){	//if player did something that uses a turn, enemy will hit player.
			int dealdamage = randomrange(enemyobj.enlevel - (enemyobj.enlevel / 5), enemyobj.enlevel + (enemyobj.enlevel / 5)) * 7;	//deals damage within 20% of enemy's level, and multiplies it. will change this later because different enemies have different stats.
			cout << "\nThe enemy hits you for " << dealdamage << " HP ( - " << dealdamage / playerobj.maxhp * 100 << " % of your HP )\n";
			if(playerobj.hp - dealdamage <= 0){return 2;}	//if player dies. enemy is deleted at return, when it goes out of scope (I think), so don't have to use delete keyword.
			else{cout << "here"; playerobj.hp -= dealdamage;}	//if player doesn't die, reduce player's HP.
		}
		if(newround){round++; printbasestats(playerobj, enemyobj);} //print player and enemy stats automatically, and increment round number.
		if(enemyobj.enhp <= 0){playerobj.xp += enemyobj.rarity * 5; return 1;}	//if enemy died without the player hitting it, probably by poison potion or some DoT thing. also increases player XP.
	}
}

int combat(player playerobj, string entype, int dungeonfloor){	//fight function, parameters are the enemy's type and level. If return 1, the player won the fight. If return 2, player died. If return 3, player ran.
	if(randomrange(1, 100) >=0){	//currently a 100% chance to fight a kobold, will add more types of enemies later.
		int enlvltmp = randomrange(dungeonfloor - 3, dungeonfloor + 3);
		if(enlvltmp <=0){enlvltmp = 1;}	//if player is on dungeon floor 1, and the enemy level is less than  or equal to 0 (see above), set enemy level to 1 because can't have negative level.
		enemy Enemy("kobold", enlvltmp);	//enemy level is random within 3 of the current dungeon floor. if on floor 10, level will be 7-13.
		combatloop(playerobj, Enemy);
	}
	return 0;
}

int dungeon(player playerobj){	//dungeon loop
	string floor;
	cout << "\nFloor to enter: (around your level is recommended)\n>";
	cin >> floor;
	bool exception = true;	//used to check if user's input is valid
	try{int floorint = stoi(floor); exception = false;}
	catch(std::invalid_argument& error){cout << "\ninvalid input\n"; dungeon(playerobj);}
	if(!exception){	//If user entered a valid floor.
		string action;
		cout << "\nEntering floor " << floor << "...\n";
		
		while(true){
			cout << "Enter action:\n1\tExit dungeon\n2\tEnter a different floor of the dungeon\n3\tFind something to fight\n>";
			cin >> action;
			if(action == "1"){return 0;}	//Exit dungeon
			else if(action == "2"){dungeon(playerobj);}	//Enter a different floor of the dungeon, just restarts the function
			else if(action == "3"){
				int outcome = combat(playerobj, "kobold", stoi(floor));	//outcome is what combat() returns. if it returns 1, player won fight. if returns 2, player died. if returns 3, player ran. avoiding returning 0 just in case
				switch(outcome){
					case 1:
						cout << "\n" << playerobj.name << " won the fight!\n";
						break;
					case 2:
						cout << "\n" << playerobj.name << " dies an honorable death, fighting valiantly.\n";
						return 1;	//sets bool died in player.h true, died is then returned to centralloop.h which then quits.
						break;
					case 3:
						cout << "\n" << playerobj.name << " ran away like a coward.\n";
						break;
				}
			}
			else{cout << "\ninvalid input\n";}
		}
	}
	else{cout << "\ninvalid input\n"; dungeon(playerobj);}
	return 0;
};
