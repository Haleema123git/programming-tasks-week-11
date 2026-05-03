#include <iostream>
#include <string>
using namespace std;

const int COLS = 5;
int converter(int cars[][COLS], int rows, string color) {
    int colorIndex = -1;
    
    // Find color index
    if(color == "Red") colorIndex = 0;
    else if(color == "Black") colorIndex = 1;
    else if(color == "Brown") colorIndex = 2;
    else if(color == "Blue") colorIndex = 3;
    else if(color == "Gray") colorIndex = 4;
    
    if(colorIndex == -1) return 0;
    
    int total = 0;
    for(int i = 0; i < rows; i++) {
        total += cars[i][colorIndex];
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
    
    cout << "Total Red Cars: " << converter(carData, 5, "Red") << endl;
    cout << "Total Black Cars: " << converter(carData, 5, "Black") << endl;
    cout << "Total Blue Cars: " << converter(carData, 5, "Blue") << endl;
    
    return 0;
}