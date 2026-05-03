#include <iostream>
using namespace std;

const int COLS = 5;

// A. Print only Toyota Blue cars
void printToyotaBlue(int cars[][COLS]) {
    // Toyota is row 1 (index 1), Blue is column 3 (index 3)
    cout << "Toyota Blue Cars: " << cars[1][3] << endl;
}

int main() {
    int carData[5][COLS] = {
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}
    };
    
    printToyotaBlue(carData);
    
    return 0;
}