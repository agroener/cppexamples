//BlueDragon.cpp

#include <string>

using std::string;

class BlueDragon : public Dragon
{
private:
  int iceDamage;
public:
  BlueDragon(int theSize);
  int attack(int targetArmour);
  void defend(int damage);
  string getName() { return "Blue Dragon"; }
};

BlueDragon::BlueDragon(int theSize) : Dragon(theSize)
{
  iceDamage = 3 * getSize();
}

int BlueDragon::attack(int targetArmour)
{
  return Dragon::attack(targetArmour, iceDamage);
}

void BlueDragon::defend(int damage)
{
  getHitPoints() -= (damage-getArmour())/2;
}
