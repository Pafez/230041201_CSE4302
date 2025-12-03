#include <iostream>

using namespace std;

class BatchMeter
{
private:
    int total;
    int pulseSize;
public:
    BatchMeter();
    ~BatchMeter();
    void setPulseSize(int s);
    int getTotal();
    void addPulse();
    void getClear();
};

BatchMeter::BatchMeter() {
    total = 0;
    pulseSize = 1;
}

BatchMeter::~BatchMeter() {
    return;
}

void BatchMeter::setPulseSize(int s) {
    if (s <= 0) {
        cout << endl << "Invalid pulse; must be > 0" << endl;
        return;
    }
    pulseSize = s;
}

int BatchMeter::getTotal() {
    return total;
}

void BatchMeter::addPulse() {
    total += pulseSize;
}

void BatchMeter::getClear() {
    total = 0;
}

int main() {
    BatchMeter test;
    cout << test.getTotal();
    test.setPulseSize(5);
    test.addPulse();
    cout << test.getTotal();
}
