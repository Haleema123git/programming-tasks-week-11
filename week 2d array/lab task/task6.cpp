#include <iostream>
using namespace std;

const int COLS = 3;

int countIdenticalArrays(int arr[][COLS], int rows) {
    int count = 0;
    
    for(int i = 0; i < rows; i++) {
        bool duplicateFound = false;
        
        for(int j = i + 1; j < rows; j++) {
            bool identical = true;
            
            for(int k = 0; k < COLS; k++) {
                if(arr[i][k] != arr[j][k]) {
                    identical = false;
                    break;
                }
            }
            
            if(identical) {
                duplicateFound = true;
                break;
            }
        }
        
        if(duplicateFound) {
            count++;
        }
    }
    
    return count;
}

int main() {
    // Test Case 1
    int arr1[4][COLS] = {
        {0, 0, 0},
        {0, 1, 2},
        {0, 0, 0},
        {2, 1, 0}
    };
    
    cout << "Test Case 1: " << countIdenticalArrays(arr1, 4) << endl;
    
    // Test Case 2
    int arr2[4][COLS] = {
        {0, 1, 0},
        {0, 1, 2},
        {0, 2, 0},
        {2, 1, 0}
    };
    
    cout << "Test Case 2: " << countIdenticalArrays(arr2, 4) << endl;
    
    // Test Case 3
    int arr3[4][COLS] = {
        {0, 1, 2},
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 0}
    };
    
    cout << "Test Case 3: " << countIdenticalArrays(arr3, 4) << endl;
    
    return 0;
}