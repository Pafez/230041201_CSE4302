#include <iostream>
#include <cmath>

using namespace std;

class Wizard
{
private:
    string wizardName;
    string familiarType;
    int spellPower;
    int manaPool;
public:
    Wizard();
    Wizard(string name, string type, int power, int mana);
    ~Wizard();

    Wizard & duel(Wizard & opponent);
    void print();
};

Wizard::Wizard() {
    wizardName = "N/A";
    familiarType = "N/A";
    spellPower = 0;
    manaPool = 0;
}
Wizard::Wizard(string name, string type, int power, int mana)
{
    wizardName = name;
    familiarType = type;
    spellPower = power;
    manaPool = mana;
}

Wizard::~Wizard()
{
}

Wizard & Wizard::duel(Wizard & opponent) {
    double A_ofCaller = pow(spellPower, 0.8f) * manaPool / (manaPool + opponent.spellPower) + log2(spellPower+1) * sqrt(manaPool);
    double A_ofOpponent = pow(opponent.spellPower, 0.8f) * opponent.manaPool / (opponent.manaPool + spellPower) + log2(opponent.spellPower+1) * sqrt(opponent.manaPool);
    if (A_ofOpponent > A_ofCaller) return opponent;
    else return *this;
}

void Wizard::print() {
    cout << "Wizard: " << wizardName << ", ";
    cout << "Familiar: " << familiarType << ", ";
    cout << "Spell Power: " << spellPower << ", ";
    cout << "Mana: " << manaPool;
}

int main() {
    Wizard wizards[5];
    wizards[0] = Wizard("Yuusha", "Nekomancy", 85, 130);
    wizards[1] = Wizard("Farha", "Nitration", 87, 120);
    wizards[2] = Wizard("Sig", "Chrome", 75, 145);
    wizards[3] = Wizard("Faiyaz", "Scholar", 55, 190);
    wizards[4] = Wizard("Pafez", "Melody", 70, 155);

    cout << "=== All Wizards ===" << endl;
    for (int i = 0; i < 5; i++) {
        wizards[i].print();
        cout << endl;
    }

    cout << "\n=== Tournament ===" << endl;
    Wizard winner = wizards[0];
    for (int i = 1; i < 5; i++) {
        cout << "\nRound " << i << ": "; winner.print();
        cout << "\nvs "; wizards[i].print();
        cout << "\nWinner: "; (winner = winner.duel(wizards[i])).print();
        cout << endl;
    }

    cout << "\n=== Ultimate Champion ===" << endl;
    winner.print();

    return 0;
}
