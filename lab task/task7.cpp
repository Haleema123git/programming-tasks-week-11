#include <iostream>
using namespace std;

// Function prototype
bool isSymmetrical(int number);

int main() {
    int num;
    
    cout << "Enter a three-digit number: ";
    cin >> num;
    
    if (num < 100 || num > 999) {
        cout << "Please enter a valid three-digit number!" << endl;
        return 1;
    }
    
    bool result = isSymmetrical(num);
    
    if (result) {
        cout << "The number is symmetrical." << endl;
    } else {
        cout << "The number is not symmetrical." << endl;
    }
    
    return 0;
}

// Function definition
bool isSymmetrical(int number) {
    int firstDigit = number / 100;
    int lastDigit = number % 10;
    
    return (firstDigit == lastDigit);
}