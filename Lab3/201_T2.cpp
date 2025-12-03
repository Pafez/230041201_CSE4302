#include <iostream>

using namespace std;

class RatioQuota
{
private:
    int p;
    int q;
public:
    RatioQuota();
    ~RatioQuota();
    void setRatio(int a, int b);
    double asDecimal();
    void reciprocal();
    void show();
};

RatioQuota::RatioQuota()
{
    p = 0;
    q = 1;
}

RatioQuota::~RatioQuota() {}

void RatioQuota::setRatio(int a, int b) {
    if (q == 0) {
        cout << "Denominator cannot be zero" << endl;
        return;
    }
    p = a;
    q = b;
}

double RatioQuota::asDecimal() {
    return (double)p/q;
}

void RatioQuota::reciprocal() {
    if (p == 0) {
        cout << "Reciprocal failed: zero cannot be a denominator" << endl;
        return;
    }
    int temp = p;
    p = q;
    q = temp;
}

void RatioQuota::show() {
    cout << "Ratio: " << p << "/" << q;
}
