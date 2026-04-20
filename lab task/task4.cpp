#include <iostream>
#include <cmath>
using namespace std;

// Function prototype
double calculateTreeHeight(double distance, double angleDegrees);

int main() {
    double distance, angle;
    
    cout << "Enter the distance from the base of the tree (in feet): ";
    cin >> distance;
    cout << "Enter the angle of elevation (in degrees): ";
    cin >> angle;
    
    double height = calculateTreeHeight(distance, angle);
    
    cout << "The height of the tree is " << height << " feet" << endl;
    return 0;
}

// Function definition
double calculateTreeHeight(double distance, double angleDegrees) {
    const double DEG_TO_RAD = 57.2958;   // Conversion factor (180/π ≈ 57.2958)
    double angleRadians = angleDegrees / DEG_TO_RAD;
    return distance * tan(angleRadians);
}