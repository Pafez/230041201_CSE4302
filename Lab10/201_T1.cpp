#include <iostream>

using namespace std;

class SpellCaster
{
protected:
    string casterName;
    int basePowerLevel;
    int health;
public:
    SpellCaster() {
        casterName = "N/A";
        basePowerLevel = 0;
        health = 50;
    }

    SpellCaster(string Name, int PowerLevel, int Health) {
        casterName = Name;
        basePowerLevel = PowerLevel;
        health = Health;
        if (basePowerLevel < 0) basePowerLevel = 0;
        if (health < 0) health = 0;
    }

    virtual int castSpell() const {
        cout << casterName << " is casting a generic spell..." << endl;
        return basePowerLevel;
    }

    void scout() const {
        cout << casterName << " is scouting the area for enemies." << endl;
    }
    
    virtual void takeDamage(int damage) {
        health -= damage;
    }

    bool isAlive() const {
        return health > 0;
    }

    void getInfo() const {
        cout << "Wizard: " << casterName << " Health: " << health << endl;
    }
    
    ~SpellCaster() {}
};

class Pyromancer: public SpellCaster
{
protected:
    int heatIntensity;
public:
    Pyromancer():SpellCaster() {
        heatIntensity = 0;
    }

    Pyromancer(string Name, int PowerLevel, int Health, int HeatIntensity):SpellCaster(Name, PowerLevel, Health) {
        heatIntensity = HeatIntensity;
    }

    virtual int castSpell() const {
        int newPowerLevel = SpellCaster::castSpell() + heatIntensity;
        cout << "Adding fire element..." << endl;
        return newPowerLevel;
    }

    virtual void takeDamage(int damage) {
        health -= damage*2;
    }

    ~Pyromancer() {}
};

class LavaMage: public Pyromancer
{
private:
    int magmaDensity;
public:
    LavaMage():Pyromancer() {
        magmaDensity = 0;
    }

    LavaMage(string Name, int PowerLevel, int Health, int HeatIntensity, int MagmaDensity):Pyromancer(Name, PowerLevel, Health, HeatIntensity) {
        magmaDensity = MagmaDensity;
    }

    int castSpell() const {
        int newPowerLevel = Pyromancer::castSpell() + magmaDensity;
        cout << "Solidifying magma..." << endl;
        return newPowerLevel;
    }

    void ignite() const {
        scout();
        cout << "The ground is burning!";
    }

    void takeDamage(int damage) {
        health -= damage*3;
    }

    ~LavaMage() {}
};

class Enemy
{
protected:
    string name;
    int health;
    int armor;
public:
    Enemy() {
        name = "BaseEnemy";
        health = 10;
        armor = 2;
    }

    Enemy(string Name, int Health, int Armor) {
        name = Name;
        health = Health;
        armor = Armor;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    int attack() const {
        return 10;
    }

    string getType() const {
        return name;
    }

    bool isAlive() {
        return health > 0;
    }

    void getInfo() const {
        cout << "Enemy: " << name << " Health: " << health << endl;
    }

    ~Enemy() {}
};

class Ogre: public Enemy
{
private:
    bool rageMode;
public:
    Ogre(string Name, int Health, int Armor, bool RageMode): Enemy(Name, Health, Armor) {
        rageMode = RageMode;
    }

    int attack() const {
        if (rageMode) return 25;
        return 20;
    }

    void takeDamage(int damage) {
        int trueDamage = damage - armor;
        if (trueDamage > 0) health -= trueDamage;
        if (health > 0 && health < 5) rageMode = 1; 
    }

    ~Ogre() {}
};

int battle(SpellCaster * wizards[], Enemy * enemies[]) {
    int target = rand()%3;
    static int turn = 1;
    if (turn) {
        int totalDamage = 0;
        for (int i = 0; i < 3; i++) {
            if (!wizards[i]->isAlive()) continue;
            totalDamage += wizards[i]->castSpell();
        }
        Enemy * targetEnemy;
        int isEveryOneDead = 1;
        for (int i = 0; i < 3; i++) {
            if (!enemies[(target+i)%3]->isAlive()) continue;
            targetEnemy = enemies[(target+i)%3];
            targetEnemy->takeDamage(totalDamage);
            isEveryOneDead = 0;
            break;
        }
        if (isEveryOneDead) return 2;
    }
    else {
        int totalDamage = 0;
        for (int i = 0; i < 3; i++) {
            if (!enemies[i]->isAlive()) continue;
            totalDamage += enemies[i]->attack();
        }
        SpellCaster * targetWizard;
        int isEveryOneDead = 1;
        for (int i = 0; i < 3; i++) {
            if (!wizards[(target+i)%3]->isAlive()) continue;
            targetWizard = wizards[(target+i)%3];
            targetWizard->takeDamage(totalDamage);
            isEveryOneDead = 0;
            break;
        }
        if (isEveryOneDead) return -2;
    }
    turn = !turn;
    return turn;
}

int main() {
    srand(time(0));

    SpellCaster * wizards[3];
    Enemy * enemies[3];

    wizards[0] = new SpellCaster("SpellCaster", 20, 70);
    wizards[1] = new Pyromancer("Pyromancer", 20, 60, 10);
    wizards[2] = new LavaMage("LavaMage", 20, 40, 10, 20);
    
    enemies[0] = new Enemy("Enemy1", 60, 50);
    enemies[1] = new Enemy("Enemy2", 60, 50);
    enemies[2] = new Enemy("Enemy3", 60, 50);


    int status;
    while (true)
    {
        status = battle(wizards, enemies);
        if (status == -2 or status == +2) break;
    }
    
    if (status == 2) {
        cout << "Wizards won" << endl;
        for (int i = 0; i < 3; i++) {
            if (wizards[i]->isAlive()) wizards[i]->getInfo();
        }
    }
    else {
        cout << "Enemies won" << endl;
        for (int i = 0; i < 3; i++) {
            if (enemies[i]->isAlive()) enemies[i]->getInfo();
        }
    }
}

