#include <iostream>
using namespace std;

const int COLS = 5;

void printTranspose(int cars[][COLS], int rows) {
    cout << "Transpose Matrix:" << endl;
    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < rows; j++) {
            cout << cars[j][i] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int carData[5][COLS] = {
        {10, 7, 12, 10, 4},
        {18, 11, 15, 17, 2},
        {23, 19, 12, 16, 14},
        {7, 12, 16, 0, 2},
        {3, 5, 6, 2, 1}
    };
    
    cout << "Original Matrix:" << endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << carData[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    printTranspose(carData, 5);
    
    return 0;
}