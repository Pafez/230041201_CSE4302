#include <iostream>

using namespace std;

class SnackProfile
{
private:
    string itemName;
    string makerName;
    double MRP;
    double discount;
public:
    SnackProfile();
    ~SnackProfile();
    void setLabels(string item, string maker);
    void setMRP(double price);
    void setDiscount(double percent);
    double getUnitPrice();
    double getTotalPrice(int qty);
    void info();
};

SnackProfile::SnackProfile()
{
    itemName = "Dummy";
    makerName = "Dummy";
    discount = 7.0;
    MRP = 0.0;
}

SnackProfile::~SnackProfile() {}

void SnackProfile::setLabels(string item, string maker) {
    itemName = item;
    makerName = maker;
}

void SnackProfile::setMRP(double price) {
    if (price < 0.0) {
        MRP = 0.0;
        cout << "Invalid MRP; set to 0.0" << endl;
        return;
    }
    MRP = price;
}

void SnackProfile::setDiscount(double percent) {
    if (percent < 0.0 || percent > 25.0) {
        cout << "Invalid Discount; did not update" << endl;
        return;
    }
    discount = percent;
}

double SnackProfile::getUnitPrice() {
    return MRP * (1 - discount/100.0);
}

double SnackProfile::getTotalPrice(int qty = 1) {
    if (qty < 0) {
        cout << "Invalid quantity" << endl;
        return 0.0;
    }
    return qty * getUnitPrice();
}

void SnackProfile::info() {
    cout << itemName << " by " << makerName;
    printf(": MRP %.2f, Discount %.1f%%", MRP, discount);
}

int main() {
    SnackProfile oss;
    oss.info();
}
