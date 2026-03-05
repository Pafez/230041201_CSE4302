#include <iostream>

using namespace std;

class IGadget
{
private:
    /* data */
public:
    IGadget() {}
    ~IGadget() {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class IConnected
{
private:
    /* data */
public:
    IConnected() {}
    ~IConnected() {}

    virtual void connectToWiFi(string ssid) = 0;
    virtual void disconnectWiFi() = 0;
};

class BasicGadget: public IGadget
{
private:
    string gadgetName;
public:
    BasicGadget(string gadgetName_): gadgetName(gadgetName_) {}
    ~BasicGadget() {}

    void showName() {
        cout << "Gadget name: " << gadgetName << endl;
    }

    void turnOn() {
        cout << "Basic Turn on" << endl;
    }

    void turnOff() {
        cout << "Basic Turn off" << endl;
    }
};

class SmartGadget: public IConnected, public IGadget
{
private:
    string gadgetName;
    int batteryLevel;
public:
    SmartGadget(string gadgetName_, int batteryLevel_ = 50) {
        gadgetName = gadgetName_;
        batteryLevel = batteryLevel_;
    }
    ~SmartGadget() {}

    void turnOn() {
        cout << "Smart Turn on" << endl;
        cout << "Battery level: " << batteryLevel << "%" << endl;
    }
    void turnOff() {
        cout << "Smart Turn off " << batteryLevel << "%" << endl;
    }

    void chargeBattery(int amount) {
        batteryLevel += amount;
        cout << "New Battery level: " << batteryLevel << "%" << endl;
    }

    void reduceBattery(int amount) {
        batteryLevel -= amount;
        cout << "New Battery level: " << batteryLevel << "%" << endl;
    }

    void connectToWiFi(string ssid) {
        cout << "Smart Connected to WiFi, ssid: " << ssid << endl;
    }

    void disconnectWiFi() {
        cout << "Smart Disconnected from WiFi" << endl;
    }

    void showBatteryLevel() const {
        cout << "Battery level of" << gadgetName << ": " << batteryLevel << "%" << endl;
    }
};

class AdvancedRobot: public SmartGadget
{
private:
    string robotID;
public:
    AdvancedRobot(string gadgetName_, string robotID_, int batteryLevel_ = 50): SmartGadget(gadgetName_, batteryLevel_), robotID(robotID_) {}
    ~AdvancedRobot() {}

    void turnOn() {
        SmartGadget::turnOn();
        cout << "Robot " << robotID << " is powered up" << endl;
    }

    void scanEnvironment() {
        cout << "Scanning the environment..." << endl;
    }

    void moveForward(int steps) {
        cout << "Robot " << robotID << " moved " << steps << " steps forward" << endl;
    }

    void performSelfCheck() {
        cout << "Robot " << robotID << " performing self-check..." << endl;
    }
};

void test(IGadget & t) {
    t.turnOn();
    t.turnOff();
}

int main() {
    AdvancedRobot divA("AnonymousM", "01", 79);
    divA.turnOn();
    divA.chargeBattery(20);
    divA.connectToWiFi("h11d3n");
    divA.scanEnvironment();
    divA.moveForward(5);
    divA.performSelfCheck();
    divA.disconnectWiFi();
    divA.turnOff();
    divA.showBatteryLevel();
    divA.reduceBattery(10);

    BasicGadget anywhereDoor("Anywhere Door");
    SmartGadget fourDimensionalPocket("4D Pocket", 100);
    AdvancedRobot iRobot("No,", "Can you?");

    test(anywhereDoor);
    test(fourDimensionalPocket);
    test(iRobot);
}
