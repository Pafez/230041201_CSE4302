#include <iostream>

using namespace std;

enum etype 
{
  laborer, secretary, manager, accountant, executive, researcher
};

int main() {
    char a;
    etype work;
    cout << "Enter employee type (first letter only): ";
    cin >> a;
    string s = "lsmaer";
    int e = 1;
    for (int i = 0; i < 6; i++) {
        if (s[i] == a) {
            work = etype(i);
            e = 0;
            break;
        }
    }

    if (e) {
        cout << "Invalid Input";
        return 0;
    }

    switch (work)
    {
    case laborer:
        cout << "Employee type is laborer.";
        break;
    
    case secretary:
        cout << "Employee type is laborer.";
        break;

    case manager:
        cout << "Employee type is laborer.";
        break;

    case accountant:
        cout << "Employee type is laborer.";
        break;

    case executive:
        cout << "Employee type is laborer.";
        break;

    case researcher:
        cout << "Employee type is laborer.";
        break;
    
    default:
        break;
    }

    return 0;
}
