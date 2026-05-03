#include <iostream>
using namespace std;

const int SIZE = 3;

bool isIdentityMatrix(int matrix[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) return false;
            } else {
                if(matrix[i][j] != 0) return false;
            }
        }
    }
    return true;
}

int main() {
    int matrix[SIZE][SIZE];
    
    cout << "Enter 3x3 Matrix:" << endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nMatrix:" << endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    if(isIdentityMatrix(matrix)) {
        cout << "\nThe matrix is an Identity Matrix" << endl;
    } else {
        cout << "\nThe matrix is NOT an Identity Matrix" << endl;
    }
    
    return 0;
}