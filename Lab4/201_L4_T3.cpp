#include <iostream>

using namespace std;

class Zombie
{
private:
    int HP;
    static int totalZombiesAlive;
public:
    Zombie(int initialHP);
    ~Zombie();

    void takeDamage(int damageAmount);
    static int getHordeCount();
}; int Zombie::totalZombiesAlive = 0;

Zombie::Zombie(int initialHP)
{
    HP = initialHP;
    totalZombiesAlive++;
    cout << "A new zombie rises! Total count: " << totalZombiesAlive;
}

Zombie::~Zombie()
{
    totalZombiesAlive--;
    cout << "Zombie eliminated. Total remaining: " << totalZombiesAlive;
}

void Zombie::takeDamage(int damageAmount) {
    int newHealth = HP - damageAmount;
    if (newHealth < 0) {
        cout << "Zombie is ‘down’" << endl;
        HP = 0;
        return;
    }
    HP = newHealth;
}

int Zombie::getHordeCount() {
    return totalZombiesAlive;
}
