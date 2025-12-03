#include <iostream>

using namespace std;

class BatteryMonitor
{
private:
    double currentBattery;
    double criticalThreshold;
public:
    BatteryMonitor();
    void setCriticalThreshold(double percent);
    void drain(double amount);
    void recharge(double amount);
    bool needsCharging();
    void status();
    ~BatteryMonitor();
};

BatteryMonitor::BatteryMonitor()
{
    criticalThreshold = 15.0;
    currentBattery = 100.0;
}

void BatteryMonitor::setCriticalThreshold(double percent) {
    if (percent < 5.0 || percent > 25.0) {
        cout << "Invalid threshold; must be 5-25%" << endl;
        return;
    }
    criticalThreshold = percent;
}

void BatteryMonitor::drain(double amount) {
    if (amount < 0.0) {
        cout << "Invalid recharge amount" << endl;
        return;
    }
    currentBattery -= amount;
    if (currentBattery < 0.0) {
        cout << "Battery depleted" << endl;
        currentBattery = 0.0;
    }
}
void BatteryMonitor::recharge(double amount) {
    if (amount < 0.0) {
        cout << "Invalid recharge amount" << endl;
        return;
    }
    currentBattery += amount;
    if (currentBattery > 100.0) {
        cout << "Battery fully recharged" << endl;
        currentBattery = 100.0;
    }
}
bool BatteryMonitor::needsCharging() {
    if (currentBattery <= criticalThreshold) {
        return true;
    }
    return false;
}
void BatteryMonitor::status() {
    cout << "Battery: " << currentBattery << "% " << (!needsCharging() ? "OK" : "CRITICAL");
}

BatteryMonitor::~BatteryMonitor()
{

}

