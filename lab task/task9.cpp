#include <iostream>
#include <string>
using namespace std;

// Function prototype
string timeTravel(int hours, int minutes);

int main() {
    // Test cases from lab manual
    cout << "Test 1: 12:49 → " << timeTravel(12, 49) << endl;
    cout << "Test 2: 0:01  → " << timeTravel(0, 1) << endl;
    cout << "Test 3: 23:59 → " << timeTravel(23, 59) << endl;
    cout << "Test 4: 11:08 → " << timeTravel(11, 8) << endl;
    
    // User input version
    int hours, minutes;
    cout << "Enter Hours: ";
    cin >> hours;
    cout << "Enter Minutes: ";
    cin >> minutes;
    
    cout << timeTravel(hours, minutes) << endl;
    
    return 0;
}

string timeTravel(int hours, int minutes) {
    minutes = minutes + 15;
    
    if (minutes >= 60) {
        minutes = minutes - 60;
        hours = hours + 1;
    }
    
    if (hours >= 24) {
        hours = hours - 24;
    }
    
    return to_string(hours) + ":" + to_string(minutes);
}