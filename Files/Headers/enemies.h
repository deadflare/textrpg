class enemy {
 public:
  int rarity, enlevel, enhp, enmaxhp, enmp, enmaxmp,
      endmg;  // same members that player has, but prefixed with "en" to signify
              // it's the enemy's member. rarity is used to determine rewards.
              // lower rarity is less rewards.
  string entype, endescription;
  enemy(string type, int level) {
    enlevel = level;
    entype = type;
    if (type == "kobold") {
      endescription = "A short goblin thing.";
    }
    rarity = 1, enmaxhp = enhp = enlevel * 75,
    enmaxmp = enmp = enlevel * 50;  // will adjust the balance later, just want
                                    // to get things functioning
  }
  int printstats() {
    int enhppercent = round(float(enhp) / enmaxhp * 100),
        enmppercent = round(
            float(enmp) / enmaxmp *
            100);  // Calculate enemy's HP% and MP% and round to nearest int
    cout << "\nEnemy name:\t" << entype << "\nLevel:\t" << enlevel
         << "\nRarity:\t" << rarity << "\nHP:\t" << enhp << " / " << enmaxhp
         << " ( " << enhppercent << " % )"
         << "\nMP:\t" << enmp << " / " << enmaxmp << " ( " << enmppercent
         << " % )\n";
    return 0;
  }
};
