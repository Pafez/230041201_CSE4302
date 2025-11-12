#include <iostream>

using namespace std;

int main() 
{
    int energy, total = 0;
    cout << "Enter maximum height: ";
    cin >> energy; energy *= 2;
    for (int i = 0; i < 3; i++)
    {
        total += energy = (energy+1)/2;
        cout << "Height after hour " << i+1 << ": "<< total  << endl;
    }
    
}
