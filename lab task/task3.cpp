#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;

    cout << "Enter a number: ";
    cin >> x;
    cout << "Original number: " << x << endl;
    cout << "Cube root (cbrt): " << cbrt(x) << endl;
    cout << "Ceil (round up): " << ceil(x) << endl;
    cout << "Floor (round down): " << floor(x) << endl;
    // For trigonometric functions
    cout << "cos(" << x << "): " << cos(x) << endl;
    cout << "sin(" << x << "): " << sin(x) << endl;
    cout << "tan(" << x << "): " << tan(x) << endl;

    return 0;
}