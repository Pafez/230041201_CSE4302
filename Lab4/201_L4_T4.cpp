#include <iostream>

using namespace std;

class CreditCard
{
private:
    double creditLimit;
    double currentBalanceOwed;
public:
    CreditCard(double limit);
    ~CreditCard();

    int makePurchase(double amount);
    bool compareAvailability(const CreditCard & anotherCard);
    void displayInfo() const;
};

CreditCard::CreditCard(double limit)
{
    creditLimit = limit;
    currentBalanceOwed = 0.0f;
}

CreditCard::~CreditCard()
{
    cout << "Card destroyed" << endl;
}

int CreditCard::makePurchase(double amount) {
    double newCreditAmount = currentBalanceOwed + amount;
    if (newCreditAmount > creditLimit) {
        cout << "Declined" << endl;
        return 1;
    }
    currentBalanceOwed = newCreditAmount;
    return 0;
}

bool CreditCard::compareAvailability(const CreditCard & anotherCard) {
    if (anotherCard.creditLimit-anotherCard.currentBalanceOwed < creditLimit-currentBalanceOwed) return true;
    return false;
}

void CreditCard::displayInfo() const {
    cout << "Current Limit: " << creditLimit << endl;
    cout << "Current Balance: " << currentBalanceOwed << endl;
    cout << "Available Credit: " << creditLimit - currentBalanceOwed << endl;
}
