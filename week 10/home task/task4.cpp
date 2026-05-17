#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function prototype
string projectTimeCalculation(int neededHours, int days, int workers);

int main() {
    int neededHours, days, workers;
    
    cout << "Enter needed hours: ";
    cin >> neededHours;
    cout << "Enter days firm has: ";
    cin >> days;
    cout << "Enter number of workers: ";
    cin >> workers;
    
    string result = projectTimeCalculation(neededHours, days, workers);
    cout << result << endl;
    
    return 0;
}

string projectTimeCalculation(int neededHours, int days, int workers) {
    // Training takes 10% of days
    double trainingDays = days * 0.10;
    double workingDays = days - trainingDays;
    
    // Each worker works
    double totalWorkingHours = workingDays * workers * 10;
    
    // Round down to nearest integer
    totalWorkingHours = floor(totalWorkingHours);
    
    if (totalWorkingHours >= neededHours) {
        double hoursLeft = totalWorkingHours - neededHours;
        return "Yes! " + to_string((int)hoursLeft) + " hours left.";
    } else {
        double hoursNeeded = neededHours - totalWorkingHours;
        return "Not enough time! " + to_string((int)hoursNeeded) + " hours needed.";
    }
}