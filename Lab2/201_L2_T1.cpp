#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    char s;
    cout << "Enter first fraction: ";
    cin >> a >> s >> b;
    cout << "Enter second fraction: ";
    cin >> c >> s >> d;

    cout << "Sum = " << (a*d+b*c) << '/' << (b*d);

    return 0;
} 
