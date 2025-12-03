#include <iostream>

using namespace std;

class SmartElevator
{
private:
    int currentFloor;
    double currentWeight;
    const int maxFloorNumber;
    const double maxWeight;
public:
    SmartElevator(int maxFloorNumber);
    ~SmartElevator();

    int boardPassenger(double passengerWeight);
    int goToFloor(int targetFloor);
    void displayPanel() const;
};

SmartElevator::SmartElevator(int maxFloor):maxWeight(4302.0f), maxFloorNumber(maxFloor)
{
    currentFloor = 0;
    currentWeight = 0.0f;
}

SmartElevator::~SmartElevator()
{
    cout << "Elevator system entering maintenance mode." << endl;
}

int SmartElevator::boardPassenger(double passengerWeight) {
    double newWeight = currentWeight + passengerWeight;
    if (newWeight > maxWeight) {
        cout << "Overload! Someone must exit." << endl;
        return 1;
    }
    currentWeight = newWeight;
    return 0;
}

int SmartElevator::goToFloor(int targetFloor) {
    if (targetFloor < 0 || targetFloor > maxFloorNumber) {
        cout << "Error 404: Floor not found. Try reality instead." << endl;
        return 1;
    }
    if (targetFloor == currentFloor) {
        cout << "Staying put engaged. Enjoy the view!" << endl;
        return 2;
    }
    currentFloor = targetFloor;
    return 0;
}

void SmartElevator::displayPanel() const {
    cout << "Current Floor: " << currentFloor << endl;
    cout << "Current Load: " << currentWeight << "kg" << endl;
}
