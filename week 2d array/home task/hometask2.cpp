#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

// Function prototypes
void gotoxy(int x, int y);
void hideCursor();
void setupGame();
void drawGame();
void handleInput();
void updateGame();
void gameOver();
void levelComplete();
void instructions();

// Game world size
int width = 40;
int height = 20;

// 2D array for game state (Bonus Task)
int gameMap[20][40];

// Player variables
int playerX, playerY;
int playerHealth;
int playerLives;
int score;
int currentLevel;

// Enemy arrays (3 different types)
int enemyX[15], enemyY[15];
int enemyType[15];     // 1=Normal, 2=Fast, 3=Tank
int enemyHealth[15];
int enemyActive[15];
int enemyShootDelay[15];
int enemyMoveCount[15];
int totalEnemies;

// Bullet arrays
int bulletX[50], bulletY[50];
int bulletFromPlayer[50]; // 1=player, 0=enemy
int bulletActive[50];
int totalBullets = 50;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
    cursor.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void setupGame() {
    // Initialize player
    playerX = width / 2;
    playerY = height - 2;
    playerHealth = 100;
    playerLives = 3;
    score = 0;
    
    // Clear game map (2D array)
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            gameMap[i][j] = 0;
        }
    }
    
    // Clear bullets
    for(int i = 0; i < totalBullets; i++) {
        bulletActive[i] = 0;
    }
    
    // Setup enemies based on level
    if(currentLevel == 1) totalEnemies = 5;
    else if(currentLevel == 2) totalEnemies = 7;
    else totalEnemies = 9;
    
    for(int i = 0; i < totalEnemies; i++) {
        enemyActive[i] = 1;
        enemyX[i] = 5 + (i * 4);
        enemyY[i] = 3 + (i / 5);
        enemyShootDelay[i] = rand() % 30;
        enemyMoveCount[i] = 0;
        
        // Assign enemy types (3 different types)
        if(currentLevel == 1) {
            // Level 1: Mostly normal enemies
            enemyType[i] = 1;
            enemyHealth[i] = 30;
        }
        else if(currentLevel == 2) {
            // Level 2: Mix of normal and fast
            if(i < 4) {
                enemyType[i] = 1;
                enemyHealth[i] = 30;
            } else {
                enemyType[i] = 2;
                enemyHealth[i] = 20;
            }
        }
        else {
            // Level 3: All three types
            if(i < 3) {
                enemyType[i] = 1;  // Normal
                enemyHealth[i] = 30;
            }
            else if(i < 6) {
                enemyType[i] = 2;  // Fast
                enemyHealth[i] = 20;
            }
            else {
                enemyType[i] = 3;  // Tank
                enemyHealth[i] = 50;
            }
        }
        
        gameMap[enemyY[i]][enemyX[i]] = enemyType[i] + 1;
    }
    
    gameMap[playerY][playerX] = 1;
}

void drawGame() {
    system("cls");
    
    // Draw border
    for(int i = 0; i <= width; i++) {
        gotoxy(i, 0); cout << "#";
        gotoxy(i, height); cout << "#";
    }
    for(int i = 0; i <= height; i++) {
        gotoxy(0, i); cout << "#";
        gotoxy(width, i); cout << "#";
    }
    
    // Draw player
    gotoxy(playerX, playerY);
    cout << "A";
    
    // Draw enemies (3 different symbols for 3 types)
    for(int i = 0; i < totalEnemies; i++) {
        if(enemyActive[i]) {
            gotoxy(enemyX[i], enemyY[i]);
            if(enemyType[i] == 1) cout << "E";
            else if(enemyType[i] == 2) cout << "F";
            else cout << "T";
        }
    }
    
    // Draw bullets
    for(int i = 0; i < totalBullets; i++) {
        if(bulletActive[i]) {
            gotoxy(bulletX[i], bulletY[i]);
            if(bulletFromPlayer[i]) cout << "|";
            else cout << ".";
        }
    }
    
    // Draw UI (Health bar, Lives, Score)
    gotoxy(2, height + 1);
    cout << "Health: ";
    int healthBars = playerHealth / 10;
    for(int i = 0; i < healthBars; i++) cout << "#";
    for(int i = healthBars; i < 10; i++) cout << " ";
    cout << " " << playerHealth << "%";
    
    gotoxy(2, height + 2);
    cout << "Lives: ";
    for(int i = 0; i < playerLives; i++) cout << char(3) << " ";
    
    gotoxy(2, height + 3);
    cout << "Score: " << score;
    
    gotoxy(30, height + 1);
    cout << "Level: " << currentLevel;
    
    gotoxy(30, height + 2);
    cout << "Enemies: " << totalEnemies;
}

void handleInput() {
    if(kbhit()) {
        char key = getch();
        
        // Player movement
        if(key == 'a' && playerX > 1) playerX--;
        if(key == 'd' && playerX < width-1) playerX++;
        if(key == 'w' && playerY > 1) playerY--;
        if(key == 's' && playerY < height-2) playerY++;
        
        // Player firing
        if(key == ' ') {
            for(int i = 0; i < totalBullets; i++) {
                if(!bulletActive[i]) {
                    bulletActive[i] = 1;
                    bulletX[i] = playerX;
                    bulletY[i] = playerY - 1;
                    bulletFromPlayer[i] = 1;
                    break;
                }
            }
        }
        
        // Exit game
        if(key == 27) {
            gameOver();
            exit(0);
        }
    }
}

void updateGame() {
    // Update bullets
    for(int i = 0; i < totalBullets; i++) {
        if(bulletActive[i]) {
            if(bulletFromPlayer[i]) bulletY[i]--;
            else bulletY[i]++;
            
            if(bulletY[i] <= 0 || bulletY[i] >= height) {
                bulletActive[i] = 0;
            }
        }
    }
    
    // Enemy shooting
    for(int i = 0; i < totalEnemies; i++) {
        if(enemyActive[i]) {
            enemyShootDelay[i]++;
            if(enemyShootDelay[i] > 25) {
                for(int j = 0; j < totalBullets; j++) {
                    if(!bulletActive[j]) {
                        bulletActive[j] = 1;
                        bulletX[j] = enemyX[i];
                        bulletY[j] = enemyY[i] + 1;
                        bulletFromPlayer[j] = 0;
                        break;
                    }
                }
                enemyShootDelay[i] = 0;
            }
        }
    }
    
    // Enemy movement (varies by type)
    for(int i = 0; i < totalEnemies; i++) {
        if(enemyActive[i]) {
            enemyMoveCount[i]++;
            
            if(enemyType[i] == 1) { // Normal - slow random movement
                if(enemyMoveCount[i] % 20 == 0) {
                    int dir = rand() % 4;
                    if(dir == 0 && enemyX[i] > 1) enemyX[i]--;
                    if(dir == 1 && enemyX[i] < width-1) enemyX[i]++;
                    if(dir == 2 && enemyY[i] > 2) enemyY[i]--;
                    if(dir == 3 && enemyY[i] < height-4) enemyY[i]++;
                }
            }
            else if(enemyType[i] == 2) { // Fast - quick random movement
                if(enemyMoveCount[i] % 8 == 0) {
                    int dir = rand() % 4;
                    if(dir == 0 && enemyX[i] > 1) enemyX[i]--;
                    if(dir == 1 && enemyX[i] < width-1) enemyX[i]++;
                    if(dir == 2 && enemyY[i] > 2) enemyY[i]--;
                    if(dir == 3 && enemyY[i] < height-4) enemyY[i]++;
                }
            }
            else { // Tank - moves toward player
                if(enemyMoveCount[i] % 25 == 0) {
                    if(enemyX[i] < playerX) enemyX[i]++;
                    if(enemyX[i] > playerX) enemyX[i]--;
                    if(enemyY[i] < playerY) enemyY[i]++;
                    if(enemyY[i] > playerY) enemyY[i]--;
                }
            }
        }
    }
    
    // Collision: Player bullets hit enemies
    for(int i = 0; i < totalBullets; i++) {
        if(bulletActive[i] && bulletFromPlayer[i]) {
            for(int j = 0; j < totalEnemies; j++) {
                if(enemyActive[j] && bulletX[i] == enemyX[j] && bulletY[i] == enemyY[j]) {
                    enemyHealth[j] -= 20;
                    bulletActive[i] = 0;
                    
                    if(enemyHealth[j] <= 0) {
                        enemyActive[j] = 0;
                        totalEnemies--;
                        
                        // Scoring (different points for different enemies)
                        if(enemyType[j] == 1) score += 100;
                        else if(enemyType[j] == 2) score += 150;
                        else score += 200;
                    }
                    break;
                }
            }
        }
    }
    
    // Collision: Enemy bullets hit player
    for(int i = 0; i < totalBullets; i++) {
        if(bulletActive[i] && !bulletFromPlayer[i]) {
            if(bulletX[i] == playerX && bulletY[i] == playerY) {
                playerHealth -= 15;
                bulletActive[i] = 0;
                
                if(playerHealth <= 0) {
                    playerLives--;
                    if(playerLives > 0) {
                        playerHealth = 100;
                        playerX = width / 2;
                        playerY = height - 2;
                    }
                }
            }
        }
    }
    
    // Collision: Enemy touches player
    for(int i = 0; i < totalEnemies; i++) {
        if(enemyActive[i] && enemyX[i] == playerX && enemyY[i] == playerY) {
            playerHealth -= 25;
            
            if(playerHealth <= 0) {
                playerLives--;
                if(playerLives > 0) {
                    playerHealth = 100;
                    playerX = width / 2;
                    playerY = height - 2;
                }
            }
            
            // Push enemy away
            if(enemyY[i] < height-3) enemyY[i]++;
            else if(enemyY[i] > 2) enemyY[i]--;
        }
    }
}

void instructions() {
    system("cls");
    cout << "\n\n";
    cout << "====================================\n";
    cout << "         SPACE SHOOTER GAME\n";
    cout << "====================================\n\n";
    cout << "CONTROLS:\n";
    cout << "  W A S D - Move your ship\n";
    cout << "  SPACE   - Shoot bullets\n";
    cout << "  ESC     - Exit game\n\n";
    cout << "ENEMY TYPES (3 different):\n";
    cout << "  E - Normal enemy (100 points)\n";
    cout << "  F - Fast enemy (150 points)\n";
    cout << "  T - Tank enemy (200 points)\n\n";
    cout << "FEATURES:\n";
    cout << "  - Player has 3 lives with health bar\n";
    cout << "  - Both player and enemies can shoot\n";
    cout << "  - Score points by defeating enemies\n";
    cout << "  - 3 levels with different enemy setups\n";
    cout << "  - Game state stored in 2D array\n\n";
    cout << "Press any key to start...";
    getch();
}

void levelComplete() {
    system("cls");
    gotoxy(12, 10);
    cout << "LEVEL COMPLETE!";
    gotoxy(10, 11);
    cout << "Score: " << score;
    gotoxy(12, 12);
    cout << "Bonus: +500";
    score += 500;
    gotoxy(10, 13);
    cout << "Press any key for next level...";
    getch();
}

void gameOver() {
    system("cls");
    gotoxy(15, 10);
    cout << "GAME OVER!";
    gotoxy(12, 11);
    cout << "Final Score: " << score;
    gotoxy(10, 12);
    cout << "Press any key to exit...";
    getch();
}

int main() {
    srand(time(0));
    hideCursor();
    instructions();
    
    currentLevel = 1;
    
    while(currentLevel <= 3 && playerLives > 0) {
        setupGame();
        
        while(playerLives > 0 && totalEnemies > 0) {
            drawGame();
            handleInput();
            updateGame();
            Sleep(60);
        }
        
        if(playerLives > 0 && currentLevel < 3) {
            levelComplete();
            currentLevel++;
        } else {
            break;
        }
    }
    
    // Game win
    if(playerLives > 0 && currentLevel == 3) {
        system("cls");
        gotoxy(15, 10);
        cout << "YOU WIN!";
        gotoxy(12, 11);
        cout << "Final Score: " << score;
        gotoxy(10, 12);
        cout << "Congratulations!";
        getch();
    } else if(playerLives <= 0) {
        gameOver();
    }
    
    return 0;
}