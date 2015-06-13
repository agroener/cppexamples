//RedDragon.cpp
#include <string>

using std::string;

class RedDragon : public Dragon
{
private:
  int fireDamage;
public:
  RedDragon(int theSize);
  int attack(int targetArmour);
  void defend(int damage);
  string getName() { return "Red Dragon"; }
};

RedDragon::RedDragon(int theSize) : Dragon(theSize)
{
  fireDamage = 4 * getSize();
}

int RedDragon::attack(int targetArmour)
{
  return Dragon::attack(targetArmour, fireDamage);
}

void RedDragon::defend(int damage)
{
  getHitPoints() -= (damage-getArmour())/3;
}
