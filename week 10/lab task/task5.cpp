#include <iostream>
#include <cmath>
using namespace std;

// Function prototypes
void solveQuadratic(double a, double b, double c);
double calculateDiscriminant(double a, double b, double c);
void handleTwoRealRoots(double a, double b, double d);
void handleOneRealRoot(double a, double b);
void handleComplexRoots(double a, double b, double d);

int main() {
    double a, b, c;
    
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;
    
    if (a == 0) {
        cout << "This is not a quadratic equation (a cannot be zero)!" << endl;
        return 1;
    }
    
    solveQuadratic(a, b, c);
    
    return 0;
}

// Function definitions

void solveQuadratic(double a, double b, double c) {
    double d = calculateDiscriminant(a, b, c);
    
    cout << "\nDiscriminant = " << d << endl;
    
    if (d > 0) {
        handleTwoRealRoots(a, b, d);
    }
    else if (d == 0) {
        handleOneRealRoot(a, b);
    }
    else {
        handleComplexRoots(a, b, d);
    }
}

double calculateDiscriminant(double a, double b, double c) {
    return (b * b) - (4 * a * c);
}

void handleTwoRealRoots(double a, double b, double d) {
    double root1 = (-b + sqrt(d)) / (2 * a);
    double root2 = (-b - sqrt(d)) / (2 * a);
    cout << "Solutions: x = " << root1 << " and x = " << root2 << endl;
}

void handleOneRealRoot(double a, double b) {
    double root = -b / (2 * a);
    cout << "Solution: x = " << root << endl;
}

void handleComplexRoots(double a, double b, double d) {
    double realPart = -b / (2 * a);
    double imagPart = sqrt(-d) / (2 * a);  // sqrt of positive number
    cout << "Complex Solutions: x = " << realPart << " + " << imagPart << "i";
    cout << " and x = " << realPart << " - " << imagPart << "i" << endl;
}