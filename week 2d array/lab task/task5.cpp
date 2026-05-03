#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

string battleShip(char board[][SIZE], string coordinates) {
    
    int row = coordinates[0] - 'A';
    int col = coordinates[1] - '1';
    
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        if(board[row][col] == '*') {
            return "BOOM";
        } else {
            return "splash";
        }
    }
    return "Invalid coordinates";
}

int main() {
    // Hardcoded Battleship configuration
    char battleBoard[SIZE][SIZE] = {
        {'.', '.', '.', '.', '*'},
        {'.', '*', '.', '.', '.'},
        {'.', '.', '.', '*', '.'},
        {'*', '.', '.', '.', '.'},
        {'.', '.', '*', '.', '.'}
    };
    
    cout << "Battleship Game!" << endl;
    cout << "Board size: 5x5 (Rows A-E, Cols 1-5)" << endl;
    cout << "Ships are marked as *" << endl << endl;
    
    // Display board
    cout << "  ";
    for(int i = 1; i <= SIZE; i++) cout << i << " ";
    cout << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << char('A' + i) << " ";
        for(int j = 0; j < SIZE; j++) {
            cout << battleBoard[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTest Cases:" << endl;
    cout << "Coordinate A5: " << battleShip(battleBoard, "A5") << endl;
    cout << "Coordinate B2: " << battleShip(battleBoard, "B2") << endl;
    cout << "Coordinate C4: " << battleShip(battleBoard, "C4") << endl;
    cout << "Coordinate D1: " << battleShip(battleBoard, "D1") << endl;
    cout << "Coordinate E3: " << battleShip(battleBoard, "E3") << endl;
    
    return 0;
}