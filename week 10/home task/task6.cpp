#include <iostream>
using namespace std;

// Function prototype
bool isStrong(int num);
int factorial(int n);

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (isStrong(number)) {
        cout << number << " is a Strong Number!" << endl;
    } else {
        cout << number << " is NOT a Strong Number!" << endl;
    }
    
    return 0;
}

// Calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Check if number is Strong
bool isStrong(int num) {
    int originalNum = num;
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    
    return (sum == originalNum);
}