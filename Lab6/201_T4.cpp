#include <iostream>

using namespace std;

class TradeSignal
{
private:
    double magnitude;
    long timestamp;
public:
    TradeSignal::TradeSignal()
    {
        magnitude = 1.0f;
        timestamp = 0;
    }

    TradeSignal::TradeSignal(double magT, long timeSt)
    {
        magnitude = magT;
        timestamp = timeSt;
    }

    TradeSignal::~TradeSignal()
    {
    }

    TradeSignal operator+(const TradeSignal & other) const{
        long newTime = (timestamp > other.timestamp) ? timestamp : other.timestamp;
        return TradeSignal(magnitude + other.magnitude, newTime);
    }

    TradeSignal operator*(double scalar) const{
        return TradeSignal(magnitude*scalar, timestamp);
    }

    friend ostream operator<<(ostream out, TradeSignal TS);
    friend TradeSignal operator*(double scalar, TradeSignal TS);
};

TradeSignal operator*(double scalar, TradeSignal TS) {
    return TradeSignal(TS.magnitude*scalar, TS.timestamp);
}

ostream operator<<(ostream out, TradeSignal TS) {
    out << "[" << TS.timestamp << "] Magnitude: " << TS.magnitude << endl;
}
