#include "Corrector.h"
#include <iostream>
using namespace std;
// checking possibility of moves in different directions
int TryUp(int** A, int N) {
    for (int j = 0; j < N; j++) {
        for (int i = 1; i < N; i++) {
            if (A[i][j] == 0) {
                continue;
            }
            if (A[i][j] != 0 && A[i - 1][j] == 0) {
                return 1;
            }
            if (A[i][j] != 0 && A[i - 1][j] != 0) {
                if (A[i][j] == A[i - 1][j]) {
                    return 1;
                }
                else {
                    continue;
                }
            }
        }
    }
    return 0;
}
int TryDown(int** A, int N) {
    for (int j = 0; j < N; j++) {
        for (int i = N - 2; i >= 0; i--) {
            if (A[i][j] == 0) {
                continue;
            }
            if (A[i][j] != 0 && A[i + 1][j] == 0) {
                return 1;
            }
            if (A[i][j] != 0 && A[i + 1][j] != 0) {
                if (A[i][j] == A[i + 1][j]) {
                    return 1;
                }
                else {
                    continue;
                }
            }
        }
    }
    return 0;
}
int TryRight(int** A, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (A[i][j] == 0) {
                continue;
            }
            if (A[i][j] != 0 && A[i][j + 1] == 0) {
                return 1;
            }
            if (A[i][j] != 0 && A[i][j + 1] != 0) {
                if (A[i][j] == A[i][j + 1]) {
                    return 1;
                }
                else {
                    continue;
                }
            }
        }
    }
    return 0;
}
int TryLeft(int** A, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (A[i][j] == 0) {
                continue;
            }
            if (A[i][j] != 0 && A[i][j - 1] == 0) {
                return 1;
            }
            if (A[i][j] != 0 && A[i][j - 1] != 0) {
                if (A[i][j] == A[i][j - 1]) {
                    return 1;
                }
                else {
                    continue;
                }
            }
        }
    }
    return 0;
}
