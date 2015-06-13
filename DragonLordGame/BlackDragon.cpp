//BlackDragon.cpp

#include <string>

using std::string;

class BlackDragon : public Dragon
{
private:
  int poisonDamage;
public:
  BlackDragon(int theSize);
  int attack(int targetArmour);
  void defend(int damage);
  string getName() { return "Black Dragon"; }
};

BlackDragon::BlackDragon(int theSize) : Dragon(theSize)
{
  poisonDamage = getSize();
}

int BlackDragon::attack(int targetArmour)
{
  return Dragon::attack(targetArmour, poisonDamage);
}

void BlackDragon::defend(int damage)
{
  getHitPoints() -= damage - getArmour();
}


