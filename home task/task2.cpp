#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototype
string pyramidVolume(double length, double width, double height, string unit);

int main() {
    cout << pyramidVolume(4, 6, 20, "centimeters") << endl;
    cout << pyramidVolume(1843, 1823, 923, "kilometers") << endl;
    cout << pyramidVolume(18, 412, 93, "millimeters") << endl;
    
    // User input
    double l, w, h;
    string u;
    cout << "\nEnter length, width, height (meters): ";
    cin >> l >> w >> h;
    cout << "Enter output unit (millimeters/centimeters/meters/kilometers): ";
    cin >> u;
    cout << pyramidVolume(l, w, h, u) << endl;
    
    return 0;
}

string pyramidVolume(double length, double width, double height, string unit) {
    // Volume in cubic meters
    double volumeMeters = (length * width * height) / 3.0;
    double result;
    string unitName;
    
    if (unit == "millimeters") {
        result = volumeMeters * 1000000000;
        unitName = "cubic millimeters";
    }
    else if (unit == "centimeters") {
        result = volumeMeters * 1000000;
        unitName = "cubic centimeters";
    }
    else if (unit == "meters") {
        result = volumeMeters;
        unitName = "cubic meters";
    }
    else if (unit == "kilometers") {
        result = volumeMeters / 1000000000;
        unitName = "cubic kilometers";
    }
    else {
        return "Invalid unit!";
    }
    
    // Format output
    cout << fixed << setprecision(3);
    return to_string(result) + " " + unitName;
}