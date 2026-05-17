#include <iostream>
using namespace std;

// Global variable (accessible everywhere)
int globalVar = 100;

// Function prototype
void demonstrateLocalVariable();
void demonstrateGlobalVariable();

int main() {
    cout << "Local vs Global Variables Demo" << endl;
    
    demonstrateLocalVariable();
    demonstrateGlobalVariable();
    
    cout << "In main() - Global variable value: " << globalVar << endl;
    
    return 0;
}

void demonstrateLocalVariable() {
    // Local variable
    int localVar = 50;
    
    cout << "Inside demonstrateLocalVariable():" << endl;
    cout << "Local variable value: " << localVar << endl;
    cout << "Global variable value: " << globalVar << endl;
}

void demonstrateGlobalVariable() {
    cout << "Inside demonstrateGlobalVariable():" << endl;
    cout << "Global variable value: " << globalVar << endl;
    
    globalVar = 200;
    cout << "Global variable modified to: " << globalVar << endl;
}