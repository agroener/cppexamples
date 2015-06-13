//DragonLord.cpp

#include <iostream>
#include <ctime>
#include<cstdlib>
#include "Dragon.cpp"
#include "RedDragon.cpp"
#include "BlueDragon.cpp"
#include "BlackDragon.cpp"

int menuChoice();

int main (void)
{

  using std::srand;
  using std::time;
  using std::rand;
  using std::cout;
  srand((unsigned int)time(0));
  Dragon* dragons[3];
  int hp = 15;
  int armour = 2;
  int tempArmour;
  int tempAttack;
  dragons[0] = new RedDragon(rand()%4+1);
  dragons[1] = new BlackDragon(rand()%4+1);
  dragons[2] = new BlueDragon(rand()%4+1);
  Dragon* d = dragons[rand()%3];
  cout << "Welcome noble knight.\n"
       << "You must save a princess."
       << " She has been captured by a "
       << d->getName() << ".\n"
       << "You must defeat the dragon.\n";
  cout << "Your hit points are: " << hp << "\n";
  while (d->isAlive() && hp>0)
    {
      int choice = menuChoice();
      if (choice == 3)
        goto RUN;
      else if (choice == 1)
        {
          tempAttack = rand()%16+5;
          tempArmour = armour;
        }
      else
        {
          tempAttack = rand()%11;
          tempArmour = armour + 4;
        }

      hp -= d->attack(armour);
      d->defend(rand()%16-5);
      cout << "\nYou deliver a mighty blow and deal " << tempAttack
           << " damage.\n";
      cout << "Your hit points are : " << hp;
    }
  if (d-> isAlive())
    cout << "\nYou have perished before"
         << " the might of the dragon.\n";
  else
    cout << "\n\nYou have slain the dragon!"
         << " Congratulations.\n"
         << "The princess is saved,\n";
  
  return 0;
 RUN:
  cout << "\nYou have fled in cowardice.\n";
  return 0;
}

int menuChoice()
{
  using std::cout;
  using std::cin;
  int choice;
  do {
    cout << "\n[1]Attack\n"
         << "[2]Defensive Mode\n"
         << "[3]Run Away\n";
    cin >> choice;
  } while (choice < 1 && choice < 3);
  return choice;
}
