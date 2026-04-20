#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
float calculateBalance(float balance, int years);

int main() {
    float balance;
    int years;
    
    cout << "Enter current balance: $";
    cin >> balance;
    cout << "Enter number of years: ";
    cin >> years;
    
    float newBalance = calculateBalance(balance, years);
    
    cout << fixed << setprecision(2);
    cout << "Balance after " << years << " years: $" << newBalance << endl;
    
    return 0;
}

float calculateBalance(float balance, int years) {
    float interestRate = 0.0;
    
    // Determine base interest rate
    if (balance < 10000) {
        interestRate = 5.0;
    } else if (balance <= 50000) {
        interestRate = 7.0;
    } else {
        interestRate = 10.0;
    }
    
    // Add extra interest for long-term (3+ years)
    if (years >= 3) {
        interestRate += 2.0;
    }
    
    float interestAmount = balance * (interestRate / 100);
    float newBalance = balance + interestAmount;
    
    return newBalance;
}