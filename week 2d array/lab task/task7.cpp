#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

char world[ROWS][COLS];
bool gravityEnabled = true;
bool isBlackHole = false;

void initializeWorld() {
    // Initialize empty world
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            world[i][j] = ' ';
        }
    }
    
    // Add some blocks for demonstration
    world[0][2] = '#';
    world[1][2] = '#';
    world[2][4] = '#';
    world[3][1] = '#';
    world[4][3] = '#';
}

void displayWorld() {
    cout << "World (5x5):" << endl;
    cout << "  ";
    for(int j = 0; j < COLS; j++) cout << j << " ";
    cout << endl;
    
    for(int i = 0; i < ROWS; i++) {
        cout << i << " ";
        for(int j = 0; j < COLS; j++) {
            cout << world[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void setGravityStatus(bool status) {
    gravityEnabled = status;
    cout << "Gravity " << (gravityEnabled ? "ENABLED" : "DISABLED") << endl;
}

void setBlackHoleStatus(bool status) {
    isBlackHole = status;
    cout << "Black Hole " << (isBlackHole ? "ACTIVE" : "INACTIVE") << endl;
}

void timeTick(int times) {
    for(int tick = 0; tick < times; tick++) {
        if(gravityEnabled) {
            // Process each column from bottom to top
            for(int col = 0; col < COLS; col++) {
                for(int row = ROWS - 2; row >= 0; row--) {
                    if(world[row][col] == '#') {
                        int fallRow = row;
                        
                        // Find how far it can fall
                        while(fallRow + 1 < ROWS && world[fallRow + 1][col] == ' ') {
                            fallRow++;
                        }
                        
                        if(fallRow != row) {
                            // Move block down
                            world[fallRow][col] = '#';
                            world[row][col] = ' ';
                        }
                    }
                }
            }
            
            // Handle black hole effect (last row)
            if(isBlackHole) {
                for(int col = 0; col < COLS; col++) {
                    if(world[ROWS - 1][col] == '#') {
                        // Teleport to first row
                        world[ROWS - 1][col] = ' ';
                        world[0][col] = '#';
                    }
                }
            }
        }
        
        cout << "After tick " << (tick + 1) << ":" << endl;
        displayWorld();
    }
}

int main() {
    initializeWorld();
    
    cout << "Initial World:" << endl;
    displayWorld();
    
    cout << "Setting Gravity ON..." << endl;
    setGravityStatus(true);
    
    cout << "\nApplying 1 tick:" << endl;
    timeTick(1);
    
    cout << "Applying 2 more ticks:" << endl;
    timeTick(2);
    
    cout << "\nNow enabling Black Hole mode..." << endl;
    setBlackHoleStatus(true);
    
    cout << "\nApplying ticks with Black Hole:" << endl;
    timeTick(3);
    
    return 0;
}