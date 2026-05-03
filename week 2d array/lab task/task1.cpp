#include <iostream>
using namespace std;

// Global constant for column size
const int COLS = 5;
int printCars(int cars[][COLS], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << cars[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    // Car data: Rows = Companies (Suzuki, Toyota, Nissan, BMW, Audi)
    // Columns = Colors (Red, Black, Brown, Blue, Gray)
    int carData[5][COLS] = {
        {10, 7, 12, 10, 4},   // Suzuki
        {18, 11, 15, 17, 2},  // Toyota
        {23, 19, 12, 16, 14}, // Nissan
        {7, 12, 16, 0, 2},    // BMW
        {3, 5, 6, 2, 1}       // Audi
    };
    
    cout << "Car Data Matrix:" << endl;
    printCars(carData, 5);
    
    return 0;
}