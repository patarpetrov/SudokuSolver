#include <iostream>
#include <stdlib.h>
#include <Windows.h>

bool checkNumberLines(int map[9][9], int number, int posx, int posy);
void printSudoku(int map[9][9]);
bool checkBox(int map[9][9], int number, int posx, int posy);
bool check(int map[9][9], int number, int posx, int posy);
void solveSudoku2(int map[9][9]);


bool check(int map[9][9], int number, int posx, int posy) {
    if (checkNumberLines(map, number, posx, posy) == true && checkBox(map, number, posx, posy) == true)
    {
        return true;
    }
    return false;
}

bool checkNumberLines(int map[9][9], int number, int posx, int posy) {
    bool lamp = true;
    //cout << "x  " << posx << "y   " << posy << endl;
    for (int i = 0; i < 9; i++) {
        if (map[posx][i] == number) {
            return false;
        }
        if (map[i][posy] == number) {
            return false;
        }
    }
    return true;
}

bool checkBox(int map[9][9], int number, int posx, int posy) {
    int boxX = (posx / 3) * 3;
    int boxY = (posy / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            if (map[boxX + i][boxY + k] == number)
            {
                return false;
            }
        }
    }
    return true;
}

void printSudoku(int map[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            std::cout << map[i][k] << " ";
        }
        std::cout << std::endl;
    }
}

void solveSudoku2(int map[9][9]) {
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if(map[y][x] == 0){
                for (int i = 1; i <= 9; i++) {
                    if (check(map, i, y, x) == true) {
                        map[y][x] = i;
                        solveSudoku2(map);
                        map[y][x] = 0;
                    }
                } 
                return;
            }
        }
    }
    printSudoku(map);
    return;
}


int main() {
    int map[9][9] = { {2, 0, 4, 0, 6, 1, 0, 0, 9},
                      {0, 1, 0, 0, 0, 4, 0, 0, 0},
                      {0, 7, 0, 0, 0, 0, 0, 2, 0},
                      {0, 2, 0, 0, 0, 0, 0, 0, 0},
                      {8, 0, 3, 0, 0, 7, 0, 9, 0},
                      {0, 0, 0, 5, 0, 0, 0, 0, 6},
                      {4, 0, 9, 0, 0, 3, 0, 8, 0},
                      {0, 0, 1, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 7, 0, 3, 0, 0} };
    /*int map[9][9] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0} };*/
    solveSudoku2(map);
    


}