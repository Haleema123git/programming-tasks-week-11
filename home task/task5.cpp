#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
float calculateSalary(float base, int score, int experience);

int main() {
    float baseSalary;
    int perfScore, expYears;
    
    cout << "Enter base salary: $";
    cin >> baseSalary;
    cout << "Enter performance score (0-100): ";
    cin >> perfScore;
    cout << "Enter years of experience: ";
    cin >> expYears;
    
    float finalSalary = calculateSalary(baseSalary, perfScore, expYears);
    
    cout << fixed << setprecision(2);
    cout << "Final salary: $" << finalSalary << endl;
    
    return 0;
}

float calculateSalary(float base, int score, int experience) {
    float performanceBonus = 0.0;
    
    // Determine performance bonus
    if (score >= 90) {
        performanceBonus = 20.0;
    } else if (score >= 75) {
        performanceBonus = 10.0;
    } else {
        performanceBonus = 5.0;
    }
    
    // Add extra bonus for experience
    if (experience >= 5) {
        performanceBonus += 5.0;
    }
    
    float bonusAmount = base * (performanceBonus / 100);
    float finalSalary = base + bonusAmount;
    
    return finalSalary;
}