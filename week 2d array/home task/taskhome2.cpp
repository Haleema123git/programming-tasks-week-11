#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Game dimensions
int WIDTH = 40;
int HEIGHT = 20;
int MAX_ENEMIES = 8;
int MAX_BULLETS = 30;

// Game state 2D array
int gameState[20][40];

// Player variables
int playerX, playerY;
int playerHealth;
int playerLives;
int score;
int currentLevel;
int enemiesAlive;

// Enemy structure
struct Enemy {
    int x, y;
    int type;
    int health;
    int shootCooldown;
    int active;
    int moveCounter;
};

// Bullet structure
struct Bullet {
    int x, y;
    int isPlayer;
    int active;
};

// Global arrays
Enemy enemies[8];
Bullet bullets[30];

// Function prototypes
void gotoxy(int x, int y);
void hideCursor();
void initializeGame();
void initializeLevel();
void drawBorder();
void drawGame();
void movePlayer(char key);
void shoot(int isPlayer, int x, int y);
void updateBullets();
void updateEnemies();
void enemyShoot(Enemy &e);
void checkCollisions();
void addScore(int points);
void drawHealthAndScore();
void gameOver();
void levelComplete();
void waitForKeyPress();
void showInstructions();
void setupLevel1();
void setupLevel2();
void setupLevel3();

int main() {
    showInstructions();
    initializeGame();
    
    while(currentLevel <= 3 && playerLives > 0) {
        initializeLevel();
        
        bool levelRunning = true;
        
        while(levelRunning && playerLives > 0 && enemiesAlive > 0) {
            system("cls");
            drawGame();
            
            if(kbhit()) {
                char key = getch();
                if(key == 27) {
                    gameOver();
                    return 0;
                }
                movePlayer(key);
            }
            
            updateBullets();
            updateEnemies();
            checkCollisions();
            
            if(playerLives <= 0) {
                levelRunning = false;
                break;
            }
            
            if(enemiesAlive <= 0) {
                levelRunning = false;
                addScore(500);
            }
            
            Sleep(50);
        }
        
        if(playerLives > 0 && currentLevel < 3) {
            levelComplete();
            currentLevel++;
        } else {
            break;
        }
    }
    
    if(playerLives > 0 && currentLevel == 3) {
        system("cls");
        gotoxy(15, 10);
        cout << "YOU WIN!";
        gotoxy(12, 11);
        cout << "Final Score: " << score;
        gotoxy(10, 12);
        cout << "Congratulations!";
        getch();
    } else {
        gameOver();
    }
    
    return 0;
}

// Function definitions after main
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void initializeGame() {
    playerLives = 3;
    score = 0;
    currentLevel = 1;
    hideCursor();
}

void initializeLevel() {
    // Clear game state
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            gameState[i][j] = 0;
        }
    }
    
    // Clear bullets
    for(int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = 0;
    }
    
    // Set player position
    playerX = WIDTH / 2;
    playerY = HEIGHT - 2;
    playerHealth = 100;
    gameState[playerY][playerX] = 1;
    
    // Setup enemies based on level
    if(currentLevel == 1) {
        setupLevel1();
    } else if(currentLevel == 2) {
        setupLevel2();
    } else {
        setupLevel3();
    }
}

void setupLevel1() {
    enemiesAlive = 5;
    
    for(int i = 0; i < enemiesAlive; i++) {
        enemies[i].active = 1;
        enemies[i].x = 5 + (i * 6);
        enemies[i].y = 3;
        enemies[i].type = 1;
        enemies[i].health = 30;
        enemies[i].shootCooldown = 0;
        enemies[i].moveCounter = 0;
        gameState[enemies[i].y][enemies[i].x] = 2;
    }
}

void setupLevel2() {
    enemiesAlive = 6;
    
    for(int i = 0; i < enemiesAlive; i++) {
        enemies[i].active = 1;
        enemies[i].moveCounter = 0;
        
        if(i < 3) {
            enemies[i].x = 8 + (i * 8);
            enemies[i].y = 3;
            enemies[i].type = 1;
            enemies[i].health = 30;
        } else {
            enemies[i].x = 10 + ((i-3) * 6);
            enemies[i].y = 6;
            enemies[i].type = 2;
            enemies[i].health = 20;
        }
        
        enemies[i].shootCooldown = 0;
        gameState[enemies[i].y][enemies[i].x] = enemies[i].type + 1;
    }
}

void setupLevel3() {
    enemiesAlive = 8;
    
    for(int i = 0; i < enemiesAlive; i++) {
        enemies[i].active = 1;
        enemies[i].moveCounter = 0;
        
        if(i < 3) {
            enemies[i].x = 5 + (i * 10);
            enemies[i].y = 3;
            enemies[i].type = 1;
            enemies[i].health = 30;
        }
        else if(i < 6) {
            enemies[i].x = 8 + ((i-3) * 8);
            enemies[i].y = 6;
            enemies[i].type = 2;
            enemies[i].health = 20;
        }
        else {
            enemies[i].x = 15 + ((i-6) * 8);
            enemies[i].y = 9;
            enemies[i].type = 3;
            enemies[i].health = 50;
        }
        
        enemies[i].shootCooldown = 0;
        gameState[enemies[i].y][enemies[i].x] = enemies[i].type + 1;
    }
}

void drawBorder() {
    for(int i = 0; i <= WIDTH + 1; i++) {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, HEIGHT + 1);
        cout << "#";
    }
    
    for(int i = 0; i <= HEIGHT + 1; i++) {
        gotoxy(0, i);
        cout << "#";
        gotoxy(WIDTH + 1, i);
        cout << "#";
    }
}

void drawGame() {
    drawBorder();
    
    gotoxy(playerX, playerY);
    cout << "A";
    
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].active) {
            gotoxy(enemies[i].x, enemies[i].y);
            if(enemies[i].type == 1) cout << "E";
            else if(enemies[i].type == 2) cout << "F";
            else cout << "T";
        }
    }
    
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i].active) {
            gotoxy(bullets[i].x, bullets[i].y);
            if(bullets[i].isPlayer) cout << "|";
            else cout << ".";
        }
    }
    
    drawHealthAndScore();
}

void movePlayer(char key) {
    gameState[playerY][playerX] = 0;
    
    int newX = playerX;
    int newY = playerY;
    
    if(key == 'a' || key == 'A') newX--;
    if(key == 'd' || key == 'D') newX++;
    if(key == 'w' || key == 'W') newY--;
    if(key == 's' || key == 'S') newY++;
    
    if(newX > 0 && newX < WIDTH + 1 && newY > 0 && newY < HEIGHT + 1) {
        playerX = newX;
        playerY = newY;
    }
    
    gameState[playerY][playerX] = 1;
    
    if(key == ' ') {
        shoot(1, playerX, playerY - 1);
    }
}

void shoot(int isPlayer, int x, int y) {
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i].active == 0) {
            bullets[i].x = x;
            bullets[i].y = y;
            bullets[i].isPlayer = isPlayer;
            bullets[i].active = 1;
            break;
        }
    }
}

void updateBullets() {
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i].active) {
            if(gameState[bullets[i].y][bullets[i].x] == 5) {
                gameState[bullets[i].y][bullets[i].x] = 0;
            }
            
            if(bullets[i].isPlayer) {
                bullets[i].y--;
            } else {
                bullets[i].y++;
            }
            
            if(bullets[i].y <= 0 || bullets[i].y >= HEIGHT + 1) {
                bullets[i].active = 0;
            } else {
                gameState[bullets[i].y][bullets[i].x] = 5;
            }
        }
    }
}

void updateEnemies() {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].active) {
            gameState[enemies[i].y][enemies[i].x] = 0;
            
            enemies[i].moveCounter++;
            
            if(enemies[i].type == 1) {
                if(enemies[i].moveCounter % 20 == 0) {
                    int direction = rand() % 4;
                    if(direction == 0 && enemies[i].x > 1) enemies[i].x--;
                    if(direction == 1 && enemies[i].x < WIDTH) enemies[i].x++;
                    if(direction == 2 && enemies[i].y > 1) enemies[i].y--;
                    if(direction == 3 && enemies[i].y < HEIGHT - 3) enemies[i].y++;
                }
            }
            else if(enemies[i].type == 2) {
                if(enemies[i].moveCounter % 10 == 0) {
                    int direction = rand() % 4;
                    if(direction == 0 && enemies[i].x > 1) enemies[i].x--;
                    if(direction == 1 && enemies[i].x < WIDTH) enemies[i].x++;
                    if(direction == 2 && enemies[i].y > 1) enemies[i].y--;
                    if(direction == 3 && enemies[i].y < HEIGHT - 3) enemies[i].y++;
                }
            }
            else {
                if(enemies[i].moveCounter % 25 == 0) {
                    if(enemies[i].x < playerX && enemies[i].x < WIDTH) enemies[i].x++;
                    else if(enemies[i].x > playerX && enemies[i].x > 1) enemies[i].x--;
                    
                    if(enemies[i].y < playerY && enemies[i].y < HEIGHT - 3) enemies[i].y++;
                    else if(enemies[i].y > playerY && enemies[i].y > 1) enemies[i].y--;
                }
            }
            
            gameState[enemies[i].y][enemies[i].x] = enemies[i].type + 1;
            
            enemies[i].shootCooldown++;
            int shootDelay = 30 - currentLevel * 5;
            if(enemies[i].shootCooldown > shootDelay) {
                enemyShoot(enemies[i]);
                enemies[i].shootCooldown = 0;
            }
        }
    }
}

void enemyShoot(Enemy &e) {
    shoot(0, e.x, e.y + 1);
}

void checkCollisions() {
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i].active && bullets[i].isPlayer) {
            for(int j = 0; j < MAX_ENEMIES; j++) {
                if(enemies[j].active && bullets[i].x == enemies[j].x && bullets[i].y == enemies[j].y) {
                    int damage = 20;
                    enemies[j].health -= damage;
                    bullets[i].active = 0;
                    
                    if(enemies[j].health <= 0) {
                        enemies[j].active = 0;
                        gameState[enemies[j].y][enemies[j].x] = 0;
                        enemiesAlive--;
                        
                        if(enemies[j].type == 1) addScore(100);
                        else if(enemies[j].type == 2) addScore(150);
                        else addScore(200);
                    }
                    break;
                }
            }
        }
        
        if(bullets[i].active && bullets[i].isPlayer == 0) {
            if(bullets[i].x == playerX && bullets[i].y == playerY) {
                playerHealth -= 15;
                bullets[i].active = 0;
                
                if(playerHealth <= 0) {
                    playerLives--;
                    if(playerLives > 0) {
                        playerHealth = 100;
                        playerX = WIDTH / 2;
                        playerY = HEIGHT - 2;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].active && enemies[i].x == playerX && enemies[i].y == playerY) {
            playerHealth -= 30;
            
            if(playerHealth <= 0) {
                playerLives--;
                if(playerLives > 0) {
                    playerHealth = 100;
                    playerX = WIDTH / 2;
                    playerY = HEIGHT - 2;
                }
            }
            
            if(enemies[i].y < HEIGHT - 3) enemies[i].y++;
            else if(enemies[i].y > 2) enemies[i].y--;
        }
    }
}

void addScore(int points) {
    score = score + points;
}

void drawHealthAndScore() {
    gotoxy(2, HEIGHT + 2);
    cout << "Health: " << playerHealth << "%  ";
    cout << "Lives: ";
    for(int i = 0; i < playerLives; i++) cout << char(3) << " ";
    cout << "  Score: " << score << "  ";
    cout << "Level: " << currentLevel << "  ";
    cout << "Enemies: " << enemiesAlive;
}

void gameOver() {
    system("cls");
    gotoxy(15, 10);
    cout << "GAME OVER!";
    gotoxy(13, 11);
    cout << "Final Score: " << score;
    gotoxy(10, 12);
    cout << "Press any key to exit...";
    getch();
}

void levelComplete() {
    system("cls");
    gotoxy(12, 10);
    cout << "LEVEL COMPLETE!";
    gotoxy(13, 11);
    cout << "Score: " << score;
    gotoxy(8, 12);
    cout << "Press any key for next level...";
    getch();
}

void waitForKeyPress() {
    gotoxy(2, HEIGHT + 4);
    cout << "Press any key to continue...";
    getch();
}

void showInstructions() {
    system("cls");
    cout << "\n\n================== SPACE SHOOTER ==================\n\n";
    cout << "Instructions:\n";
    cout << "- Use WASD keys to move your ship (A)\n";
    cout << "- Press SPACE to shoot bullets\n";
    cout << "- Destroy enemies to earn points\n";
    cout << "- Different enemies give different points:\n";
    cout << "  * E (Normal): 100 points\n";
    cout << "  * F (Fast): 150 points\n";
    cout << "  * T (Tank): 200 points\n";
    cout << "- You have 3 lives. Each life has 100% health\n";
    cout << "- Complete all 3 levels to win!\n\n";
    cout << "Press any key to start...";
    getch();
}