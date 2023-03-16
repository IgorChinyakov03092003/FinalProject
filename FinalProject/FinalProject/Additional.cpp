#include "Additional.h"
#include <iostream>
#include <string>
using namespace std;
int MatrixMax(int** GamePole, int N) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (GamePole[i][j] > max) {
                max = GamePole[i][j];
            }
        }
    }
    return max;
}
int DigNum(int num) {
    if (num == 0) {
        return 1;
    }
    int DigNum = 0;
    while (num > 0) {
        DigNum++;
        num = num / 10;
    }
    return DigNum;
}
void PrintPole(int** GamePole, int N) { // printing pole using "_" to make the similar blocks
    string s;
    int MAX = MatrixMax(GamePole, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (GamePole[i][j] > 0) {
                s = to_string(GamePole[i][j]);
            }
            else {
                s = "_";
            }
            for (int k = 0; k < DigNum(MAX) - DigNum(GamePole[i][j]); k++) {
                s.append("_");
            }
            cout << s;
            cout << ' ';
        }
        cout << endl;
        cout << endl;
    }
}
void Copy(int** newPole, int** oldPole, int N) {    // copying to save last moves
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            oldPole[i][j] = newPole[i][j];
        }
    }
}
int IsVictory(int** A, int N) {     // victory checking
    if (N == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 1024) {
                    return 1;
                }
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 2048) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
