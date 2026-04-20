#include <iostream>
#include <string>
using namespace std;

// Function prototype
string oddishOrEvenish(int number);

int main() {
    int num;
    
    cout << "Enter a five-digit number: ";
    cin >> num;
    
    // validation for 5-digit input
    if (num < 10000 || num > 99999) {
        cout << "Please enter a valid five-digit number!" << endl;
        return 1;
    }
    
    string result = oddishOrEvenish(num);
    cout << result << endl;
    
    return 0;
}

// Function definition
string oddishOrEvenish(int number) {
    int digit1 = number / 10000;           // Ten-thousands 
    int digit2 = (number / 1000) % 10;     // Thousands
    int digit3 = (number / 100) % 10;      // Hundreds
    int digit4 = (number / 10) % 10;       // Tens
    int digit5 = number % 10;              // Units
    
    // Calculate sum of digits
    int sum = digit1 + digit2 + digit3 + digit4 + digit5;
    
    // Check if sum is odd or even
    if (sum % 2 == 1) {
        return "Oddish";
    } else {
        return "Evenish";
    }
}