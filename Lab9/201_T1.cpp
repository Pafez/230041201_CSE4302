#include <iostream>

using namespace std;

class SpellCaster
{
private:
    string casterName;
    int basePowerLevel;
public:
    SpellCaster() {
        casterName = "N/A";
        basePowerLevel = 0;
    }

    SpellCaster(string Name, int PowerLevel) {
        casterName = Name;
        basePowerLevel = PowerLevel;
        if (basePowerLevel < 0) basePowerLevel = 0;
    }

    int castSpell() const {
        cout << casterName << " is casting a generic spell..." << endl;
        return basePowerLevel;
    }

    void scout() const {
        cout << casterName << " is scouting the area for enemies." << endl;
    }
    

    ~SpellCaster() {}
};

class Pyromancer: protected SpellCaster
{
private:
    int heatIntensity;
public:
    Pyromancer():SpellCaster() {
        heatIntensity = 0;
    }

    Pyromancer(string Name, int PowerLevel, int HeatIntensity):SpellCaster(Name, PowerLevel) {
        heatIntensity = HeatIntensity;
    }

    int castSpell() const {
        int newPowerLevel = SpellCaster::castSpell() + heatIntensity;
        cout << "Adding fire element..." << endl;
        return newPowerLevel;
    }

    void scout() const {
        SpellCaster::scout();
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

    LavaMage(string Name, int PowerLevel, int HeatIntensity, int MagmaDensity):Pyromancer(Name, PowerLevel, HeatIntensity) {
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

    ~LavaMage() {}
};

int main() {
    LavaMage Yuusha("Yuusha", 100, 50, 34);
    Yuusha.scout();
    int dmg = Yuusha.castSpell();
    cout << "Damage: " << dmg << endl;
    Yuusha.ignite();

    return 0;
}
