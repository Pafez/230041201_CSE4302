#include <iostream>

using namespace std;

enum CrustType {
    Thin,
    Thick,
    Stuffed
};

class Pizza
{
private:
    string pizzaName;
    CrustType crustType;
    int spicinessLevel;
    bool isExtraCheesy;
public:
    Pizza();
    Pizza(string name, CrustType crustT, int spice, bool extraCheese);
    ~Pizza();

    string getPizzaName() const;
    int setPizzaName(string name);

    CrustType getCrustType() const;
    int setCrustType(CrustType crustT);

    int getSpicinessLevel() const;
    int setSpicinessLevel(int spice);

    bool getIsExtraCheesy() const;
    int setIsExtraCheesy(bool extraCheese);

    static int totalCrustType;
};

int Pizza::totalCrustType = 3;

Pizza::Pizza()
{
    pizzaName = "Unnamed";
    crustType = Thin;
    spicinessLevel = 0;
    isExtraCheesy = false;
}

Pizza::Pizza(string name, CrustType crustT, int spice, bool extraCheese)
{
    pizzaName = name;
    crustType = crustT;
    spicinessLevel = spice;
    isExtraCheesy = extraCheese;
}

Pizza::~Pizza() {}

string Pizza::getPizzaName() const {
    return pizzaName;
}
int Pizza::setPizzaName(string name) {
    pizzaName = name;
    return 0;
}

CrustType Pizza::getCrustType() const {
    return crustType;
}
int Pizza::setCrustType(CrustType crustT) {
    if (0 > crustT or crustT > totalCrustType) {
        cout << "Invalid Crust Type, defaulting to Thin" << endl;
        crustType = Thin;
        return 1;
    }
    crustType = crustT;
    return 0;
}

int Pizza::getSpicinessLevel() const {
    return spicinessLevel;
}
int Pizza::setSpicinessLevel(int spice) {
    if (spicinessLevel < 1 or spicinessLevel > 10) {
        cout << "Invalid Spiciness Level, defaulting to 5 (medium)" << endl;
        spicinessLevel = 5;
        return 1;
    }
    spicinessLevel = spice;
    return 0;
}

bool Pizza::getIsExtraCheesy() const {
    return isExtraCheesy;
}
int Pizza::setIsExtraCheesy(bool extraCheese) {
    isExtraCheesy = extraCheese;
    return 0;
}

void prepareOrders(Pizza menu[], int size) {
    for (int i = 0; i < 4; i++)
    {
        string name; int crustType; int spicinessLevel; string isExtraCheesy;
        cout << "How would you like Pizza " << i+1 << endl;
        cout << "Pizza Name: "; cin >> name; menu[i].setPizzaName(name);
        cout << "Crust Type (0->Thin, 1->Thick, 2->Stuffed): "; cin >> crustType; menu[i].setCrustType((CrustType)crustType);
        cout << "Spice Level: "; cin >> spicinessLevel; menu[i].setSpicinessLevel(spicinessLevel);
        cout << "Extra Cheese? Y/N: "; cin >> isExtraCheesy; (isExtraCheesy == "Y") ? (menu[i].setIsExtraCheesy(true)) : (menu[i].setIsExtraCheesy(false));
    }
    for (int i = 4; i < 30; i++) {
        menu[i].setPizzaName("Mystery Pizza");
        menu[i].setCrustType(Thick);
        menu[i].setSpicinessLevel(rand()%10+1);
        if (i%2 + 1) menu[i].setIsExtraCheesy(true);
    }
}

int main() {
    Pizza orders[30];
    string crustTypes[Pizza::totalCrustType] = {"Thin", "Thick", "Stuffed"};
    string boolToString[2] = {"Yes", "No"};
    prepareOrders(orders, 30);
    for (int i = 0; i < 30; i++) {
        if (orders[i].getSpicinessLevel() < 7) continue;
        cout << "Pizza Name: " << orders[i].getPizzaName() << endl;
        cout << "Crust Type: " << crustTypes[orders[i].getCrustType()] << endl;
        cout << "Spice Level: " << orders[i].getSpicinessLevel() << endl;
        cout << "Extra Cheese: " << boolToString[orders[i].getIsExtraCheesy()] << endl;
    }
}
