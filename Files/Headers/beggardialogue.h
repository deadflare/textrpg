int beggardialogue() {  // Gives you a chanc to give some coins to a beggar. If
                        // you give him coins, you will have a temporary luck
                        // bonus, which I have yet to implement.
  string action;
  cout
      << "\nA wretched beggar stumbles over to you. You quickly locate his "
         "hands, which are visible and empty. He seems too poor to buy a knife "
         "or weapon, so you do not consider him a threat. The only danger is "
         "the miasma wafting from his dirty clothes.\n\"Please, sir, give a "
         "poor man a meal today?\"\nHe shakily extends a wrinkled hand, palm "
         "up.\nChoose an action:\n1\tToss him some coins\n2\tDecline\n>";
  cin >> action;
  if (action == "1") {
    cout << "\nHow many?\n>";
    string amount;
    cin >> amount;
    try {
      int intamount = stoi(amount);
      if (Player.gold >= intamount) {
        Player.gold -= intamount;
      } else {
        cout << "\nYou don't have enough coins. You have:\n"
             << Player.gold << " coins.\n";
        beggardialogue();
      }
    }  // Attempts to change string amount to int amount to catch invalid input.
       // If it fails to convert to int, a letter was found and thus invalid
       // input. Then, checks to see if player has enough coins.
    catch (std::invalid_argument& error) {
      cout << "\ninvalid input\n";
      beggardialogue();
    }
  } else if (action == "2") {
    cout << "\nYou do not sympathize with the man and walk away from him.\n";
  } else {
    cout << "\ninvalid input\n";
    beggardialogue();
  }
  return 0;
}
