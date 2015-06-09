#include <iostream>

class Weapon
{
  int cost;
  int damage;
public:
  Weapon(int theCost, int theDamage);
  int getCost() {return cost;}
};

Weapon::Weapon(int theCost, int theDamage) : cost(theCost), damage(theDamage)
  {}

class ProjectileWeapon : public Weapon
{
  int range;
public:
  ProjectileWeapon(int theCost, int theDamage, int theRange);
};

ProjectileWeapon::ProjectileWeapon(int theDamage, int theCost, int theRange)
  : Weapon(theDamage, theCost), range(theRange)
{}

int main()
{
  using std::cout;
  ProjectileWeapon bow(5,2,10);
  cout << "The cost is " << bow.getCost() << "\n";
  return 0;
}
