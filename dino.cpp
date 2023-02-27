#include <iostream>
#include <chrono>
#include <windows.h>
#include <conio.h>
using namespace std;
bool gameOver = false;
const int width = 100;
const int height = 10;
int hurdle[width];
bool pos = false; // can be true or false (jump or normal)ww
int x = 90;
int y = height - 1;
int score = 0;

void draw() {
    system("cls");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (hurdle[j] == 1 && i >= height - 1) {
                cout << "||";
            } else if (j == x && i == y) {
                cout << "^";
            }            
             else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void input() {
    
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            pos = true;
            
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            pos = false;
            break;
        }
    }
}

void logic() {
    int hurdleCounter = 0;
    int hurdleRate = 10; 
    int frameCounter = 0;
    while (!gameOver) {
        input();
        score++;
        if (frameCounter==hurdleRate&&hurdleCounter<35) {
            int randomIndex = rand() % 15 ;
            hurdle[randomIndex+5] = 1;
            hurdleCounter++;
            frameCounter=0;
        }
         else {
            frameCounter++;
            
        }

        for (int i = width - 1; i > 0; i--) {
            hurdle[i] = hurdle[i - 1];
           
        }
        hurdle[0] = 0;

        if (pos) {
            y -= 2;
            pos = false;
        } else {
            if (y < height - 1) {
                y++;
            }
        }

        if (hurdle[x] == 1 && y == height - 1) {
            gameOver = true;
            
        }
        

        draw();
        Sleep(100);
    }
}

int main() {
    while (!gameOver) {
        logic();
    }
    if(gameOver){
        cout<<"G A M E - O V E R";
    }
    return 0;
}