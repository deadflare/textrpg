#include <string>

class enemy{
	public:
	int enlevel, enhp, enmaxhp, enmp, enmaxmp, endmg;	//same members that player has, but prefixed with "en" to signify it's the enemy's member.
	string entype, endescription;
	enemy(string type, int level) : entype {type}, enlevel {level}
	{};
};

class kobold: public enemy{
	public:
	kobold(int enlevel) : enemy("kobold", enlevel){
		entype = "kobold";
		endescription = "A short goblin thing.";
		enmaxhp = enhp = enlevel * 75, enmaxmp = enmp = enlevel * 50;	//will adjust the balance later, just want to get things functioning
	}
	int printstats(){
		int enhppercent = round(float(enhp) / enmaxhp * 100), enmppercent = round(float(enmp) / enmaxmp * 100);	//Calculate enemy's HP% and MP% and round to nearest int
		cout << "\nEnemy name:\t" << entype << "\nLevel:\t" << enlevel << "\nHP:\t" << enhp << " / " << enmaxhp << " ( " << enhppercent << " % )" << "\nMP:\t" << enmp << " / " << enmaxmp << " ( " << enmppercent << " % )\n";
		return 0;
	}
};
