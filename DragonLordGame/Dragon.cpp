// The Dragon Lord Game - Austen Groener
// Dragon.cpp

#include <string>
#include <ctime>
#include <cstdlib>

using std::string;

#define MAX(a,b) a>b ? a:b

class Dragon
{
private:
  int speed;
  string name;
  int hitPoints;
  int armour;
  int treasure;
  int clawDamage;
  int size;
protected:
  Dragon(int theSize);
  int getArmour() {return armour; }
  int& getHitPoints() { return hitPoints; }
  int getClawDamage() { return clawDamage; }
  int getSize() { return size; }
  virtual int attack(int targetArmour, int specialDamage);
public:
  virtual int attack(int targetArmour) = 0;
  virtual void defend(int damage) = 0;
  int getTreasure() { return treasure; }
  virtual string getName() { return name; }
  bool isAlive() { return hitPoints > 0; }
};

Dragon::Dragon(int theSize) : size(theSize)
{
  if (size < 1 || size > 4)
    size = 3;
  clawDamage = 2 * size;
  speed = 3 * size;
  hitPoints = 4 * size;
  armour = size;
  treasure = 1000 * size;
  srand(time(0));
}

int Dragon::attack(int targetArmour, int specialDamage)
{
  int useSpecial = rand() % 2; // 0 or 1
  int damage;
  if (useSpecial)
    damage = specialDamage;
  else
    damage = getClawDamage();
  return MAX(damage - targetArmour,0);
  
}
