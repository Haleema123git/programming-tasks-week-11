#include <iostream>
using namespace std;

// Function prototype
double findMin(double a, double b);

int main() {
    double num1, num2;
    
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    double minimum = findMin(num1, num2);
    
    cout << "The minimum of " << num1 << " and " << num2 << " is: " << minimum << endl;
    
    return 0;
}

// Function definition
double findMin(double a, double b) {
    if (a < b)
        return a;
    else
        return b;
}