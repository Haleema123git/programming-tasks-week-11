#include <iostream>
using namespace std;

const int COLS = 5;

int totalNissanCars(int cars[][COLS]) {
    int total = 0;
    for(int j = 0; j < COLS; j++) {
        total += cars[2][j]; // Nissan is row 2
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
    
    cout << "Total Nissan Cars: " << totalNissanCars(carData) << endl;
    
    return 0;
}