#include <iostream>

using namespace std;

struct fraction
{
    int numerator;
    int denominator;
};


int main() {
    fraction a, b;
    char s;
    cout << "Enter first fraction: ";
    cin >> a.numerator >> s >> a.denominator;
    cout << "Enter second fraction: ";
    cin >> b.numerator >> s >> b.denominator;



    cout << "Sum = " << (a.numerator*b.denominator+a.denominator*b.numerator) << '/' << (a.denominator*b.denominator);

    return 0;
}
