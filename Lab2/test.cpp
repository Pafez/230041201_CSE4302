#include <iostream>

using namespace std;

inline int add(int a, int b) {
    return a+b;
}

void rep(char ch='*', int t) {
    for (int i = 0; i < t; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ch;
        }
        cout << endl;
    }
}

void sum(int a, int b, int & res) {
    res = a+b;
}

void sum(int a, int b, int * res) {
    *res = a+b;
}

int main() {
    int res;
    sum(1, 2, res);
    cout << res;

    return 0;
}
