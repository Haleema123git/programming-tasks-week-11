#include <iostream>
using namespace std;

const int COLS = 5;

int totalRedCars(int cars[][COLS], int rows) {
    int total = 0;
    for(int i = 0; i < rows; i++) {
        total += cars[i][0]; // Red is column 0
    }
    return total;
}

int main() {
    int carData[5][COLS] = {
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}
    };
    
    cout << "Total Red Cars: " << totalRedCars(carData, 5) << endl;
    
    return 0;
}