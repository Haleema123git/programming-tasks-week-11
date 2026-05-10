#include <iostream>
using namespace std;

// Function declaration
void swapValues(int *a, int *b);

int main() {
    int x = 10, y = 20;

    cout << "Before swapping:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    // Function call
    swapValues(&x, &y);

    cout << "After swapping:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

// Function definition
void swapValues(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}