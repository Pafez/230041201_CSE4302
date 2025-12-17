#include <iostream>

using namespace std;

class DigitalWallet
{
private:
    string userID;
    double balance;

    bool isOverdraft() const;
public:
    DigitalWallet();
    DigitalWallet(string UID, double initBalance);
    ~DigitalWallet();

    string getUserID() const;
    double getBalance() const;

    int setUserID(string UID);
    int setBalance(double newBalance);

    DigitalWallet operator+(double deposit) const ;
    DigitalWallet operator-(double withdrawal) const ;
    DigitalWallet operator*(double interest) const ;

    operator long() const;

    void checkStatus() const;
};

DigitalWallet::DigitalWallet() {
    userID = "N/A";
    balance = 0.0f;
}

DigitalWallet::DigitalWallet(string UID, double initBalance)
{
    userID = UID;
    balance = initBalance;
}

DigitalWallet::~DigitalWallet()
{
    cout << "\n\nAccount " << userID << " closed with balance " << balance << endl;
}

bool DigitalWallet::isOverdraft() const {
        if (balance < 0.0f) return true;
        return false;
}

string DigitalWallet::getUserID() const {
    return userID;
}
double DigitalWallet::getBalance() const {
    return balance;
}

int DigitalWallet::setUserID(string UID) {
    if (UID.length() < 5) {
        cout << "UserID must be at least 5 characters!" << endl;
        return 2;
    }
    userID = UID;
}
int DigitalWallet::setBalance(double newBalance) {
    if (newBalance < 0.0f) {
        cout << "Overdraft detected!" << endl;
    }
    balance = newBalance;
}

DigitalWallet DigitalWallet::operator+(double deposit) const {
    if (deposit < 0.0f) {
        cout << "Amount can't be negative!" << endl;
    }
    DigitalWallet newDW = *this;
    newDW.balance = newDW.balance + deposit;
    return newDW;
}
DigitalWallet DigitalWallet::operator-(double withdrawal) const {
    DigitalWallet newDW = *this;
    newDW.balance = newDW.balance - withdrawal;
    if (newDW.balance < 0.0f) {
        cout << "Overdraft Detected!" << endl;
    }
    return newDW;
}
DigitalWallet DigitalWallet::operator*(double interest) const {
    DigitalWallet newDW = *this;
    newDW.balance = newDW.balance * (1 + interest);
    return newDW;
}

DigitalWallet::operator long() const {
    return (long)balance*100;
}

void DigitalWallet::checkStatus() const {
    cout << "Account: " << userID << "\nBalance: " << balance << endl;
}
